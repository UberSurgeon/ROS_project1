#include<ros/ros.h>
#include<std_msgs/Empty.h>
#include<std_msgs/Bool.h>

bool check1 = false;


void cb(const std_msgs::Empty &msgs){
        check1 =!check1;
        if (check1 == true){
            ROS_INFO_STREAM("start OvO");
            system("canberra-gtk-play -f $(rospack find project1)/src/smaudio.ogg");
        }
}

int main(int argc, char** argv){
    ros::init(argc, argv, "Audio_player");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/motor_toggle", 1, &cb);
    while(ros::ok()){
        ros::spin();
    }

}