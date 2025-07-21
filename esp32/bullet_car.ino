/*
   -- control --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.13 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.15.01 or later version;
     - for iOS 1.12.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE

#include <BLEDevice.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "bullet_car"
#define REMOTEXY_ACCESS_PASSWORD "1234"

const int motor1Pin1 = 13;  // L298N IN1
const int motor1Pin2 = 12;  // L298N IN2
const int motor2Pin1 = 14;  // L298N IN1
const int motor2Pin2 = 27;  // L298N IN2


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 78 bytes
  { 255,4,0,0,0,71,0,19,0,0,0,99,111,110,116,114,111,108,0,31,
  1,106,200,1,1,4,0,1,39,35,24,24,0,2,31,85,80,0,1,40,
  76,24,24,0,2,31,68,79,87,78,0,1,11,55,24,24,0,2,31,76,
  69,70,84,0,1,68,56,24,24,0,2,31,82,73,71,72,84,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t up; // =1 if button pressed, else =0
  uint8_t down; // =1 if button pressed, else =0
  uint8_t left; // =1 if button pressed, else =0
  uint8_t right; // =1 if button pressed, else =0

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)

void setup() {
  RemoteXY_Init (); 
  // put your setup code here, to run once:
  //setup pin mode
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  Serial.begin(115200);
  Serial.println("Hello world!");
}

void loop() {
  RemoteXY_Handler ();
  // put your main code here, to run repeatedly:
  if (RemoteXY.up)
  {
    Serial.println("up!");
    // motor forward rotation
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
  }
  else if (RemoteXY.down)
  {
    Serial.println("down!");
    // motor backward rotation
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
  }
  else if (RemoteXY.left)
  {
    Serial.println("left!");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
  }
  else if (RemoteXY.right)
  {
    Serial.println("right!");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
  }
  else
  {
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);   
  }
}
