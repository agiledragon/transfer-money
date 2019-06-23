#ifndef HF097FB54_782B_4951_BBA0_2146B311CC07
#define HF097FB54_782B_4951_BBA0_2146B311CC07


#include <domain/model/comm-role/AccountInfo.h>
#include <domain/model/comm-role/MoneyDest.h>
#include <string>

struct AccountInfo;

struct RemoteMoneyDest : MoneyDest
{
	void transferMoneyFrom(const std::string& fromId, U32 amount);
	std::string getAccountId() const;

private:
	USE_ROLE(AccountInfo);
};



#endif
