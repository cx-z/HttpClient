#include "HttpResponse.h"

// 重载operator<<，作为友元函数允许访问HttpResponse的私有部分
std::ostream& operator<<(std::ostream& os, const HttpResponse& response) {
    os << "Status Code: " << response.status_code << "\n";
    os << "Headers:\n";
    for (const auto& header : response.headers) {
        os << "  " << header.first << ": " << header.second << "\n";
    }
    os << "Body:\n" << response.body << "\n";
    return os;
}