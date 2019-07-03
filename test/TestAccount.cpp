#include <domain/model/local-account/LocalAccount.h>
#include <gtest/gtest.h>
#include <app/service/AccountApi.h>
#include <domain/model/local-account/LocalAccountRepo.h>
#include <vector>
#include <string>

namespace
{
	struct FakeAccountRepo : LocalAccountRepo
	{
		OVERRIDE(void add(LocalAccount* account))
		{
			accounts.push_back(account);
		}

		OVERRIDE(LocalAccount* get(const std::string& accountId))
		{
			for (auto a : accounts)
			{
				if (a->getId() == accountId)
				{
					return a;
				}
			}
			return nullptr;
		}

		//simulate dbs operation
		OVERRIDE(void update(LocalAccount* account))
		{
			for (auto a : accounts)
			{
				if (a == account)
				{
					remove(account->getId());
					add(account);

				}
			}

		}

		OVERRIDE(LocalAccount* remove(const std::string& accountId))
		{
			int i = 0;
			for (auto a : accounts)
			{
				if (a->getId() == accountId)
				{
					accounts.erase(accounts.begin() + i);
					return a;
				}
				i++;
			}
			return nullptr;
		}

	private:
		std::vector<LocalAccount*> accounts;
	};
}

struct TestAccount : testing::Test
{

protected:
	virtual void SetUp()
	{
		accountRepo = new FakeAccountRepo();
		setLocalAccountRepo(accountRepo);
		api = new AccountApi();
		jimPhoneNumber = "19999999999";
		jimAccountId = api->createAccount(jimPhoneNumber, JIM_INIT_AMOUNT);
		lucyPhoneNumber = "18888888888";
		lucyAccountId = api->createAccount(lucyPhoneNumber, LUCY_INIT_AMOUNT);
	}

	virtual void TearDown()
	{
		api->destroyAccount(jimAccountId);
		api->destroyAccount(lucyAccountId);
		delete api;
		delete accountRepo;
	}

protected:
	std::string jimPhoneNumber;
	std::string lucyPhoneNumber;
	AccountApi* api;
	std::string jimAccountId;
	std::string lucyAccountId;
	FakeAccountRepo* accountRepo;
	const U32 JIM_INIT_AMOUNT{10000};
	const U32 LUCY_INIT_AMOUNT{5000};
};

TEST_F(TestAccount, withdraw_money)
{
	const U32 AMOUNT = 1500;
	api->withdrawMoney(jimAccountId, AMOUNT);
	ASSERT_EQ(JIM_INIT_AMOUNT - AMOUNT, api->getAmount(jimAccountId));
}

TEST_F(TestAccount, transfer_money_to_local)
{
	const U32 AMOUNT = 1500;
	api->transferMoneyToLocal(jimAccountId, lucyAccountId, AMOUNT);
	ASSERT_EQ(JIM_INIT_AMOUNT - AMOUNT, api->getAmount(jimAccountId));
	ASSERT_EQ(LUCY_INIT_AMOUNT + AMOUNT, api->getAmount(lucyAccountId));
}

TEST_F(TestAccount, transfer_money_to_remote)
{
	const U32 AMOUNT = 1500;
	api->transferMoneyToRemote(jimAccountId, lucyAccountId, AMOUNT);
	ASSERT_EQ(JIM_INIT_AMOUNT - AMOUNT, api->getAmount(jimAccountId));
}

TEST_F(TestAccount, transfer_money_from_remote)
{
	const U32 AMOUNT = 1500;
	api->transferMoneyFromRemote(lucyAccountId, jimAccountId, AMOUNT);
	ASSERT_EQ(JIM_INIT_AMOUNT + AMOUNT, api->getAmount(jimAccountId));
}

