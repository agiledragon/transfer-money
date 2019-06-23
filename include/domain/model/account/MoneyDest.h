#ifndef H37D30A34_49DD_455C_9D50_B405C928EA9D
#define H37D30A34_49DD_455C_9D50_B405C928EA9D


#include "domain/model/base/Role.h"
#include "pub/base/Types.h"
#include "domain/model/account/Balance.h"
#include "domain/model/account/Phone.h"
#include "domain/model/account/AccountInfo.h"

#include <string>

struct AccountInfo;
struct Balance;
struct Phone;

struct MoneyDest : Role
{
	void transferMoneyFrom(const std::string& srcAccountId, U32 amount) const;
	std::string getAccountId() const;

private:
	USE_ROLE(AccountInfo);
	USE_ROLE(Balance);
	USE_ROLE(Phone);
};



#endif
