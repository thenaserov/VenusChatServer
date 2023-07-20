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

}

void ChatServerController::StopJoinThread()
{

}
