#include<iostream>
#include<string>

class Requester
{
private:
    /* data */
public:

    bool sendData(const std::string& data, int sock);
    // 构造GET请求 
    std::string createGetRequest(const std::string& host, const std::string& path = "/");
    // 构造POST请求
    std::string createPostRequest(const std::string& host, const std::string& path, const std::string& contentType, const std::string& data);
};
