#ifndef CLIENTFACTORY_H
#define CLIENTFACTORY_H

#include <client.h>
#include <memory>


class ClientFactory
{
public:
    std::unique_ptr<Client> create_client(const std::string& name, int socket_fd) {
        return std::make_unique<Client>(name, socket_fd);
    }
};

#endif // CLIENTFACTORY_H
