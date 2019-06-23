#include "domain/model/account/Phone.h"
#include "domain/model/account/AccountInfo.h"
#include "pub/log/log.h"


Phone::Phone(const std::string& phoneNumber) : phoneNumber(phoneNumber)
{

}

bool Phone::operator==(ValueObject* rhs)
{
	return phoneNumber == dynamic_cast<Phone*>(rhs)->phoneNumber;
}

void Phone::sendWithdrawMsg(U32 amount)
{
	INFO_LOG("phone(%s): %u yuan has been withdrawed from accountId(%s)!",
			phoneNumber.c_str(), amount, ROLE(AccountInfo).getAccountId().c_str());
}

void Phone::sendTransferToMsg(const std::string& toId, U32 amount)
{
	INFO_LOG("phone(%s): accountId(%s) send %u yuan to accountId(%s)!",
			phoneNumber.c_str(), ROLE(AccountInfo).getAccountId().c_str(), amount, toId.c_str());
}

void Phone::sendTransferFromMsg(const std::string& fromId, U32 amount)
{
	INFO_LOG("phone(%s): accountId(%s) receive %u yuan from accountId(%s)!",
			phoneNumber.c_str(), ROLE(AccountInfo).getAccountId().c_str(), amount, fromId.c_str());
}
