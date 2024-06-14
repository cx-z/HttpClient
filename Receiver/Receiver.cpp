#include "Receiver.h"

#include <sstream>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

Receiver::Receiver() : sock(-1) {
    // 确保地址结构体被清零
    memset(&server_addr, 0, sizeof(server_addr));
}

Receiver::~Receiver() {
    closeConnection();
}

bool Receiver::connectToServer(const std::string& host, int port) {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Cannot create socket\n";
        return false;
    }

    struct hostent *server = gethostbyname(host.c_str());
    if (server == nullptr) {
        std::cerr << "No such host\n";
        return false;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    int connectCode = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (connectCode < 0) {
        std::cerr << "Connecting failed\n";
        return false;
    }

    return true;
}

void Receiver::closeConnection() {
    if (sock != -1) {
        close(sock);
        sock = -1;
    }
}

// 封装的接收数据函数
std::string Receiver::receiveData(int sock) {
    this->sock = sock;
    const int buffer_size = 4096;
    char buffer[buffer_size];
    std::string response;
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, buffer_size, 0)) > 0) {
        response.append(buffer, bytes_received);
    }

    if (bytes_received == -1) {
        std::cerr << "Failed to receive data\n";
        return "";
    } 

    return response;
}

HttpResponse Receiver::parseHttpResponse(const std::string& response) {
    HttpResponse result;
    std::istringstream response_stream(response);
    std::string line;
    std::string http_version;
    
    // 解析状态行
    if (std::getline(response_stream, line) && !line.empty()) {
        std::istringstream status_line(line);
        status_line >> http_version;               // HTTP版本
        status_line >> result.status_code;         // 状态码
        // 其余部分是状态消息，通常不需要解析使用
    }

    // 解析头部字段
    while (std::getline(response_stream, line) && !line.empty()) {
        std::size_t colon_pos = line.find(':');
        if (colon_pos != std::string::npos) {
            std::string key = line.substr(0, colon_pos);
            std::string value = line.substr(colon_pos + 2);
            result.headers[key] = value;
        }
    }

    // 解析正文部分
    // 注意：正文可能在某些响应中不存在，例如响应状态码为204（无内容）或304（未修改）时
    std::string body_content;
    while (std::getline(response_stream, line)) {
        body_content += line + "\n";
    }
    result.body = body_content;

    return result;
}