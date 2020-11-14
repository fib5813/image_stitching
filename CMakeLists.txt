cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "-lstdc++fs")
set(OpenCV_DIR /home/bubbles/installation/OpenCV-master/lib/cmake/opencv4)
set(PROJECT_INCLUDE_DIRS inc)
project(demo)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS}
                    ${PROJECT_INCLUDE_DIRS})
#message("${PROJECT_INCLUDE_DIRS}")

add_executable(demo src/main.cpp
                    src/Streamer.cpp
                    src/Tailor.cpp)
                    
target_link_libraries(demo ${OpenCV_LIBS} stdc++fs)