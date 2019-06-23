#ifndef H4CFFA0F5_A592_4F3A_B033_9B2CD36AD920
#define H4CFFA0F5_A592_4F3A_B033_9B2CD36AD920


#include "pub/base/Types.h"
#include <string>

struct AccountRepo;

struct TransferMoneyToLocalService
{
	TransferMoneyToLocalService();
	void exec(const std::string& fromId, const std::string& toId, U32 amount);

private:
	AccountRepo* repo;
};


#endif
