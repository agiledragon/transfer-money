#ifndef HB4FB1F4B_62CC_4211_8541_1AE017733A76
#define HB4FB1F4B_62CC_4211_8541_1AE017733A76

#include <pub/base/Types.h>
#include <string>

struct LocalAccountRepo;

struct WithdrawMoneyService
{
	WithdrawMoneyService();
	void exec(const std::string& accountId, U32 amount);

private:
	LocalAccountRepo* repo;
};



#endif
