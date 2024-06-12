#include"Logger.h"
#include"Receiver.h"
#include"HttpResponse.h"

int main() {
    std::string http_response = 
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html; charset=UTF-8\r\n"
    "Content-Length: 13\r\n"
    "Connection: close\r\n"
    "Date: Tue, 27 Apr 2021 12:28:53 GMT\r\n"
    "\r\n"
    "Hello, world!";

    Receiver receiver = Receiver();
    HttpResponse response = receiver.parseHttpResponse(http_response);
    std::cout << response;

    return 0;
}