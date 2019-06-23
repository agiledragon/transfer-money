#include "domain/service/TransferMoneyService.h"
#include "domain/model/account/Account.h"
#include "domain/model/account/AccountRepo.h"
#include "domain/model/base/Role.h"
#include "domain/model/account/MoneySrc.h"

TransferMoneyService::TransferMoneyService()
{
	repo = getAccountRepo();
}

U32 TransferMoneyService::getAmount(const std::string& accountId) const
{
	auto account = repo->get(accountId);
	return SELF(*account, MoneySrc).getAmount();
}
