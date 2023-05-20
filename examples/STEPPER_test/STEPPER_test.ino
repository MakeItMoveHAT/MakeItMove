
#include <StepperMotor.h>
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

Stepper1 Stepper_1;  
Stepper2 Stepper_2;
Stepper3 Stepper_3;

// Steper 1
void Stepper_1_test(){
    Serial.println("\t\t MIM : Testing Stepper Motor 1");
    
    Stepper_1.Run_one_round();    delay(2000); // slowly
    
    // Increasing Stepper Speed 
    Stepper_1.set_Step_time(1000); // Time between each steps. default is 2000 
    Stepper_1.Run_one_round();    
    
    delay(2000); // Fast

    // change direction
    Stepper_1.Set_direction(false);  //   default is true
    Stepper_1.Run_steps(5000); // stepper runs this much stepps
    
    delay(2000);    
    
    Serial.println("\t\t MIM : Testing Completed for stepper 1\n");
}

// Steper 2
void Stepper_2_test(){
    Serial.println("\t\t MIM : Testing Stepper Motor 2");
    
    Stepper_2.Run_one_round();    delay(2000); // slowly
    
    // Increasing Stepper Speed 
    Stepper_2.set_Step_time(1000); // Time between each steps. default is 2000 
    Stepper_2.Run_one_round();    
    
    delay(2000); // Fast

    // change direction
    Stepper_2.Set_direction(false);  //   default is true
    Stepper_2.Run_steps(5000); // stepper runs this much stepps
    
    delay(2000);    
    
    Serial.println("\t\t MIM : Testing Completed for stepper 2\n");
}
// Steper 3
void Stepper_3_test(){
    Serial.println("\t\t MIM : Testing Stepper Motor 3");
    
    Stepper_3.Run_one_round();    delay(2000); // slowly
    
    // Increasing Stepper Speed 
    Stepper_3.set_Step_time(1000); // Time between each steps. default is 2000 
    Stepper_3.Run_one_round();    
    
    delay(2000); // Fast

    // change direction
    Stepper_3.Set_direction(false);  //   default is true
    Stepper_3.Run_steps(5000); // stepper runs this much stepps
    
    delay(2000);    
    
    Serial.println("\t\t MIM : Testing Completed fro stepper 3\n");
}

void setup() {
    Serial.begin(115200);
    delay(2000);
    Serial.println("MIM : Testing Stepper Motors ");

    Stepper_1_test();    delay(2000);
    Stepper_2_test();    delay(2000);
    Stepper_3_test();    delay(2000);
    
    Serial.println("MIM : Testing Completed for all motors");
    
}

void loop() {

}
