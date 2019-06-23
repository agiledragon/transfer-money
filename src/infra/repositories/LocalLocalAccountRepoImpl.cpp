#include <domain/model/local-account/LocalAccountRepo.h>

struct LocalAccountRepoImpl : LocalAccountRepo
{
	OVERRIDE(void add(LocalAccount* account))
	{

	}

	OVERRIDE(LocalAccount* get(const std::string& accountId))
	{
		return nullptr;
	}

	OVERRIDE(void update(LocalAccount* account))
	{

	}

	OVERRIDE(LocalAccount* remove(const std::string& accountId))
	{
		return nullptr;
	}
};
