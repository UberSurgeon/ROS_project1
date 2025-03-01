#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Empty.h>

// put function declarations here:
int PIN_13 = 13;
int PIN_12 = 12;
int PIN_11 = 11;


ros::NodeHandle nh;

std_msgs::UInt16 Status;
bool check = false;

void cb(const std_msgs::Empty togglemsg){
    check = !check;
    if (check == true){
        digitalWrite(PIN_13, HIGH);
        digitalWrite(PIN_12, LOW);
        Status.data = 1;
    } else{
        digitalWrite(PIN_13, LOW);
        digitalWrite(PIN_12, LOW);
        Status.data = 0;
    }
    
}


ros::Publisher pub("Status", &Status);
ros::Subscriber<std_msgs::Empty> sub("motor_toggle", &cb);

void setup() {
    pinMode(PIN_13, OUTPUT);
    pinMode(PIN_12, OUTPUT);
    pinMode(PIN_11, OUTPUT);
    analogWrite(PIN_11, 130);
    nh.initNode();
    nh.advertise(pub);
    nh.subscribe(sub);

}




void loop() {
    pub.publish(&Status);
    nh.spinOnce();
    delay(100);
}

