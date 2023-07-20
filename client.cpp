#include "client.h"

Client::Client(const std::string& name, int socket_fd)
{
    name_ = name;
    socket_fd_ = socket_fd;
}
