#include <Arduino.h>
#include "../CONFIG.h"

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


class DCMotor {
  public:
    DCMotor(int pin1, int pin2){  // constructor taking Pin no as input
        _pin1 = pin1;
        _pin2 = pin2;
        pinMode(_pin1, OUTPUT);
        pinMode(_pin2, OUTPUT);
    }
    void setSpeed(int speed){  // sets the PWM Value
        _speed = speed;
        if (DEBUG_DCMOTOR){
            Serial.print(" MIM : Speed Updated : ");
            Serial.print(_speed);
            Serial.print(" PWM");
        }
    }
    void forward(){ 
        analogWrite(_pin1, _speed);  //  FORWARD Pin HIGH
        analogWrite(_pin2, LOW);     //  BACKWARD PIN LOW
        if (DEBUG_DCMOTOR){
            Serial.print("MIM : Moving Forward with Speed : ");
            Serial.print(_speed);
            Serial.print(" PWM");
        }
    }
    void backward(){     
        analogWrite(_pin1, LOW);      //  FORWARD Pin LOW  
        analogWrite(_pin2, _speed);  //  BACKWARD PIN HIGH
        if (DEBUG_DCMOTOR){
            Serial.print("MIM : Moving Backward with Speed : ");
            Serial.print(_speed);
            Serial.print(" PWM");
        }
    }
    void stop(){
        analogWrite(_pin1, LOW);
        analogWrite(_pin2, LOW);
        if (DEBUG_DCMOTOR){
            Serial.print("MIM : Moving STOPPED ");
        }
    }
  private:
    int _speed = 255 ; // default is max speed
    int _pin1;
    int _pin2;
};

class Left_M1 : public DCMotor {
  public:
    Left_M1(): DCMotor(M1_A, M1_B) {}    
};
class Left_M2 : public DCMotor {
  public:
    Left_M2(): DCMotor(M2_A, M2_B) {}  
};

class Right_M1 : public DCMotor {
  public:
    Right_M1(): DCMotor(M3_A, M3_B) {}  
};
class Right_M2 : public DCMotor {
  public:
    Right_M2(): DCMotor(M4_A, M4_B) {}  
};
