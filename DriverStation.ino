#include"Joystick.h"
#include <Wire.h>
int ledt = 5;
int r = 0;
int Led1 = 0;
int Led2 = 255;
int Led3 = 255;
int Led4 = 255;
int Led5 = 0;
int Led6 = 255;
int bs = 0;
int os = 1;
int button_mode = 1;
int button_mode2 = 1;
int button_mode3 = 1;
int button_mode_low_bar = 1;
int Range = 4;
int fjoy = 127;
//int joy1 = A0;
//int joy2 = A1;
void setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
//  pinMode(A0, OUTPUT);
  Joystick.begin();
  Serial.begin(9600);
}
  const int pinToButtonMap = 0;
  int lastButtonState[10] = {0,0,0,0,0,0,0,0,0,0};
  
void loop() {
//  joy1 = analogRead(A0);
//  joy2 = analogRead(A1);

  

//  bs = digitalRead(7);
//  if(digitalRead(6) == HIGH && button_mode == 1){
//  Led1 = 255;
//    button_mode = 0;
///  }else if ((digitalRead(6) == LOW) && (button_mode == 0)) {
//    Led1 = 0;
//    button_mode = 1;
//  }

  analogWrite(A0, Led1);
  analogWrite(A1, Led2);
  analogWrite(A2, Led3);
  analogWrite(A3, Led4);
  analogWrite(A4, Led5);
  analogWrite(A5, Led6);



  
  r = r + ledt;
  if (r == 0 || r == 255) {
    ledt = -ledt ;

  int currentButtonStates[10];

  for (int index = 0; index < 10; index++)//set to as meny buttons as you have
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
    currentButtonStates[index] = currentButtonState;
  }

  
//  Joystick.setYAxis(-(joy1/Range)-fjoy);
//  Joystick.setXAxis(-(joy1/Range)-fjoy);
  Joystick.sendState();


  if(currentButtonStates[7]){
    if(button_mode == 1) {
     if(Led4 == 255) {
      Led4 = 0;
      Led5 = 255;
     }else{
      Led4 = 255;
      Led5 = 0;
     }
     button_mode = 0;
    }
  }else{
    button_mode = 1;
  }

  if(currentButtonStates[2]){
    if(button_mode2 == 1) {
     if(Led6 == 255) {
      Led1 = 255;
      Led6 = 0;
     }else{
      Led1 = 0;
      Led6 = 255;
     }
     button_mode2 = 0;
    }
  }else{
    button_mode2 = 1;
  }
  if (currentButtonStates[9]){
    if(button_mode3 == 1){
      if(Led6 == 255){
        Led6 = 0;
        Led1 = 255;
      }
    }
  }
  if (currentButtonStates[9]){
    if(button_mode3 == 1){
      if(Led4 == 255){
        Led4 = 0;
        Led5 = 255;
      }
    }
  }

//  if (currentButtonStates[10]){
//    if(button_mode_low_bar == 1) {
//     Led1 = 0;
//    }
//    button_mode_low_bar = 0;
//    Serial.println("low");
//  }else{
//    button_mode_low_bar = 1;
//    Serial.println("high");
//  }
  
  delay(5);
}
}
