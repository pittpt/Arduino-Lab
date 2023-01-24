#include <M5Stack.h>

#define TFT_GREY 0x5AEB

uint32_t targetTime = 0;
static uint8_t conv2d(const char* p); 
uint8_t hh = conv2d(__TIME__), mm = conv2d(__TIME__ + 3);
uint8_t ss = conv2d(__TIME__ + 6); 
byte omm = 99, oss = 99;
byte xcolon = 0, xsecs = 0;
unsigned int colour = 0;

void setup() {
 //Serial.begin(115200);
 M5.begin();
 // M5.Lcd.setRotation(1);
 M5.Lcd.fillScreen(TFT_BLACK);
 M5.Lcd.setTextSize(1);
 M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
 targetTime = millis() + 1000;
}

void loop() {
 if (targetTime < millis()) {
   targetTime = millis() + 1000;
   ss++; 

  if (ss == 60) {
     ss = 0; 
     omm = mm; 
     mm++; 
        if (mm > 59) { 
        mm = 0;
        hh++; 
          if (hh > 23) { 
            hh = 0; 
           }
      }
 }
 
 int xpos = 0;
 int ypos = 85; 
 int ysecs = ypos + 24;
 
 if (omm != mm) { 
    omm = mm;
 
   if (hh < 10) xpos += M5.Lcd.drawChar('0', xpos, ypos, 8);
     xpos += M5.Lcd.drawNumber(hh, xpos, ypos, 8); // Draw hours
     xcolon = xpos; // Save colon coord for later to flash on/off later
     xpos += M5.Lcd.drawChar(':', xpos, ypos - 8, 8);
 // Add minutes leading zero
       if (mm < 10) xpos += M5.Lcd.drawChar('0', xpos, ypos, 8);
     xpos += M5.Lcd.drawNumber(mm, xpos, ypos, 8); // Draw minutes
    xsecs = xpos; // Save seconds 'x' position for later display updates
 }

 if (oss != ss) { // Redraw seconds time every second
  oss = ss;
  xpos = xsecs;
    if (ss % 2) { // Flash the colons on/off
 // Set colour to grey to dim colon
      M5.Lcd.setTextColor(0x39C4, TFT_BLACK);
      M5.Lcd.drawChar(':', xcolon, ypos - 8, 8); // Hour:minute colon
      xpos += M5.Lcd.drawChar(':', xsecs, ysecs, 6); // Seconds colon
 // Set colour back to yellow
      M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
   }
    else {
      M5.Lcd.drawChar(':', xcolon, ypos - 8, 8); // Hour:minute colon
      xpos += M5.Lcd.drawChar(':', xsecs, ysecs, 6); // Seconds colon
    }
 //Draw seconds
 // Add leading zero
    if (ss < 10) xpos += M5.Lcd.drawChar('0', xpos, ysecs, 6);
      M5.Lcd.drawNumber(ss, xpos, ysecs, 6); // Draw seconds
    }
 }
}

static uint8_t conv2d(const char* p) {
 uint8_t v = 0;
 if ('0' <= *p && *p <= '9')
 v = *p - '0';
 return 10 * v + *++p - '0';
}
