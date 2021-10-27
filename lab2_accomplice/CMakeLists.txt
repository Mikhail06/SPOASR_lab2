cmake_minimum_required(VERSION 3.0.2)
project(lab2_accomplice)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    lab2_message
)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})
add_executable(accomplice src/accomplice.cpp)
target_link_libraries(accomplice ${catkin_LIBRARIES})
