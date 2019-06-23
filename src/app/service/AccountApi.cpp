#include <app/service/AccountApi.h>


AccountApi::AccountApi()
: accountService(AccountService()), withdrawMoneyService(WithdrawMoneyService())
, transferMoneyToLocalService(TransferMoneyToLocalService())
, transferMoneyToRemoteService(TransferMoneyToRemoteService())
, transferMoneyFromRemoteService(TransferMoneyFromRemoteService())
, transferMoneyService(TransferMoneyService())
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

void AccountApi::withdrawMoney(const std::string& accountId, U32 amount)
{
	withdrawMoneyService.exec(accountId, amount);
}

U32 AccountApi::getAmount(const std::string& accountId)
{
	return transferMoneyService.getAmount(accountId);
}

void AccountApi::transferMoneyToLocal(const std::string& fromId, const std::string& toId, U32 amount)
{
	transferMoneyToLocalService.exec(fromId, toId, amount);
}

void AccountApi::transferMoneyToRemote(const std::string& fromId, const std::string& toId, U32 amount)
{
	transferMoneyToRemoteService.exec(fromId, toId, amount);
}

void AccountApi::transferMoneyFromRemote(const std::string& fromId, const std::string& toId, U32 amount)
{
	transferMoneyFromRemoteService.exec(fromId, toId, amount);
}


std::string AccountApi::generateAccountId(const std::string& phoneNumber)
{
	return phoneNumber.substr(2) + "888";
}
