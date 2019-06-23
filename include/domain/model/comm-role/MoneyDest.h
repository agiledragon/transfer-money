#ifndef HE505D656_3291_4CAA_8224_D1840E5A1115
#define HE505D656_3291_4CAA_8224_D1840E5A1115

#include <domain/model/base/Role.h>
#include <pub/base/Types.h>
#include <pub/base/Keywords.h>

struct MoneyDest : Role
{
	ABSTRACT(void transferMoneyFrom(const std::string& fromId, U32 amount));
	ABSTRACT(std::string getAccountId() const);
};

#endif
