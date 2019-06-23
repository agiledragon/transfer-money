#ifndef H13D2C1E1_4A8B_411D_ACA9_461323B9B2D7
#define H13D2C1E1_4A8B_411D_ACA9_461323B9B2D7

#include <pub/base/Keywords.h>
#include <string>

struct LocalAccount;

struct LocalAccountRepo
{
	virtual ~LocalAccountRepo() = default;

	ABSTRACT(void add(LocalAccount* account));
	ABSTRACT(LocalAccount* get(const std::string& accountId));
	ABSTRACT(void update(LocalAccount* account));
	ABSTRACT(LocalAccount* remove(const std::string& accountId));
};

void setLocalAccountRepo(LocalAccountRepo* repo);
LocalAccountRepo* getLocalAccountRepo();

#endif
