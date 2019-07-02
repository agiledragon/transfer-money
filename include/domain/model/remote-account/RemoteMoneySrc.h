#ifndef HDD98495C_501C_4B55_A399_524E6BA67800
#define HDD98495C_501C_4B55_A399_524E6BA67800


#include <domain/model/comm-role/MoneySrc.h>

struct AccountInfo;
struct MoneyDest;

struct RemoteMoneySrc : MoneySrc
{
	OVERRIDE(void transferMoneyTo(MoneyDest& dest, U32 amount));

private:
	USE_ROLE(AccountInfo);
};


#endif
