#include <domain/model/local-account/LocalAccount.h>
#include <domain/service/WithdrawMoneyService.h>
#include <domain/model/base/Role.h>
#include <domain/model/local-account/LocalAccountRepo.h>

WithdrawMoneyService::WithdrawMoneyService()
{
	repo = getLocalAccountRepo();
}

void WithdrawMoneyService::exec(const std::string& accountId, U32 amount)
{
	auto account = repo->get(accountId);
	SELF(*account, MoneyCollector).withdraw(amount);
}
