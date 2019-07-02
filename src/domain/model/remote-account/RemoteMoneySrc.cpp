#include <domain/model/comm-role/AccountInfo.h>
#include <domain/model/comm-role/MoneyDest.h>
#include <domain/model/remote-account/RemoteMoneySrc.h>
#include <domain/model/remote-account/RemoteAccountProvider.h>


void RemoteMoneySrc::transferMoneyTo(MoneyDest& dest, U32 amount)
{
	dest.transferMoneyFrom(ROLE(AccountInfo).getAccountId(), amount);
	Response ok{false};
	sendProtocolResponse(ok);
}
