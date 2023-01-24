#include<M5Stack.h>

const int C = 262;
const int D = 294;
const int E = 330;
const int F = 349;
const int G = 392;
const int A = 440;
const int B = 494;

int i = 0;
const int note[] = {
  E,E,E,E,E,E,E,G,C,D,E,F,F,F,F,F,E,E,E,D,D,E,D,G};

  
void setup() {
 M5.begin();
}

void loop() {

if(M5.BtnA.isPressed()){
   M5.Speaker.tone(note[i]);
   delay(100);
}

if(M5.BtnA.wasReleased()){
    i = i+1;
    M5.Speaker.mute();
}

if(i>23){
  i = 0;
}

M5.update();
}
