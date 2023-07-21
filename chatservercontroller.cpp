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
    std::cout << "Here" << std::endl;
    if(!join_listener_thread_.joinable() && !kill_join_thread_)
    {
        join_listener_thread_ = std::thread(ThreadChatServer);
        join_listener_thread_.join();
    }
}

void ChatServerController::StopJoinThread()
{
    if(!kill_join_thread_)
    {
        kill_join_thread_ = true;
    }
}

void ChatServerController::ThreadChatServer()
{
    std::cout << "Starting thread!" << std::endl;
}

