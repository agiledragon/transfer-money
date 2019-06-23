#include <domain/model/local-account/LocalAccount.h>
#include <domain/service/AccountService.h>
#include <domain/model/base/Role.h>
#include <domain/model/local-account/LocalAccountRepo.h>

AccountService::AccountService()
{
	repo = getLocalAccountRepo();
}

std::string AccountService::createAccount(const std::string& accountId, const std::string& phoneNumber, U32 initAmount)
{
	auto account = new LocalAccount(accountId, phoneNumber, initAmount);
	repo->add(account);
	return accountId;
}

void AccountService::destroyAccount(const std::string& accountId)
{
	auto account = repo->remove(accountId);
	delete account;
}
