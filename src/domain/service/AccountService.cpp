#include "domain/service/AccountService.h"
#include "domain/model/account/Account.h"
#include "domain/model/account/AccountRepo.h"
#include "domain/model/base/Role.h"

AccountService::AccountService()
{
	repo = getAccountRepo();
}

std::string AccountService::createAccount(const std::string& accountId, const std::string& phoneNumber, U32 initAmount)
{
	auto account = new Account(accountId, phoneNumber, initAmount);
	repo->add(account);
	return accountId;
}

void AccountService::destroyAccount(const std::string& accountId)
{
	auto account = repo->remove(accountId);
	delete account;
}
