#include <domain/model/local-account/Balance.h>
#include <domain/model/local-account/MoneyCollector.h>
#include <domain/model/local-account/Phone.h>

void MoneyCollector::withdraw(U32 amount)
{
	if (ROLE(Balance).get() < amount)
	{
		throw "insufficient money!";
		return;
	}
	ROLE(Balance).decrease(amount);
	ROLE(Phone).sendWithdrawMsg(amount);
}
