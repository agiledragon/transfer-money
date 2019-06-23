#ifndef HFA103727_C940_4878_997B_3BBA35F3EBFC
#define HFA103727_C940_4878_997B_3BBA35F3EBFC


#include <domain/model/base/Role.h>
#include <pub/base/Types.h>
#include <pub/base/Keywords.h>

struct MoneyDest;

struct MoneySrc : Role
{
	ABSTRACT(void transferMoneyTo(MoneyDest& dst, U32 amount));
};


#endif
