#include <domain/model/local-account/LocalAccount.h>

LocalAccount::LocalAccount(const std::string& accountId, const std::string& phoneNumber, U32 initialAmount)
: AggregateRoot(accountId), AccountInfo(accountId), Balance(initialAmount), Phone(phoneNumber)
{

}
