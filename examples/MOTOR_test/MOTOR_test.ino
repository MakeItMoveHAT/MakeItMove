#include <DC_motor.h>
//#include "CONFIG.h"
/*
  ┌────────────────────────────────────────────────────┐
  │ Make-IT-Move by JumpLabs                           ┃
  ├────────────────────────────────────────────────────┤
  │  website :                                         ┃
  ├────────────────────────────────────────────────────┤
  │  LICENSE : Make-IT-Move is  OpenSourced            ┃
  ├────────────────────────────────────────────────────┤
  │                                                    ┃
  │ IMPORTANT! Read the Wiki on Our Website.           ┃
  │                                                    ┃
  ├────────────────────────────────────────────────────┤
  │ Code For DC Motor by Make-IT-Move Hat By Jumplabs  ┃
  │ Make-IT-Move provide hassle free development of    ┃
  │ robotics and Motor Driving Devices                 ┃
  │ Make-IT-Move HAT is compatible with Raspberry pi,  ┃
  │ Arduino, Esp32, Esp8266 development Boards.        ┃
  │ Make-IT-Move can be easily integrate with other    ┃
  │ Microcontroller as well. Contact us for support    ┃
  ├──────────────────────────┬─────────────────────────┤
  │ Version: 0.0.2 - ALPHA        Date: 09.May.2023    ┃
  ├──────────────────────────┴─────────────────────────┤
  │ - compatible with Arduino, ESP8266 Currently       ┃
  │ - Not compatible  ESP32 right now                  ┃
  └────────────────────────────────────────────────────┘
*/


// Please configure the pins in CONFIG.h File

Left_M1 leftMotor_front;  
Left_M2 leftMotor_back;

Right_M1 rightMotor_front;
Right_M2 rightMotor_back;


// Left Motors
void left_front_motor_test(){
    Serial.println("\t\t MIM : Testing left front Motor");
    leftMotor_front.forward();
    leftMotor_front.backward();
    Serial.println("MIM : Reducing left front Motor Speed");
    leftMotor_front.setSpeed(127);
    leftMotor_front.forward();
    leftMotor_front.backward();
    leftMotor_front.stop();
    Serial.println("\t\t MIM : Testing Completed\n");
}
void left_back_motor_test(){
    Serial.println("\t\t MIM : Testing left back Motor");
    leftMotor_back.forward();
    leftMotor_back.backward();
    Serial.println("MIM : Reducing left back Motor Speed");
    leftMotor_back.setSpeed(127);
    leftMotor_back.forward();
    leftMotor_back.backward();
    leftMotor_back.stop();
    Serial.println("\t\t MIM : Testing Completed\n");
}

// Right Motors
void right_front_motor_test(){
    Serial.println("\t\t MIM : Testing right front Motor");
    rightMotor_front.forward();
    rightMotor_front.backward();
    Serial.println("MIM : Reducing right front Motor Speed");
    rightMotor_front.setSpeed(127);
    rightMotor_front.forward();
    rightMotor_front.backward();
    rightMotor_front.stop();
    Serial.println("\t\t MIM : Testing Completed\n");
}
void right_back_motor_test(){
    Serial.println("\t\t MIM : Testing right back Motor");
    rightMotor_back.forward();
    rightMotor_back.backward();
    Serial.println("MIM : Reducing right back Motor Speed");
    rightMotor_back.setSpeed(127);
    rightMotor_back.forward();
    rightMotor_back.backward();
    rightMotor_back.stop();
    Serial.println("\t\t MIM : Testing Completed\n");
}
void setup() {
    Serial.begin(115200);
    delay(2000);
    Serial.println("MIM : Testing DC Geared Motor");

    left_front_motor_test();    delay(2000);
    left_back_motor_test();     delay(2000);
    right_front_motor_test();   delay(2000);
    right_back_motor_test();    delay(2000);
    
    Serial.println("MIM : Testing Completed for all motors ");
    
}

void loop() {

}
