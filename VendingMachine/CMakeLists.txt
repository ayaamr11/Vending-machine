cmake_minimum_required(VERSION 3.12)
project(teamtask_assi3_aya)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(teamtask_assi3_aya
        include/Buyer.h
        include/Item.h
        include/Machine.h
        include/Money.h
        src/Buyer.cpp
        src/Item.cpp
        src/Machine.cpp
        src/Money.cpp
        main.cpp)
