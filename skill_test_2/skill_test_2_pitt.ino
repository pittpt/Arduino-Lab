#include <M5Stack.h>

void setup() {
   M5.begin();
   Serial.begin(9600);
   M5.Lcd.fillScreen(0);

}

void loop() {
  if(Serial.available()>0){
    char text = Serial.read();
    Serial.write(text);

   if(text > 47 && text < 58){
     M5.Lcd.fillScreen(0);
     M5.Lcd.drawCircle(160,120,100,RED);
     M5.Lcd.fillCircle(120,90,10,RED);
     M5.Lcd.fillCircle(200,90,10,RED);
     M5.Lcd.drawCircleHelper(160,185,55,3,RED);
    
   }

  else if(text >= 65 && text <= 90){
     M5.Lcd.fillScreen(0);
     M5.Lcd.drawCircle(160,120,100,GREEN);
     M5.Lcd.fillCircle(120,90,10,GREEN);
     M5.Lcd.fillCircle(200,90,10,GREEN);
     M5.Lcd.drawCircleHelper(160,120,70,12,GREEN);
  }
  else{
     M5.Lcd.fillScreen(0);
     M5.Lcd.drawCircle(160,120,100,BLUE);
     M5.Lcd.fillCircle(120,90,10,BLUE);
     M5.Lcd.fillCircle(200,90,10,BLUE);
     M5.Lcd.drawLine(110,160,210,160,BLUE);  
  }
    
  }
M5.update();
}
