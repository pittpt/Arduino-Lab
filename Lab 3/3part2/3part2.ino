#include<M5Stack.h>

const int C = 262;
const int D = 294;
const int E = 330;
const int F = 349;
const int G = 392;
const int A = 440;
const int B = 494;
const int C5 = 524;
const int D5 = 588;


const int note[] = {
 D5,C5,D5,F,C5,A,A,A};
const int duration[] = {
  4,4,4,4,4,4,4,1};
  
void setup() {
  M5.begin();
}



void loop() {
  for (int i=0;i<8;i++){
    int wait = 1000/duration[i];
    M5.Speaker.tone(note[i]);
    delay(wait);
    M5.Speaker.mute();
    delay(50);
  }
  M5.Speaker.mute();
  delay(2000);
  M5.update();

}
