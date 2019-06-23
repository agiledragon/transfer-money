#include "domain/model/account/MoneyCollector.h"
#include "domain/model/account/Balance.h"
#include "domain/model/account/Phone.h"
#include "pub/log/log.h"

void MoneyCollector::withdraw(U32 amount)
{
	if (ROLE(Balance).get() < amount)
	{
		ERR_LOG("insufficient money!");
		return;
	}
	ROLE(Balance).decrease(amount);
	ROLE(Phone).sendWithdrawMsg(amount);
}

U32 MoneyCollector::getAmount() const
{
	return ROLE(Balance).get();
}
