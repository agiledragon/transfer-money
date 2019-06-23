#ifndef HF8215D25_4C3E_42B3_9C90_D8CA3450788C
#define HF8215D25_4C3E_42B3_9C90_D8CA3450788C


#include <pub/base/Types.h>
#include <string>

struct LocalAccountRepo;

struct TransferMoneyService
{
	TransferMoneyService();
	U32 getAmount(const std::string& accountId) const;

private:
	LocalAccountRepo* repo;
};



#endif
