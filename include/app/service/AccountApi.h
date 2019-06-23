#ifndef H3609D1A0_41F0_4D0B_9133_7849016D0332
#define H3609D1A0_41F0_4D0B_9133_7849016D0332


#include "pub/base/Types.h"
#include "domain/service/AccountService.h"
#include "domain/service/WithdrawMoneyService.h"
#include "domain/service/TransferMoneyToLocalService.h"
#include "domain/service/TransferMoneyService.h"
#include <string>

struct AccountApi
{
	AccountApi();

	std::string createAccount(const std::string& phoneNumber, U32 initAmount);
	void destroyAccount(const std::string& accountId);
	void withdrawMoney(const std::string& accountId, U32 amount);
	U32 getAmount(const std::string& accountId);
	void transferMoneyToLocal(const std::string& fromId, const std::string& toId, U32 amount);

private:
	std::string generateAccountId(const std::string& phoneNumber);

private:
	AccountService accountService;
	WithdrawMoneyService withdrawMoneyService;
	TransferMoneyToLocalService transferMoneyToLocalService;
	TransferMoneyService transferMoneyService;
};



#endif
