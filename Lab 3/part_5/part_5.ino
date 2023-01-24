#include<M5Stack.h>

const int Bl = 247;
const int C = 262;
const int D = 294;
const int E = 330;
const int F = 349;
const int Fs = 370;
const int G = 392;
const int Gs = 415;
const int A = 440;
const int B = 494;

int i = 6;
const int note[] = {
  Fs,Fs,D,Bl,Bl,E,E,E,Gs,Gs,A,B,A,A,A,E,D,Fs,Fs,Fs,E,E,Fs,E};
const int duration[] = {
  6,6,5,3,3,3,3,7,6,6,6,6,6,6,6,3,3,3,3,7,6,6,6,6};
  
void setup() {
 M5.begin();
}

int sp = 1;
void loop() {
    
if(M5.BtnA.wasPressed()) {
    sp = sp*2;
    for (int i=0;i<24;i++){
    
    int wait = 1000/duration[i]/sp;
    M5.Speaker.tone(note[i]);
    delay(wait);
    M5.Speaker.mute();
    delay(50);
    }

  
  }

 if(M5.BtnB.wasPressed()) {
    sp = sp/2;
    for (int i=0;i<24;i++){
    
    int wait = 1000/duration[i]/sp;
    M5.Speaker.tone(note[i]);
    delay(wait);
    M5.Speaker.mute();
    delay(50);
    }

  
  }
  
if(M5.BtnC.wasPressed()) {
    for (int i=0;i<24;i++){
    
    int wait = 1000/duration[i];
    M5.Speaker.tone(note[i]);
    delay(wait);
    M5.Speaker.mute();
    delay(50);
    }

  
  }
 M5.Speaker.mute();
 M5.update();
}
