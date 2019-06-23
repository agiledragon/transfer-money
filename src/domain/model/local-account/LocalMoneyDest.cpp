#include <domain/model/local-account/LocalMoneyDest.h>


void LocalMoneyDest::transferMoneyFrom(const std::string& fromId, U32 amount)
{
	ROLE(Balance).increase(amount);
	ROLE(Phone).sendTransferFromMsg(fromId, amount);
}

std::string LocalMoneyDest::getAccountId() const
{
	return ROLE(AccountInfo).getAccountId();
}
