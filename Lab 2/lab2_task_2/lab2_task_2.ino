#include <M5Stack.h>

void setup() {
M5.begin();
  Serial.begin(9600);
    Serial.println(" ");
M5.update();
}

int count = 0;
void loop() {
    
  if (M5.BtnA.wasPressed()) {
    count=count+1;
    Serial.print("click ");
    Serial.println(count);

  } 
  M5.update();
}
