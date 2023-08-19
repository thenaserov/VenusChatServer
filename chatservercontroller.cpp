#include "chatservercontroller.h"
#include "zmq.hpp"


ChatServerController::ChatServerController()
{

}

void ChatServerController::InitSockets()
{
    socket_subscribe_to_clients_ = zmq::socket_t(context, ZMQ_SUB);
    socket_subscribe_to_clients_.bind("tcp://*:43434");

    socket_publish_for_clients_ = zmq::socket_t(context ,ZMQ_PUB);
    socket_publish_for_clients_.bind("tcp://*:43435");
}

void ChatServerController::StartJoinThread()
{
    std::cout << "Here" << std::endl;
    if(!join_listener_thread_.joinable() && kill_join_thread_)
    {
        join_listener_thread_ = std::thread(&ChatServerController::ThreadChatServerJoinListener, this);
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
        int recv_res = zmq_recv(socket_subscribe_to_clients_, &command, sizeof(command), ZMQ_RCVMORE);

        if(recv_res == -1)
            continue;

        switch (command) {
            case JOIN_REQUEST:
            {
            int name_size;
            zmq_recv(socket_subscribe_to_clients_, &name_size, sizeof(command), ZMQ_RCVMORE);
            char name[name_size];
            zmq_recv(socket_subscribe_to_clients_, name, sizeof(name), ZMQ_DONTWAIT);
            std::string join = name;
            join.append(" joined!");
            int size = join.length();
            zmq_send(socket_publish_for_clients_, &size, sizeof(int), ZMQ_SNDMORE);
            zmq_send(socket_publish_for_clients_, Tools::str2charstar(join), sizeof(name) + 8, ZMQ_DONTWAIT);
            std::cout << join << std::endl;
            break;
            }
            case SEND_MESSAGE:
            {
            int message_length;
            zmq_recv(socket_subscribe_to_clients_, &message_length, sizeof(int), ZMQ_RCVMORE);
            char message[message_length];
            zmq_recv(socket_subscribe_to_clients_, message, sizeof (message), ZMQ_DONTWAIT);
            zmq_send(socket_publish_for_clients_, message, sizeof(message), ZMQ_DONTWAIT);
            break;
            }
        }
    }
}

