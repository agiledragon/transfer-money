#include <domain/model/local-account/LocalAccount.h>
#include <domain/service/TransferMoneyFromRemoteService.h>
#include <domain/model/base/Role.h>
#include <domain/model/local-account/LocalAccountRepo.h>
#include <domain/model/remote-account/RemoteAccount.h>

TransferMoneyFromRemoteService::TransferMoneyFromRemoteService()
{
	repo = getLocalAccountRepo();
}

void TransferMoneyFromRemoteService::exec(const std::string& fromId, const std::string& toId, U32 amount)
{
	auto fromAccount = new RemoteAccount(toId);
	auto toAccount = repo->get(toId);
	SELF(*fromAccount, RemoteMoneySrc).transferMoneyTo(SELF(*toAccount, LocalMoneyDest), amount);
	delete fromAccount;
}
