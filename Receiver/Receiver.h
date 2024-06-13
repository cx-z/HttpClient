#include <iostream>
#include <string>
#include <netinet/in.h>

#include "HttpResponse.h"

class Receiver
{
private:
    int sock;
    struct sockaddr_in server_addr;
public:
    Receiver();
    ~Receiver();

    bool connectToServer(const std::string& host, int port);
    void closeConnection();
    std::string receiveData(int sock);
    HttpResponse parseHttpResponse(const std::string& response);
};
