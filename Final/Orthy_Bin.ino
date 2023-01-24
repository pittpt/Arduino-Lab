/*
 * made by technvation
 * uses open source blynk app to send data over the interent
 * This example code is in public domain.
 * feel free to modify, change, improve
 */
#define BLYNK_PRINT Serial
#include <Ultrasonic.h>

#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleMKR1000.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "jyyM2Ujcc71ECT47t-OooQ8f8WQrvpRF";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "PT";
char pass[] = "123456788";

BlynkTimer timer;
int distance = 0;
int thresh[3] = {25, 50, 75};
Ultrasonic ultrasonic(12, 13);

WidgetLED green(V1);
WidgetLED orange(V2);
WidgetLED red(V3);



void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
}

void loop()
{
  distance = ultrasonic.distanceRead();
  Serial.println(distance);
  Blynk.run();

  if(distance<thresh[0]){
    green.on();
    }
  else if(distance<thresh[1])
    green.on();
    orange.on();
  }
  else if(distance<thresh[2])
    green.on();
    orange.on();
    red.on();
  }
  else{
    green.off();
    orange.off();
    red.off();
  delay(100);
}
