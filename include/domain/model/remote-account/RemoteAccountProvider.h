#ifndef H4A89C97F_642C_4150_87CB_81C1EA13A8BD
#define H4A89C97F_642C_4150_87CB_81C1EA13A8BD


#include <pub/base/Types.h>
#include <string>

struct Response
{
	bool isFailed;
};

void sendTransferToProtocaMsg(const std::string& fromId, const std::string& toId, U32 amount);
Response waitProtocolResp();
void sendProtocolResponse(Response resp);



#endif
