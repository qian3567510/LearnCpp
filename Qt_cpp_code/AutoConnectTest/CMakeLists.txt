cmake_minimum_required(VERSION 3.0.0)
project(TestApp VERSION 0.1.0)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_AUTOMOC YES)

add_executable(TestApp WIN32 main.cpp app.h app.cpp)
target_link_libraries(TestApp PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)