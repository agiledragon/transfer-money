#include "gtest/gtest.h"
#include "app/service/AccountApi.h"
#include "domain/model/account/Account.h"
#include "domain/model/account/AccountRepo.h"
#include <vector>
#include <string>

namespace
{
	struct FakeAccountRepo : AccountRepo
	{
		OVERRIDE(void add(Account* account))
		{
			accounts.push_back(account);
		}

		OVERRIDE(Account* get(const std::string& accountId))
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
		OVERRIDE(void update(Account* account))
		{
			for (auto a : accounts)
			{
				if (a->getId() == account->getId())
				{
					remove(account->getId());
					add(account);

				}
			}

		}

		OVERRIDE(Account* remove(const std::string& accountId))
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
		std::vector<Account*> accounts;
	};
}

struct TestAccount : testing::Test
{

protected:
	virtual void SetUp()
	{
		accountRepo = new FakeAccountRepo();
		setAccountRepo(accountRepo);
		api = new AccountApi();
		jimPhoneNumber = "19999999999";
		jmAccountId = api->createAccount(jimPhoneNumber, JIM_INIT_AMOUNT);
	}

	virtual void TearDown()
	{
		api->destroyAccount(jmAccountId);
		delete api;
		delete accountRepo;
	}

protected:
	std::string jimPhoneNumber;
	AccountApi* api;
	std::string jmAccountId;
	FakeAccountRepo* accountRepo;
	const U32 JIM_INIT_AMOUNT{10000};
};

TEST_F(TestAccount, withdraw)
{
	const U32 AMOUNT = 1500;
	api->withdraw(jmAccountId, AMOUNT);
	ASSERT_EQ(JIM_INIT_AMOUNT - AMOUNT, api->getAmount(jmAccountId));
}

