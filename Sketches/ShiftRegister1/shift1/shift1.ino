#include <DS3231.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

// Init a Time-data structure
Time  t;
int SER1 = 11;
int LATCH1 = 12;
int CLK1 = 13;
int num1;
int SER2 = 8;
int LATCH2 = 9;
int CLK2 = 10;
int num2;
int SER3 = 2;
int LATCH3 = 3;
int CLK3 = 4;
int num3;
int SER4 = 5;
int LATCH4 = 6;
int CLK4 = 7;
int num4;
void setup() {
  Serial.begin(9600);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  pinMode(LATCH1, OUTPUT);
  pinMode(SER1, OUTPUT);
  pinMode(CLK1, OUTPUT);
  // Initialize the rtc object
  rtc.begin();
  rtc.setTime(17, 31, 0);
}

void loop() {
  t = rtc.getTime();
  if(t.hour == 1 || t.hour == 13){
    num1 = 128 + 64 + 32;
    if(t.min >= 31){
      num1 = num1 + 1;
    }
    digitalWrite(LATCH1, LOW);
    shiftOut(SER1, CLK1, LSBFIRST, num1);
    digitalWrite(LATCH1, HIGH);
  }
  if(t.hour == 2 || t.hour == 14){
    num1 = 128 + 64 + 16;
    if(t.min >= 31){
      num1 = num1 + 1;
    }
    digitalWrite(LATCH1, LOW);
    shiftOut(SER1, CLK1, LSBFIRST, num1);
    digitalWrite(LATCH1, HIGH);
  }
  if(t.hour == 3 || t.hour == 15){
    num1 = 128 + 64 + 8;
    if(t.min >= 31){
      num1 = num1 + 1;
    }
    digitalWrite(LATCH1, LOW);
    shiftOut(SER1, CLK1, LSBFIRST, num1);
    digitalWrite(LATCH1, HIGH);
  }
  if(t.hour == 4 || t.hour == 16){
    num1 = 128 + 64 + 4;
    if(t.min >= 31){
      num1 = num1 + 1;
    }
    digitalWrite(LATCH1, LOW);
    shiftOut(SER1, CLK1, LSBFIRST, num1);
    digitalWrite(LATCH1, HIGH);
  }
  if(t.hour == 5 || t.hour == 17){
    num1 = 128 + 64 + 2;
    if(t.min >= 31){
      num1 = num1 + 1;
    }
    digitalWrite(LATCH1, LOW);
    shiftOut(SER1, CLK1, LSBFIRST, num1);
    digitalWrite(LATCH1, HIGH);
  }
}
