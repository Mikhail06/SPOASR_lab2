cmake_minimum_required(VERSION 3.0.2)
project(lab2_scout)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    lab2_message
)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})
add_executable(scout src/scout.cpp)
target_link_libraries(scout ${catkin_LIBRARIES})
