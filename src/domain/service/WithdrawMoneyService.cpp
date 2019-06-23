#include "domain/service/WithdrawMoneyService.h"
#include "domain/model/account/Account.h"
#include "domain/model/account/AccountRepo.h"
#include "domain/model/base/Role.h"

WithdrawMoneyService::WithdrawMoneyService()
{
	repo = getAccountRepo();
}

void WithdrawMoneyService::exec(const std::string& accountId, U32 amount)
{
	auto account = repo->get(accountId);
	SELF(*account, MoneyCollector).withdraw(amount);
}

U32 WithdrawMoneyService::getAmount(const std::string& accountId) const
{
	auto account = repo->get(accountId);
	return SELF(*account, MoneyCollector).getAmount();
}
