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
    if(!join_listener_thread_.joinable() && kill_join_thread_)
    {
        join_listener_thread_ = std::thread(ThreadChatServerJoinListener);
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

void ChatServerController::ThreadChatServerJoinListener()
{
    std::cout << "Starting thread!" << std::endl;
    while(kill_join_thread_ == false)
    {
        CLIENT_COMMANDS command;
        int recv_res = zmq_recv(socket_join_request_from_client, &command, sizeof(command), ZMQ_RCVMORE);

        if(recv_res == -1)
            continue;

        switch (command) {
            case JOIN_REQUEST:
            {
            int name_size;
            zmq_recv(socket_join_request_from_client, &name_size, sizeof(command), ZMQ_RCVMORE);

            char * name;
            zmq_recv(socket_join_request_from_client, name, sizeof(name), ZMQ_DONTWAIT);
                break;
            }
            case SEND_MESSAGE:
            {

                break;
            }
        }
    }
}

