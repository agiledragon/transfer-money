#include <domain/model/comm-role/AccountInfo.h>


AccountInfo::AccountInfo(const std::string& accountId) : Entity(accountId)
{

}

std::string AccountInfo::getAccountId() const
{
	return getId();
}
