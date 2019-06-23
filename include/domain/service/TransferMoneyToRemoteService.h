#ifndef H71CB6BD4_07A1_482D_8159_12E282A036C5
#define H71CB6BD4_07A1_482D_8159_12E282A036C5


#include <pub/base/Types.h>
#include <string>

struct LocalAccountRepo;

struct TransferMoneyToRemoteService
{
	TransferMoneyToRemoteService();
	void exec(const std::string& fromId, const std::string& toId, U32 amount);

private:
	LocalAccountRepo* repo;
};



#endif
