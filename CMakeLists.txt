cmake_minimum_required(VERSION 3.20)

project(rxi_utility VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(${PROJECT_NAME}
        source/main.cpp
        source/app_args.cpp
        source/rxi_utils.cpp
)

include_directories(${PROJECT_NAME}
        include
)