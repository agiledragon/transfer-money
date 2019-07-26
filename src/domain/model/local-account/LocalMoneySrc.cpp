#include <domain/model/comm-role/AccountInfo.h>
#include <domain/model/local-account/Balance.h>
#include <domain/model/comm-role/MoneyDest.h>
#include <domain/model/local-account/LocalMoneySrc.h>
#include <domain/model/local-account/Phone.h>


void LocalMoneySrc::transferMoneyTo(MoneyDest& dest, U32 amount)
{
	if (ROLE(Balance).get() < amount)
	{
		throw "insufficient money!";
	}
	dest.transferMoneyFrom(ROLE(AccountInfo).getAccountId(), amount);
	ROLE(Balance).decrease(amount);
	ROLE(Phone).sendTransferToMsg(dest.getAccountId(), amount);
}

U32 LocalMoneySrc::getAmount() const
{
	return ROLE(Balance).get();
}
