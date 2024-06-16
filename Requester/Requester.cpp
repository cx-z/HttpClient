#include"Requester.h"
#include"Logger.h"

#include <sys/socket.h>
#include <string>

// Requester.cpp中实现
bool Requester::sendData(const std::string& data, int sock) {
    int sendCode = send(sock, data.c_str(), data.length(), 0);
    LOG("SendCode %d", sendCode);
    if (sendCode < 0) {
        std::cerr << "Failed to send data\n";
        return false;
    }
    return true;
}

std::string Requester::createGetRequest(const std::string& host, const std::string& path) {
    std::string request = "GET " + path + " HTTP/1.1\r\n";
    request += "Host: " + host + "\r\n";
    request += "Connection: close\r\n";
    request += "\r\n";
    return request;
}

std::string Requester::createPostRequest(const std::string& host, const std::string& path, const std::string& contentType, const std::string& data) {
    std::string request = "POST " + path + " HTTP/1.1\r\n";
    request += "Host: " + host + "\r\n";
    request += "Content-Type: " + contentType + "\r\n";
    request += "Content-Length: " + std::to_string(data.size()) + "\r\n";
    request += "Connection: close\r\n";
    request += "\r\n";
    request += data;
    return request;
}