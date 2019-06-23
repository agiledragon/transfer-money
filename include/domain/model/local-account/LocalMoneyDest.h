#ifndef H37D30A34_49DD_455C_9D50_B405C928EA9D
#define H37D30A34_49DD_455C_9D50_B405C928EA9D


#include <domain/model/comm-role/AccountInfo.h>
#include <domain/model/local-account/Balance.h>
#include <domain/model/local-account/Phone.h>
#include <domain/model/comm-role/MoneyDest.h>
#include <string>

struct AccountInfo;
struct Balance;
struct Phone;

struct LocalMoneyDest : MoneyDest
{
	OVERRIDE(void transferMoneyFrom(const std::string& fromId, U32 amount));
	OVERRIDE(std::string getAccountId() const);

private:
	USE_ROLE(AccountInfo);
	USE_ROLE(Balance);
	USE_ROLE(Phone);
};



#endif
