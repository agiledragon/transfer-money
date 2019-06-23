#ifndef H29CD13D2_4382_4E06_99DA_B499B523F6EE
#define H29CD13D2_4382_4E06_99DA_B499B523F6EE


#include "domain/model/base/Role.h"
#include "pub/base/Types.h"

#include <string>

struct Balance;
struct Phone;

struct MoneyCollector : Role
{
	void withdraw(U32 amount);
	U32 getAmount() const;

private:
	USE_ROLE(Balance);
	USE_ROLE(Phone);
};

#endif
