#ifndef HBAE654BC_9A9A_4189_BD3A_3F6D4020FFF1
#define HBAE654BC_9A9A_4189_BD3A_3F6D4020FFF1


#include <domain/model/comm-role/MoneySrc.h>

struct AccountInfo;
struct Balance;
struct Phone;
struct MoneyDest;

struct LocalMoneySrc : MoneySrc
{
	OVERRIDE(void transferMoneyTo(MoneyDest& dst, U32 amount));
	U32 getAmount() const;

private:
	USE_ROLE(AccountInfo);
	USE_ROLE(Balance);
	USE_ROLE(Phone);
};


#endif
