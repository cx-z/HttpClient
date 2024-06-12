#pragma once

#include <iostream>
#include <string>
#include <map>

class HttpResponse
{
private:
    /* data */
public:
    int status_code;
    std::map<std::string, std::string> headers;
    std::string body;

    // 友元声明，允许此函数访问私有和受保护的成员
    friend std::ostream& operator<<(std::ostream& os, const HttpResponse& response);
};
