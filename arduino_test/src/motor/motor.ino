#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Bool.h>

// put function declarations here:
int PIN_13 = 13;
int PIN_12 = 12;
int PIN_11 = 11;
int PIN_BTN = 8;


ros::NodeHandle nh;

std_msgs::UInt16 Status;
std_msgs::Bool BTN;
bool check = false;

void cb(const std_msgs::Empty& togglemsg){
    check = !check;
    if (check == true){
        digitalWrite(PIN_13, HIGH);
        digitalWrite(PIN_12, LOW);
        Status.data = 1;
        delay(3000);
        digitalWrite(PIN_13, LOW);
    } else{
        digitalWrite(PIN_13, LOW);
        digitalWrite(PIN_12, LOW);
        Status.data = 0;
    }
    
}


ros::Publisher pub("Status", &Status);
ros::Subscriber<std_msgs::Empty> sub("motor_toggle", &cb);
ros::Publisher pub2("BTN", &BTN);

void setup() {
    pinMode(PIN_13, OUTPUT);
    pinMode(PIN_12, OUTPUT);
    pinMode(PIN_11, OUTPUT);
    pinMode(PIN_BTN, INPUT_PULLUP);
    analogWrite(PIN_11, 130);
    nh.initNode();
    nh.advertise(pub);
    nh.advertise(pub2);
    nh.subscribe(sub);

}




void loop() {
    if (digitalRead(PIN_BTN) == HIGH) {
        BTN.data = false;
    } else {
        BTN.data = true;
    }
    pub.publish(&Status);
    pub2.publish(&BTN);
    nh.spinOnce();
    delay(100);
}

