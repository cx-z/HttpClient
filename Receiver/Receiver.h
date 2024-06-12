#include <iostream>
#include <string>

#include "HttpResponse.h"

class Receiver
{
private:
    /* data */
public:
    std::string receiveData(int sock);
    HttpResponse parseHttpResponse(const std::string& response);
};
