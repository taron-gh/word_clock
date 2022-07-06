#include <FastLED.h>
#include <DS3231.h>

#define NUM_LEDS 36
#define DATA_PIN 3
#define color 0x336699

int pakas;

DS3231  rtc(SDA, SCL);
CRGB leds[NUM_LEDS];
Time  t;
void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  rtc.begin();
  rtc.setTime(15, 55, 35);
  rtc.setDOW(WEDNESDAY);

}

void loop() {

  t = rtc.getTime();
  FastLED.setBrightness(30);
  leds[0] = CRGB(color);
  leds[28] = CRGB(color);
  if((t.hour == 1 || t.hour == 13) && t.min <= 30){
    leds[1] = CRGB(color);
    leds[2] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 1 || t.hour == 13)){
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(color); 
  }
  if((t.hour == 2 || t.hour == 14) && t.min <= 30){
    leds[2] = CRGB(color);
    leds[3] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 2 || t.hour == 14)){
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(color); 
  }
  if((t.hour == 3 || t.hour == 15) && t.min <= 30){
    leds[3] = CRGB(color);
    leds[4] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 3 || t.hour == 15)){
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(color); 
  }
  if((t.hour == 4 || t.hour == 16) && t.min <= 30){
    leds[4] = CRGB(color);
    leds[5] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 4 || t.hour == 16)){
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(color); 
  }
  if((t.hour == 5 || t.hour == 17) && t.min <= 30){
    leds[5] = CRGB(color);
    leds[6] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 5 || t.hour == 17)){
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(color); 
  }
  if((t.hour == 6 || t.hour == 18) && t.min <= 30){
    leds[6] = CRGB(color);
    leds[7] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 6 || t.hour == 18)){
    leds[6] = CRGB(0, 0, 0); 
    leds[7] = CRGB(color);
  }
  if((t.hour == 7 || t.hour == 19) && t.min <= 30){
    leds[7] = CRGB(color);
    leds[8] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 7 || t.hour == 19)){
    leds[7] = CRGB(0, 0, 0); 
    leds[8] = CRGB(color);
  }
  if((t.hour == 8 || t.hour == 20) && t.min <= 30){
    leds[8] = CRGB(color);
    leds[9] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 8 || t.hour == 20)){
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(color); 
  }
  if((t.hour == 9 || t.hour == 21) && t.min <= 30){
    leds[9] = CRGB(color);
    leds[10] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 9 || t.hour == 21)){
    leds[9] = CRGB(0, 0, 0); 
    leds[10] = CRGB(color);
  }
  if((t.hour == 10 || t.hour == 22) && t.min <= 30){
    leds[10] = CRGB(color);
    leds[11] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 10 || t.hour == 22)){
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(color); 
  }
  if((t.hour == 11 || t.hour == 23) && t.min <= 30){
    leds[11] = CRGB(color);
    leds[12] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 11 || t.hour == 23)){
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(color); 
  }
  if((t.hour == 12 || t.hour == 0) && t.min <= 30){
    leds[12] = CRGB(color);
    leds[1] = CRGB(0, 0, 0);
  }
  else if(t.min >= 31 && (t.hour == 12 || t.hour == 0)){
    leds[12] = CRGB(0, 0, 0); 
    leds[1] = CRGB(color);
  }

  
  if(t.min >= 31){
    leds[13] = CRGB(color);
    leds[14] = CRGB(0, 0, 0);
  }
  else if(t.min <= 30){
    leds[14] = CRGB(color);
    leds[13] = CRGB(0, 0, 0);
  }

  
  if(t.min < 10){
    leds[15] = CRGB(0, 0, 0);
    leds[16] = CRGB(0, 0, 0);
    leds[17] = CRGB(0, 0, 0);
  }
  else if(t.min >= 10 && t.min < 20){
    leds[15] = CRGB(color);
    leds[16] = CRGB(0, 0, 0);
    leds[17] = CRGB(0, 0, 0);
  }
  else if(t.min >= 20 && t.min < 30){
    leds[15] = CRGB(0, 0, 0);
    leds[16] = CRGB(color);
    leds[17] = CRGB(0, 0, 0);
  }
  else if(t.min == 30){
    leds[15] = CRGB(0, 0, 0);
    leds[16] = CRGB(0, 0, 0);
    leds[17] = CRGB(color);
  }
  else if(t.min >= 31 && t.min <= 40){
    leds[15] = CRGB(0, 0, 0);
    leds[16] = CRGB(color);
    leds[17] = CRGB(0, 0, 0);
  }
  else if(t.min >= 41 && t.min <= 50){
    leds[15] = CRGB(color);
    leds[16] = CRGB(0, 0, 0);
    leds[17] = CRGB(0, 0, 0);
  }
  else if(t.min > 50){
    leds[15] = CRGB(0, 0, 0);
    leds[16] = CRGB(0, 0, 0);
    leds[17] = CRGB(0, 0, 0);
  }


  if(t.min <= 29 && (t.min == 1 || t.min == 11 || t.min == 21)){
    leds[18] = CRGB(color);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 2 || t.min == 12 || t.min == 22)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(color);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 3 || t.min == 13 || t.min == 23)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(color);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 4 || t.min == 14 || t.min == 24)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(color);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 5 || t.min == 15 || t.min == 25)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(color);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 6 || t.min == 16 || t.min == 26)){
    leds[18] = CRGB(color);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(color);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 7 || t.min == 17 || t.min == 27)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(color);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 8 || t.min == 18 || t.min == 28)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(color);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min <= 29 && (t.min == 9 || t.min == 19 || t.min == 29)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(color);
  }
  if(t.min == 0 || t.min == 10 || t.min == 20 || t.min == 30 || t.min == 40 || t.min == 50){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min >= 31){
    pakas = 60 - t.min;
  }
  if(t.min >= 31 && (pakas == 1 || pakas == 11 || pakas == 21)){
    leds[18] = CRGB(color);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 2 || pakas == 12 || pakas == 22)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(color);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 3 || pakas == 13 || pakas == 23)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(color);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 4 || pakas == 14 || pakas == 24)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(color);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 5 || pakas == 15 || pakas == 25)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(color);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 6 || pakas == 16 || pakas == 26)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(color);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 7 || pakas == 17 || pakas == 27)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(color);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 8 || pakas == 18 || pakas == 28)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(color);
    leds[26] = CRGB(0, 0, 0);
  }
  if(t.min >= 31 && (pakas == 9 || pakas == 19 || pakas == 29)){
    leds[18] = CRGB(0, 0, 0);
    leds[19] = CRGB(0, 0, 0);
    leds[20] = CRGB(0, 0, 0);
    leds[21] = CRGB(0, 0, 0);
    leds[22] = CRGB(0, 0, 0);
    leds[23] = CRGB(0, 0, 0);
    leds[24] = CRGB(0, 0, 0);
    leds[25] = CRGB(0, 0, 0);
    leds[26] = CRGB(color);
  }
  if(t.min >= 31){
    leds[27] = CRGB(color);
  }
  else{
    leds[27] = CRGB(0, 0, 0);
  }
  if(t.dow == 1){
    leds[29] = CRGB(color);
    leds[30] = CRGB(0, 0, 0);
    leds[31] = CRGB(0, 0, 0);
    leds[32] = CRGB(0, 0, 0);
    leds[33] = CRGB(0, 0, 0);
    leds[34] = CRGB(0, 0, 0);
    leds[35] = CRGB(0, 0, 0);
  }
  if(t.dow == 2){
    leds[29] = CRGB(0, 0, 0);
    leds[30] = CRGB(color);
    leds[31] = CRGB(0, 0, 0);
    leds[32] = CRGB(0, 0, 0);
    leds[33] = CRGB(0, 0, 0);
    leds[34] = CRGB(0, 0, 0);
    leds[35] = CRGB(0, 0, 0);
  }
  if(t.dow == 3){
    leds[29] = CRGB(0, 0, 0);
    leds[30] = CRGB(0, 0, 0);
    leds[31] = CRGB(color);
    leds[32] = CRGB(0, 0, 0);
    leds[33] = CRGB(0, 0, 0);
    leds[34] = CRGB(0, 0, 0);
    leds[35] = CRGB(0, 0, 0);
  }
  if(t.dow == 4){
    leds[29] = CRGB(0, 0, 0);
    leds[30] = CRGB(0, 0, 0);
    leds[31] = CRGB(0, 0, 0);
    leds[32] = CRGB(color);
    leds[33] = CRGB(0, 0, 0);
    leds[34] = CRGB(0, 0, 0);
    leds[35] = CRGB(0, 0, 0);
  }
  if(t.dow == 5){
    leds[29] = CRGB(0, 0, 0);
    leds[30] = CRGB(0, 0, 0);
    leds[31] = CRGB(0, 0, 0);
    leds[32] = CRGB(0, 0, 0);
    leds[33] = CRGB(color);
    leds[34] = CRGB(0, 0, 0);
    leds[35] = CRGB(0, 0, 0);
  }
  if(t.dow == 6){
    leds[29] = CRGB(0, 0, 0);
    leds[30] = CRGB(0, 0, 0);
    leds[31] = CRGB(0, 0, 0);
    leds[32] = CRGB(0, 0, 0);
    leds[33] = CRGB(0, 0, 0);
    leds[34] = CRGB(color);
    leds[35] = CRGB(0, 0, 0);
  }
  if(t.dow == 7){
    leds[29] = CRGB(0, 0, 0);
    leds[30] = CRGB(0, 0, 0);
    leds[31] = CRGB(0, 0, 0);
    leds[32] = CRGB(0, 0, 0);
    leds[33] = CRGB(0, 0, 0);
    leds[34] = CRGB(0, 0, 0);
    leds[35] = CRGB(color);
  }
  FastLED.show();
}
