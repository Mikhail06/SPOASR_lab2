#include <ros/ros.h>
#include <lab2_message/Message1.h>

std::string text;

void accomplice (const lab2_message::Message1 & message)
{
    ROS_INFO("Received a message: %s %d %s \n", message.text1.c_str(), message.number, message.text2.c_str());

    if (message.number % 2 != 0){
        ROS_INFO("-- Understand: %s %d %s. \n", message.text1.c_str(), message.number, message.text2.c_str());
    }

    if(message.number == 5){
        ROS_INFO("-- Good bye!");
        ros::shutdown();
    }
}

int main(int argc, char **argv){

    ros::init(argc,argv,"accomplice");

    ROS_INFO_STREAM("-- Hello!\n");

    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("Name", 10, accomplice);

    ros::spin();
    
    return 0;
    
}