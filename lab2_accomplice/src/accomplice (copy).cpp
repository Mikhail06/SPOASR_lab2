#include <ros/ros.h>
#include <lab2_message/Message1.h>

std::string text;

void accomplice (const lab2_message::Message1 & message)
{

    ROS_INFO("Received a message with text %s. \n", message.text.c_str());

    if(message.text.c_str() == "Good bye!"){
        ROS_INFO("Good bye!");
        ros::shutdown();
    }

    /*if (message.number % 2 == 0){
        ROS_INFO("Understand: %s. \n", text.c_str());
        text = message.text;
    }*/
    
    /*if(message.number == 0){
        ROS_INFO("Good bye!");
        ros::shutdown();
    }*/

}

int main(int argc, char **argv){

    ros::init(argc,argv,"accomplice");

    ROS_INFO_STREAM("Hello!\n");

    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("Name", 10, accomplice);

    ros::spin();
    
    return 0;
    
}