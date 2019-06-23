#include <domain/model/remote-account/RemoteAccount.h>

RemoteAccount::RemoteAccount(const std::string& accountId)
: AggregateRoot(accountId), AccountInfo(accountId)
{

}
