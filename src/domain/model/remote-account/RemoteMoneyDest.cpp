#include <domain/model/remote-account/RemoteMoneyDest.h>

namespace
{
	void sendTransferToProtocaMsg(const std::string& fromId, const std::string& toId, U32 amount)
	{

	}

	struct Response
	{
		bool isFailed;
	};

	Response waitProtocolResp()
	{
		Response resp{false};
		return resp;
	}

}

void RemoteMoneyDest::transferMoneyFrom(const std::string& fromId, U32 amount)
{
	sendTransferToProtocaMsg(fromId, ROLE(AccountInfo).getAccountId(), amount);
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
