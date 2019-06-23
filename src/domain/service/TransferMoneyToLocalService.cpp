#include "domain/service/TransferMoneyToLocalService.h"
#include "domain/model/account/Account.h"
#include "domain/model/account/AccountRepo.h"
#include "domain/model/base/Role.h"

TransferMoneyToLocalService::TransferMoneyToLocalService()
{
	repo = getAccountRepo();
}

void TransferMoneyToLocalService::exec(const std::string& fromId, const std::string& toId, U32 amount)
{
	auto fromAccount = repo->get(fromId);
	auto toAccount = repo->get(toId);
	SELF(*fromAccount, MoneySrc).transferMoneyTo(SELF(*toAccount, MoneyDest), amount);
}
