#ifndef CHATSERVERCONTROLLER_H
#define CHATSERVERCONTROLLER_H

#include "zmq.hpp"
#include "Enums.h"
#include "tools.h"
#include <thread>
#include <iostream>

class ChatServerController
{
public:
    ChatServerController();
    void InitSockets();
    void StartJoinThread();
    void StopJoinThread();

private:
    std::thread join_listener_thread_;
    bool kill_join_thread_{true};
    // zmq sockets and context
    zmq::context_t context;
    zmq::socket_t socket_publish_for_clients_;
    zmq::socket_t socket_pull_from_clients_;
    void ThreadChatServerJoinListener();

protected:
};

#endif // CHATSERVERCONTROLLER_H
