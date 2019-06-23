#ifndef HDF4D5D3D_ABAA_48E5_8669_00132A27C6E9
#define HDF4D5D3D_ABAA_48E5_8669_00132A27C6E9


#include "domain/model/base/AggregateRoot.h"
#include "domain/model/account/MoneyCollector.h"
#include "domain/model/account/MoneySrc.h"
#include "domain/model/account/MoneyDest.h"
#include "domain/model/account/Phone.h"
#include "domain/model/account/AccountInfo.h"
#include "domain/model/account/Balance.h"


struct Account : AggregateRoot
			   , MoneyCollector
			   , MoneySrc
			   , MoneyDest
			   , private AccountInfo
			   , private Balance
			   , private Phone
{
	Account(const std::string& accountId, const std::string& phoneNumber, U32 initialAmount);

private:
	IMPL_ROLE(AccountInfo);
	IMPL_ROLE(Balance);
	IMPL_ROLE(Phone);
};


#endif
