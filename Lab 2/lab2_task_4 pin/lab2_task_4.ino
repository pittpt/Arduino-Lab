#include <M5Stack.h>

int ledPin = 21;
int ledState = LOW;
int readData = 0;

void setup(){
  M5.begin();
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  M5.update();
  Serial.println("Enter a number to light up the LED");
}

void loop() {
    if (Serial.available()>0){
     readData = Serial.read();
     Serial.print("Enter number");
       if (readData >=48 && readData <= 57){
    digitalWrite(21, HIGH);
       }
     else {
     digitalWrite(ledPin,LOW);
       }
       
    }

    M5.update();
  }
 
  
