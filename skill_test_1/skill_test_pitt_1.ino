#include <M5Stack.h>
int num = 0;

void setup() {
  
  M5.begin();
  M5.Lcd.setTextSize(20);
  M5.Lcd.setTextColor(WHITE);

}

void loop() {
  
  if(M5.BtnA.wasPressed()){
    num++;
    M5.Lcd.fillScreen(0);
  }
  if(M5.BtnB.wasPressed()){
    num--;
    M5.Lcd.fillScreen(0);
  }
  if(M5.BtnC.wasPressed()){
    num = 0;
    M5.Lcd.fillScreen(0);
  }
  if(num < 0){
    num = 0;
    M5.Lcd.fillScreen(0);
  }
  
  M5.Lcd.setCursor(140,100);
  M5.Lcd.print(num);
  
M5.update();

}
