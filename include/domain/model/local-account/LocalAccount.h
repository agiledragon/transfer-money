#ifndef HDF4D5D3D_ABAA_48E5_8669_00132A27C6E9
#define HDF4D5D3D_ABAA_48E5_8669_00132A27C6E9


#include <domain/model/comm-role/AccountInfo.h>
#include <domain/model/local-account/Balance.h>
#include <domain/model/local-account/MoneyCollector.h>
#include <domain/model/local-account/Phone.h>
#include <domain/model/base/AggregateRoot.h>
#include <domain/model/local-account/LocalMoneyDest.h>
#include <domain/model/local-account/LocalMoneySrc.h>


struct LocalAccount : AggregateRoot
                    , MoneyCollector
                    , LocalMoneySrc
                    , LocalMoneyDest
                    , private AccountInfo
                    , private Balance
                    , private Phone
{
	LocalAccount(const std::string& accountId,
			const std::string& phoneNumber,
			U32 initialAmount);

private:
	IMPL_ROLE(AccountInfo);
	IMPL_ROLE(Balance);
	IMPL_ROLE(Phone);
};


#endif
