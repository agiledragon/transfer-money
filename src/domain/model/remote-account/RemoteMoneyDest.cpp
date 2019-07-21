#include <domain/model/remote-account/RemoteMoneyDest.h>
#include <domain/model/remote-account/RemoteAccountProvider.h>


void RemoteMoneyDest::transferMoneyFrom(const std::string& fromId, U32 amount)
{
	sendTransferToProtocolMsg(fromId, ROLE(AccountInfo).getAccountId(), amount);
	Response resp = waitProtocolResp();
	if (resp.isFailed)
	{
		throw "transfer money to remote fail";
	}

}

std::string RemoteMoneyDest::getAccountId() const
{
	return ROLE(AccountInfo).getAccountId();
}
