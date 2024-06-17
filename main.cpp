#include"Logger.h"
#include"Receiver.h"
#include"Requester.h"
#include"HttpResponse.h"

int main() {
    std::string host = "www.baidu.com";
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    Receiver receiver;
    Requester requester;

    if (receiver.connectToServer(host, 80, sock)) {  // HTTP默认端口80
        std::cout << "Connected to " << host << std::endl;

        std::string request = requester.createGetRequest(host);
        if (requester.sendData(request, sock)) {
            std::cout << "Request sent, waiting for response..." << std::endl;
            std::string response = receiver.receiveData(sock);
            std::cout << "Response received:\n" << response << std::endl;
        } else {
            std::cerr << "Failed to send request." << std::endl;
        }
    } else {
        std::cerr << "Failed to connect to the server." << std::endl;
    }

    receiver.closeConnection();

    return 0;
}