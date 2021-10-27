#include <ros/ros.h>
#include <lab2_message/Message1.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

//typedef std::pair<std::string> TextNum;//, int> TextNum;

int main(int argc, char **argv){

    ros::init(argc,argv,"scout");

    ROS_INFO_STREAM("Hello!\n");

    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<lab2_message::Message1>("Name",10);

    std::vector< std::string > messageList;//TextNum > messageList;
    messageList.push_back("First 1 text");//;TextNum("First text", 1));
    messageList.push_back("Second 2 text");//TextNum("Second text", 2));
    messageList.push_back("Third 3 text");//TextNum("Third text", 3));
    messageList.push_back("Fourth 4 text");//TextNum("Fourth text", 4));
    messageList.push_back("Fifth 5 text");//TextNum("Fifth text", 5));
    messageList.push_back("Good 6 bye!");//TextNum("Good bye", 0));
    sleep(1);

    ros::Rate loop_rate(1);

    for(int i=0; i < messageList.size(); i++){
        lab2_message::Message1 message;
        message.text = messageList[i];
        //message.number = messageList[i].second;
        pub.publish(message);

        ROS_INFO("%s", messageList[i].c_str());//, messageList[i].second);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;

}