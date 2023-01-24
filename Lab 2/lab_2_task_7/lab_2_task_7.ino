#include <M5Stack.h>

void setup() {
      Serial.begin(9600);

}

void loop() {
  
    if (Serial.available()>0) {
      int key = Serial.read();
      if (key == 33){
        Serial.println("Pitt Pongpittayapa");
        Serial.println("6338158421");
      }
     
    }
    
  M5.update();

}
