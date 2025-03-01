#include<ros/ros.h>
#include<std_msgs/Empty.h>
#include<std_msgs/Bool.h>


void cb2(const std_msgs::Bool &msgs){
    if(msgs.data == true){
        ROS_INFO_STREAM("kill");
        system("killall canberra-gtk-play");
    } 
}

int main(int argc, char** argv){
    ros::init(argc, argv, "Audio_ender");
    ros::NodeHandle nh;

    ros::Subscriber sub2 = nh.subscribe("/BTN", 1, &cb2);
    while(ros::ok()){
        ros::spin();
    }

}