#ifndef HBEC0C61F_8A73_45CA_8B9A_E316589E955C
#define HBEC0C61F_8A73_45CA_8B9A_E316589E955C

#include <domain/model/comm-role/AccountInfo.h>
#include <domain/model/base/AggregateRoot.h>
#include <domain/model/remote-account/RemoteMoneyDest.h>

struct RemoteAccount : AggregateRoot
			   , RemoteMoneyDest
			   , private AccountInfo
{
	RemoteAccount(const std::string& accountId);

private:
	IMPL_ROLE(AccountInfo);
};



#endif
