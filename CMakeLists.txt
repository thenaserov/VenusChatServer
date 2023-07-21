cmake_minimum_required(VERSION 3.5)

project(VenusChatServer LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(ZMQ_LIBRARIES /usr/lib/libzmq.so)
set (ZMQ_INCLUDE_DIR /usr/include)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${ZMQ_INCLUDE_DIR})

find_package(Qt5Core REQUIRED)

add_executable(VenusChatServer
  main.cpp
  zmq.hpp
  Structs.h
  Enums.h
  chatservercontroller.cpp
  chatservercontroller.h
  client.cpp
  client.h
  clientfactory.cpp
  clientfactory.h
  tools.cpp
  tools.h
)
target_link_libraries(VenusChatServer Qt5::Core ${ZMQ_LIBRARIES})
