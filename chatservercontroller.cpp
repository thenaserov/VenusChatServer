#include "chatservercontroller.h"
#include "zmq.hpp"


ChatServerController::ChatServerController()
{

}

void ChatServerController::InitSockets()
{
    socket_join_request_from_client = zmq::socket_t(context, ZMQ_PUB);
    socket_join_request_from_client.bind("tcp://*:43434");
}

void ChatServerController::StartJoinThread()
{
    if(join_listener_thread_.joinable())
    {
        join_listener_thread_ = std::thread(ThreadChatServer);
        join_listener_thread_.join();
    }
}

void ChatServerController::StopJoinThread()
{

}

void ChatServerController::ThreadChatServer()
{
    std::cout << "Start join mechanism thread\n";
}

