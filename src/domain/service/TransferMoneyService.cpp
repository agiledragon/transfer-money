#include <domain/model/local-account/LocalAccount.h>
#include <domain/model/local-account/LocalMoneySrc.h>
#include <domain/service/TransferMoneyService.h>
#include <domain/model/base/Role.h>
#include <domain/model/local-account/LocalAccountRepo.h>

TransferMoneyService::TransferMoneyService()
{
	repo = getLocalAccountRepo();
}

U32 TransferMoneyService::getAmount(const std::string& accountId) const
{
	auto account = repo->get(accountId);
	return SELF(*account, LocalMoneySrc).getAmount();
}
