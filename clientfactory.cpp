#include "clientfactory.h"

//ClientFactory::ClientFactory()
//{

//}

std::unique_ptr<Client> ClientFactory::create_client(const std::string &name, int socket_fd)
{
    return std::make_unique<Client>(name, socket_fd);
}
