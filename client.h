#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client
{
public:
    Client(const std::string& name, int socket_fd);

    void send_message(const std::string& message) {
        // send message to this client's socket
    }

private:
    std::string name_;
    int socket_fd_;
};

#endif // CLIENT_H
