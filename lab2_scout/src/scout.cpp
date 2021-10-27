#include <ros/ros.h>
#include <lab2_message/Message1.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

typedef std::tuple<std::string, int, std::string> TextNum;

int main(int argc, char **argv){

    ros::init(argc,argv,"scout");

    ROS_INFO_STREAM("Hello!\n");

    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<lab2_message::Message1>("Name",10); //Topic

    std::vector< TextNum > messageList;
    messageList.push_back(TextNum("I moved to the", 1, "house on this street"));
    messageList.push_back(TextNum("I live on the", 2, "floor"));
    messageList.push_back(TextNum(" ", 3, "days ago I was at a conference"));
    messageList.push_back(TextNum("There were only", 4, "people"));
    messageList.push_back(TextNum("I should be at work in", 5, "minutes. Good bye!"));
    sleep(1);

    ros::Rate loop_rate(1);

    for(int i=0; i < messageList.size(); i++){
        lab2_message::Message1 message;
        message.text1 = std::get<0>(messageList[i]);
        message.number = std::get<1>(messageList[i]);
        message.text2 = std::get<2>(messageList[i]);
        pub.publish(message);

        ROS_INFO("%s %d %s", std::get<0>(messageList[i]).c_str(), std::get<1>(messageList[i]), std::get<2>(messageList[i]).c_str());//messageList[i].first.c_str(), messageList[i].second,  messageList[i].third.c_str());
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;

}