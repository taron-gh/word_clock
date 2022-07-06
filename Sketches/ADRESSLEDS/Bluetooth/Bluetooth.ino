#include <EEPROM.h>
#include <FastLED.h>
#define NUM_LEDS 38
#define DATA_PIN 3
int pakas;
CRGB leds[NUM_LEDS];
int redpin = 9;
int greenpin = 5;
int bluepin = 6;
int counter = 0;
int red;
int green;
int blue;
int brightness;
int brightnessflag = 0;
int seconds = 0;
int minutes;
int hours;
int day;
int redcolor;
int greencolor;
int bluecolor;
#include <DS3231.h>
DS3231  rtc(SDA, SCL);
Time  t;
void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  rtc.begin();
    
}


void loop() {  
  if(Serial.available() > 0){
    unsigned int firstnum = Serial.read();
    unsigned int secnum = Serial.read();
    unsigned int thnum = Serial.read();
    unsigned int frnum = Serial.read();
    long realnum = firstnum + (secnum * 256) + (thnum * (long)65536) + (frnum * (long) 16777216);
    if(1001001 <= realnum && realnum <= 256256256){
      float setred;
      float setblue;
      float setgreen;
      red = 0;
      green = 0;
      blue = 0;
      setred = round(realnum / 1000000);
      red = setred;
      setgreen = realnum - (red * 1000000);
      setgreen = round(setgreen / 1000);
      green = setgreen;
      setblue = realnum - (red * 1000000) - (green * 1000);
      blue = setblue;
      EEPROM.write(1, red);
      EEPROM.write(2, green);
      EEPROM.write(3, blue);
    }
    if(realnum == 400){
      hours = 0;
      minutes = 0;
      counter++;
      while(counter == 1){
        hours = Serial.read();
        Serial.flush();
        counter++;
        while(counter == 2){
          if(Serial.available() > 0){
            minutes = Serial.read();
            Serial.flush();
            rtc.setTime(hours, minutes, seconds);
            counter = 0;
          }
        }
      }
    } 
    if(realnum == 2010){
      day = 1;
    }
    if(realnum == 2020){
      day = 2;
    }
    if(realnum == 2030){
      day = 3;
    }
    if(realnum == 2040){
      day = 4;
    }
    if(realnum == 2050){
      day = 5;
    }
    if(realnum == 2060){
      day = 6;
    }
    if(realnum == 2070){
      day = 7;
    }
    if(realnum >= 6000 && realnum <= 6256){
      brightness = realnum - 6000;
      EEPROM.write(4, brightness);
      FastLED.setBrightness(brightness);
      FastLED.show();
      brightnessflag = 1;
      Serial.flush();        
    }

  }     
  redcolor = 255 - red;
  greencolor = 255 - green;
  bluecolor = 255 - blue;
  red = EEPROM.read(1);
  green = EEPROM.read(2);
  blue = EEPROM.read(3);
  brightness = EEPROM.read(4);
  analogWrite(redpin, redcolor);
  analogWrite(greenpin, greencolor);
  analogWrite(bluepin, bluecolor);
  Serial.println("Red: ");Serial.print(red);Serial.print(" ");Serial.println("Green: ");Serial.print(green);Serial.print(" ");Serial.println("Blue: ");Serial.print(blue);
  Serial.print("It is the ");
  Serial.print(day);
  Serial.print(". day of the week (counting monday as the 1th), and it has passed ");
  Serial.print(hours);
  Serial.print(" hour(s), ");
  Serial.print(minutes);
  Serial.print(" minute(s) and ");
  Serial.print(seconds);
  Serial.println(" second(s) since midnight.");
  t = rtc.getTime();
  if(day == 1){
    rtc.setDOW(MONDAY);    
  }
  else if(day == 2){
    rtc.setDOW(TUESDAY);
  }
  else if(day == 3){
    rtc.setDOW(WEDNESDAY);
  }
  else if(day == 4){
    rtc.setDOW(THURSDAY);
  }
  else if(day == 5){
    rtc.setDOW(FRIDAY);
  }
  else if(day == 6){
    rtc.setDOW(SATURDAY);
  }
  else if(day == 7){
    rtc.setDOW(SUNDAY);
  }
  leds[0] = CRGB(red, green, blue);
  leds[30] = CRGB(red, green, blue);
  if((t.hour == 1 || t.hour == 13) && t.min <= 30){
    leds[1] = CRGB(red, green, blue);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 1 || t.hour == 13)){
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);     
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(red, green, blue);
  }
  if((t.hour == 2 || t.hour == 14) && t.min <= 30){
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);      
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(red, green, blue);
  }
  else if(t.min >= 31 && (t.hour == 2 || t.hour == 14)){
    leds[1] = CRGB(0, 0, 0); 
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(red, green, blue);        
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  if((t.hour == 3 || t.hour == 15) && t.min <= 30){
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(red, green, blue);
    leds[4] = CRGB(0, 0, 0);    
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 3 || t.hour == 15)){
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(red, green, blue);   
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  if((t.hour == 4 || t.hour == 16) && t.min <= 30){
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0); 
    leds[4] = CRGB(red, green, blue);
    leds[5] = CRGB(0, 0, 0);       
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 4 || t.hour == 16)){
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(red, green, blue);     
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  if((t.hour == 5 || t.hour == 17) && t.min <= 30){
    leds[5] = CRGB(red, green, blue);
    leds[6] = CRGB(0, 0, 0);
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 5 || t.hour == 17)){
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(red, green, blue); 
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  if((t.hour == 6 || t.hour == 18) && t.min <= 30){
    leds[6] = CRGB(red, green, blue);
    leds[7] = CRGB(0, 0, 0);
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 6 || t.hour == 18)){
    leds[6] = CRGB(0, 0, 0); 
    leds[7] = CRGB(red, green, blue);
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  if((t.hour == 7 || t.hour == 19) && t.min <= 30){
    leds[7] = CRGB(red, green, blue);
    leds[8] = CRGB(0, 0, 0);
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 7 || t.hour == 19)){
    leds[7] = CRGB(0, 0, 0); 
    leds[8] = CRGB(red, green, blue);
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  if((t.hour == 8 || t.hour == 20) && t.min <= 30){
    leds[8] = CRGB(red, green, blue);
    leds[9] = CRGB(0, 0, 0);
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 8 || t.hour == 20)){
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(red, green, blue); 
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  if((t.hour == 9 || t.hour == 21) && t.min <= 30){
    leds[9] = CRGB(red, green, blue);
    leds[10] = CRGB(0, 0, 0);
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 9 || t.hour == 21)){
    leds[9] = CRGB(0, 0, 0); 
    leds[10] = CRGB(red, green, blue);
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  if((t.hour == 10 || t.hour == 22) && t.min <= 30){
    leds[10] = CRGB(red, green, blue);
    leds[11] = CRGB(0, 0, 0);
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 10 || t.hour == 22)){
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(red, green, blue); 
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  if((t.hour == 11 || t.hour == 23) && t.min <= 30){
    leds[11] = CRGB(red, green, blue);
    leds[12] = CRGB(0, 0, 0);
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 11 || t.hour == 23)){
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(red, green, blue); 
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[13] = CRGB(red, green, blue);
  }
  if((t.hour == 12 || t.hour == 0) && t.min <= 30){
    leds[12] = CRGB(red, green, blue);
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[13] = CRGB(red, green, blue);
    
  }
  else if(t.min >= 31 && (t.hour == 12 || t.hour == 0)){
    leds[12] = CRGB(0, 0, 0); 
    leds[1] = CRGB(red, green, blue);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[13] = CRGB(0, 0, 0);
  }

  
  if(t.min >= 31){
    leds[14] = CRGB(red, green, blue);
    leds[15] = CRGB(0, 0, 0);
    leds[16] = CRGB(0, 0, 0);
  }
  else if(t.min <= 30 && t.min != 0){
    leds[15] = CRGB(red, green, blue);
    leds[16] = CRGB(red, green, blue);
    leds[14] = CRGB(0, 0, 0);
  }
  else if(t.min == 0){
    leds[15] = CRGB(red, green, blue);
    leds[16] = CRGB(0, 0, 0);
    leds[14] = CRGB(0, 0, 0);
  }

  
  if(t.min < 10){
    leds[17] = CRGB(0, 0, 0);
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
  }
  else if(t.min >= 10 && t.min < 20){
    leds[17] = CRGB(red, green, blue);
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
  }
  else if(t.min >= 20 && t.min < 30){
    leds[17] = CRGB(0, 0, 0);
    leds[18] = CRGB(red, green, blue);
    leds[19] = CRGB(0, 0, 0);
  }
  else if(t.min == 30){
    leds[17] = CRGB(0, 0, 0);
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(red, green, blue);
  }
  else if(t.min >= 31 && t.min <= 40){
    leds[17] = CRGB(0, 0, 0);
    leds[18] = CRGB(red, green, blue);
    leds[19] = CRGB(0, 0, 0);
  }
  else if(t.min >= 41 && t.min <= 50){
    leds[17] = CRGB(red, green, blue);
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
  }
  else if(t.min > 50){
    leds[17] = CRGB(0, 0, 0);
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
  }


  if(t.min <= 29 && (t.min == 1 || t.min == 11 || t.min == 21)){
    leds[20] = CRGB(red, green, blue);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 2 || t.min == 12 || t.min == 22)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(red, green, blue);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 3 || t.min == 13 || t.min == 23)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(red, green, blue);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 4 || t.min == 14 || t.min == 24)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(red, green, blue);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 5 || t.min == 15 || t.min == 25)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(red, green, blue);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 6 || t.min == 16 || t.min == 26)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(red, green, blue);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 7 || t.min == 17 || t.min == 27)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(red, green, blue);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 8 || t.min == 18 || t.min == 28)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(red, green, blue);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 9 || t.min == 19 || t.min == 29)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(red, green, blue);
  }
  if(t.min == 0 || t.min == 10 || t.min == 20 || t.min == 30 || t.min == 40 || t.min == 50){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min >= 31){
    pakas = 60 - t.min;
  }
  if(t.min >= 31 && (pakas == 1 || pakas == 11 || pakas == 21)){
    leds[20] = CRGB(red, green, blue);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 2 || pakas == 12 || pakas == 22)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(red, green, blue);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 3 || pakas == 13 || pakas == 23)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(red, green, blue);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 4 || pakas == 14 || pakas == 24)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(red, green, blue);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 5 || pakas == 15 || pakas == 25)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(red, green, blue);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 6 || pakas == 16 || pakas == 26)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(red, green, blue);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 7 || pakas == 17 || pakas == 27)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(red, green, blue);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 8 || pakas == 18 || pakas == 28)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(red, green, blue);
    leds[28] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 9 || pakas == 19 || pakas == 29)){
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
    leds[27] = CRGB(0, 0, 0);
    leds[28] = CRGB(red, green, blue);
  }
  if(t.min >= 31){
    leds[29] = CRGB(red, green, blue);
  }
  else{
    leds[29] = CRGB(0, 0, 0);
  }

  
  if(t.dow == 1){
    leds[31] = CRGB(red, green, blue);
    leds[32] = CRGB(0, 0, 0);
    leds[33] = CRGB(0, 0, 0);
    leds[34] = CRGB(0, 0, 0);
    leds[35] = CRGB(0, 0, 0);
    leds[36] = CRGB(0, 0, 0);
    leds[37] = CRGB(0, 0, 0);
  }
  else if(t.dow == 2){
    leds[31] = CRGB(0, 0, 0);
    leds[32] = CRGB(red, green, blue);
    leds[33] = CRGB(0, 0, 0);
    leds[34] = CRGB(0, 0, 0);
    leds[35] = CRGB(0, 0, 0);
    leds[36] = CRGB(0, 0, 0);
    leds[37] = CRGB(0, 0, 0);
  }
  else if(t.dow == 3){
    leds[31] = CRGB(0, 0, 0);
    leds[32] = CRGB(0, 0, 0);
    leds[33] = CRGB(red, green, blue);
    leds[34] = CRGB(0, 0, 0);
    leds[35] = CRGB(0, 0, 0);
    leds[36] = CRGB(0, 0, 0);
    leds[37] = CRGB(0, 0, 0);
  }
  else if(t.dow == 4){
    leds[31] = CRGB(0, 0, 0);
    leds[32] = CRGB(0, 0, 0);
    leds[33] = CRGB(0, 0, 0);
    leds[34] = CRGB(red, green, blue);
    leds[35] = CRGB(0, 0, 0);
    leds[36] = CRGB(0, 0, 0);
    leds[37] = CRGB(0, 0, 0);
  }
  else if(t.dow == 5){
    leds[31] = CRGB(0, 0, 0);
    leds[32] = CRGB(0, 0, 0);
    leds[33] = CRGB(0, 0, 0);
    leds[34] = CRGB(0, 0, 0);
    leds[35] = CRGB(red, green, blue);
    leds[36] = CRGB(0, 0, 0);
    leds[37] = CRGB(0, 0, 0);
  }
  else if(t.dow == 6){
    leds[31] = CRGB(0, 0, 0);
    leds[32] = CRGB(0, 0, 0);
    leds[33] = CRGB(0, 0, 0);
    leds[34] = CRGB(0, 0, 0);
    leds[35] = CRGB(0, 0, 0);
    leds[36] = CRGB(red, green, blue);
    leds[37] = CRGB(0, 0, 0);
  }
  else if(t.dow == 7){
    leds[31] = CRGB(0, 0, 0);
    leds[32] = CRGB(0, 0, 0);
    leds[33] = CRGB(0, 0, 0);
    leds[34] = CRGB(0, 0, 0);
    leds[35] = CRGB(0, 0, 0);
    leds[36] = CRGB(0, 0, 0);
    leds[37] = CRGB(red, green, blue);
  }
  FastLED.show();
}
