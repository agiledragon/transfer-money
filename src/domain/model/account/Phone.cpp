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
	INFO_LOG("send msg to phone(%s) that %u yuan has been withdrawed from accountId(%s)!", phoneNumber.c_str(), amount, ROLE(AccountInfo).getAccountId().c_str());
}
