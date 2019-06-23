#include <domain/model/local-account/LocalAccountRepo.h>

namespace
{
	LocalAccountRepo* accountRepo = nullptr;
}

void setLocalAccountRepo(LocalAccountRepo* repo)
{
	accountRepo = repo;
}

LocalAccountRepo* getLocalAccountRepo()
{
	return accountRepo;
}
