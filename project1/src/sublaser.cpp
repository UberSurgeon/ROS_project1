#include<ros/ros.h>
#include<sensor_msgs/LaserScan.h>
#include<std_msgs/Empty.h>

ros::Publisher pub;
std_msgs::Empty pubcall;
bool check1 = false;
bool lastcheck = false;
bool loop = false;

void cb(const sensor_msgs::LaserScan &msg){
    // ROS_INFO_STREAM_THROTTLE(1, "degree0 " << msg.ranges[0]);
    // ROS_INFO_STREAM_THROTTLE(1, "degree270 " << msg.ranges[270]);
    // ROS_INFO_STREAM_THROTTLE(1, "degree90 " << msg.ranges[90]);
    
    for (int i=250;i<=290;i++){
        int normalisei = i % 360;
        if (msg.ranges[normalisei] <= 0.3){
           check1 = true;
           loop = true;
           
        }

    }
    if (loop == false){
        check1 = false;
        lastcheck = false;
    }
    loop = false;
    ROS_INFO_STREAM_THROTTLE(1, check1);
    ROS_INFO_STREAM_THROTTLE(1, lastcheck);
    ROS_INFO_STREAM_THROTTLE(1, loop);
}

int main(int argc, char** argv){
    ros::init(argc, argv, "subscribe_laser_msg");
    ros::NodeHandle nh;
    pub = nh.advertise<std_msgs::Empty>("motor_toggle", 1000);
    ros::Subscriber sub = nh.subscribe("/scan", 1000, &cb);
    while(ros::ok())
    {
        if (check1 == true && lastcheck == false){
            ROS_ERROR_STREAM("OBJECT DETECTED");
            pub.publish(pubcall);
            lastcheck = true;
        }
        ros::spinOnce();
    }
    
}