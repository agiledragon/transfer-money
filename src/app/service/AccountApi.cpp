#include "app/service/AccountApi.h"


AccountApi::AccountApi()
: accountService(AccountService()), withdrawerService(WithdrawMoneyService())
{

}

std::string AccountApi::createAccount(const std::string& phoneNumber, U32 initAmount)
{
	auto id = generateAccountId(phoneNumber);
	accountService.createAccount(id, phoneNumber, initAmount);
	return id;
}

void AccountApi::destroyAccount(const std::string& accountId)
{
	accountService.destroyAccount(accountId);
}

void AccountApi::withdraw(const std::string& accountId, U32 amount)
{
	withdrawerService.exec(accountId, amount);
}

U32 AccountApi::getAmount(const std::string& accountId)
{
	return withdrawerService.getAmount(accountId);
}

std::string AccountApi::generateAccountId(const std::string& phoneNumber)
{
	return phoneNumber.substr(2) + "888";
}
