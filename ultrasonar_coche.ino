#include <LiquidCrystal.h> //Please replace the single quote characters ('') with the parenthesis character (<>)
#include "pitches.h"

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); //RS, E, DB4, DB5, DB6, DB7

//Ultrasonar
const int trig = 9;
const int echo = 10;
long duration;
int distance;
//Buzz
int buzz = 11; //define BUZZ port
int melody[] = {NOTE_G5, NOTE_A5}; // Notes I like
int duration_buzz = 500; 

void setup() {
  
lcd.begin(16,2); // LCD screen dimensions
pinMode(trig, OUTPUT); //Ultrasonar
pinMode(echo, INPUT); //Ultrasonar
pinMode(buzz, OUTPUT);  //Buzz

}

void loop() {
  
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(8);
digitalWrite(trig, LOW);

// distance calculation
duration = pulseIn(echo, HIGH);
distance= duration*0.034/2;

// Prints value in LCD
lcd.setCursor(0,0); 
lcd.print("Distance: ");
lcd.print(distance); 
lcd.print("  cm");


if (distance<=13 && distance>8){
    digitalWrite(buzz, HIGH);
    tone(11, NOTE_A5, duration_buzz);
    delay(500);
    tone(11, NOTE_A5, duration_buzz);
    delay(500);
    tone(11, NOTE_A5, duration_buzz);
    delay(500);
  }
  
else if (distance<=8){
    digitalWrite(buzz, HIGH);
    tone(11, NOTE_G5, duration_buzz);
    delay(200);
  }
  else{
    digitalWrite(buzz, LOW);
  }
}
