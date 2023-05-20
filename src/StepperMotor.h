
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


class StepperMotor {
  public:
    // constructors

    StepperMotor(int pin1, int pin2, int steps){  // constructor taking Pins and steps/revolution as input
        
        const int dirPin = pin1;
        const int stepPin = pin2;
        const int stepsPerRevolution = steps;

        pinMode(dirPin, OUTPUT);
        pinMode(stepPin, OUTPUT);
        digitalWrite(dirPin, true);
    }

   
    void Run_one_round(){
        if (DEBUG_STEPPER){
            Serial.println("MIM : Stepper Revolving 1 round ");
        }
        Run_steps(stepsPerRevolution);
        
    }

    void Run_steps(unsigned long Step){
        if (DEBUG_STEPPER){
            Serial.print("MIM : Stepper Revolving  ");
            Serial.print(Step);
            Serial.print(" steps");
        }
        for(int x = 0; x < Step; x++)
        {
            step();
        }
    }
    void stop(){  // stops the stepper motor
        digitalWrite(stepPin, LOW);
        delayMicroseconds(delay_time_us);
        if (DEBUG_STEPPER){
            Serial.print("MIM : Stepper Stopped  ");
        }
    }
   
    void Set_direction(bool val){   // sets rotating direction
        digitalWrite(dirPin, val); // true for clockwise, false for anticlockwise
    }

    void set_Step_time(unsigned long time){ // set delay time between stepping
        delay_time_us= time;
        if (DEBUG_STEPPER){
            Serial.print("MIM : Stepper motor Delay Time Updated ");
        }
    }

  private:
    int dirPin ;
    int stepPin;
    int stepsPerRevolution = 200;
    unsigned long delay_time_us = 2000;  // Microsecond_time
    void step(){ // moves the stepper in 1 step

        digitalWrite(stepPin, HIGH);
        delayMicroseconds(delay_time_us);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(delay_time_us);
    }
};

class Stepper1 : public StepperMotor {
  public:
    Stepper1(): StepperMotor(Stepper_1_dir, Stepper_1_step , Stepper_1_steps ) {}
};

class Stepper2 : public StepperMotor {
  public:
    Stepper2(): StepperMotor(Stepper_2_dir ,Stepper_2_step ,Stepper_2_steps) {}  
};

class Stepper3 : public StepperMotor {
  public:
    Stepper3(): StepperMotor(Stepper_3_dir ,Stepper_3_step ,Stepper_3_steps) {}  
};
