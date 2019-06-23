#ifndef H31EB2176_C5BF_47BA_8640_E3F0600A541D
#define H31EB2176_C5BF_47BA_8640_E3F0600A541D

#include "pub/base/Types.h"
#include <string>

struct AccountRepo;

struct AccountService
{
	AccountService();

	std::string createAccount(const std::string& manId, const std::string& phoneNumber, U32 initAmount);
	void destroyAccount(const std::string& accountId);

private:
	AccountRepo* repo;
};





#endif
