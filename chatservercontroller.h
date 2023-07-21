#ifndef CHATSERVERCONTROLLER_H
#define CHATSERVERCONTROLLER_H

#include "zmq.hpp"
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
    static bool kill_join_thread_{true};
    // zmq sockets and context
    zmq::context_t context;
    static zmq::socket_t socket_join_request_from_client;
    static zmq::socket_t socket_join_requset_answer;
    static void ThreadChatServerJoinListener();

protected:
};

#endif // CHATSERVERCONTROLLER_H
