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
    bool kill_join_thread_{false};
    // zmq sockets and context
    zmq::context_t context;
    zmq::socket_t socket_join_request_from_client;
    zmq::socket_t socket_join_requset_answer;
    static void ThreadChatServer();

protected:
};

#endif // CHATSERVERCONTROLLER_H
