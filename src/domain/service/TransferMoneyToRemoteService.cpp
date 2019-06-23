#include <domain/model/local-account/LocalAccount.h>
#include <domain/service/TransferMoneyToRemoteService.h>
#include <domain/model/base/Role.h>
#include <domain/model/local-account/LocalAccountRepo.h>
#include <domain/model/remote-account/RemoteAccount.h>

TransferMoneyToRemoteService::TransferMoneyToRemoteService()
{
	repo = getLocalAccountRepo();
}

void TransferMoneyToRemoteService::exec(const std::string& fromId, const std::string& toId, U32 amount)
{
	auto fromAccount = repo->get(fromId);
	auto toAccount = new RemoteAccount(toId);
	SELF(*fromAccount, LocalMoneySrc).transferMoneyTo(SELF(*toAccount, RemoteMoneyDest), amount);
	delete toAccount;
}
