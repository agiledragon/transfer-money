#include <domain/model/local-account/LocalAccount.h>
#include <domain/service/TransferMoneyToLocalService.h>
#include <domain/model/base/Role.h>
#include <domain/model/local-account/LocalAccountRepo.h>

TransferMoneyToLocalService::TransferMoneyToLocalService()
{
	repo = getLocalAccountRepo();
}

void TransferMoneyToLocalService::exec(const std::string& fromId, const std::string& toId, U32 amount)
{
	auto fromAccount = repo->get(fromId);
	auto toAccount = repo->get(toId);
	SELF(*fromAccount, LocalMoneySrc).transferMoneyTo(SELF(*toAccount, LocalMoneyDest), amount);
}
