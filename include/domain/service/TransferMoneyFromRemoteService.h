#ifndef H2819BDA6_AB52_47CB_A644_9DF1E10F3EE5
#define H2819BDA6_AB52_47CB_A644_9DF1E10F3EE5


#include <pub/base/Types.h>
#include <string>

struct LocalAccountRepo;

struct TransferMoneyFromRemoteService
{
	TransferMoneyFromRemoteService();
	void exec(const std::string& fromId, const std::string& toId, U32 amount);

private:
	LocalAccountRepo* repo;
};




#endif
