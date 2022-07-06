if(!digitalRead(endbutpin)){
    timesetmode = 1; 
  }
  while(timesetmode == 1){    
    
    while(timestate == 1 && timesetmode == 1){
      if(!digitalRead(nextbutpin)){        
        hours = timestate1;
        timestate++;
      }
      if(timestate == 6){
        timestate = 1;
      }
      if(!digitalRead(endbutpin)){
        timesetmode = 0;
      }
      if(!digitalRead(switchbutpin)){
        if(timestate1 == 13){  
          timestate1 = 1;        
        }
        timestate1++;
      }
      if(round(millis() / 1000) % 2 == 0){
        for(int i = 0; i < 1; i++){
          int j;
          j = i + 1;
          leds[j] = CRGB(0, 0, 0);
          FastLED.show();
        }
        leds[timestate1] = CRGB(green, red, blue);      
      }
      else{
        for(int i = 0; i < 13; i++){
          int j;
          j = i + 1;
          leds[j] = CRGB(0, 0, 0);
          FastLED.show();
        }  
      }
      FastLED.show();
    }
    for(int i = 0; i < 13; i++){
      int j;
      j = i + 1;
      leds[j] = CRGB(0, 0, 0);
      FastLED.show();
    }
    leds[timestate1] = CRGB(green, red, blue);
    FastLED.show();
    while(timestate == 2 && timesetmode == 1){            
      if(!digitalRead(nextbutpin)){        
        pakas1 = timestate2;
        timestate++;
      }
      if(timestate == 6){
        timestate = 1;
      }
      if(!digitalRead(endbutpin)){
        timesetmode = 0;
      }
      if(!digitalRead(switchbutpin)){
        if(timestate2 == 3){  
          timestate2 = 1;        
        }
        timestate2++;
      }
      if(round(millis() / 1000) % 2 == 0){
        for(int i = 0; i < 2; i++){
          int j;
          j = i + 13;
          leds[j] = CRGB(0, 0, 0);
          FastLED.show();
        }
        int j;
        j = timestate2 + 12;
        leds[j] = CRGB(green, red, blue); 
        if(j == 13){
          leds[27] = CRGB(green, red, blue); 
        }
        else{
          leds[27] = CRGB(0, 0, 0);
        }
      }
      else{
        for(int i = 0; i < 2; i++){
          int j;
          j = i + 13;
          leds[j] = CRGB(0, 0, 0);
          leds[27] = CRGB(0, 0, 0);
          FastLED.show();
        }  
      }
      FastLED.show();
    }
    for(int i = 0; i < 2; i++){
      int j;
      j = i + 13;
      leds[j] = CRGB(0, 0, 0);
      FastLED.show();
    }
    if(timestate2 == 1){
      leds[13] = CRGB(green, red, blue);
      leds[14] = CRGB(0, 0, 0);
      leds[27] = CRGB(0, 0, 0);
    }
    else if(timestate2 == 2){
      leds[13] = CRGB(0, 0, 0);
      leds[14] = CRGB(green, red, blue);
      leds[27] = CRGB(green, red, blue);
    }
    FastLED.show();
    while(timestate == 3 && timesetmode == 1){
      if(!digitalRead(nextbutpin)){        
        minutestas = timestate3;
        timestate++;
      }
      if(timestate == 6){
        timestate = 1;
      }
      if(!digitalRead(endbutpin)){
        timesetmode = 0;
      }
      if(!digitalRead(switchbutpin)){
        if(timestate3 == 5){            
          timestate3 = 1;        
        }
        timestate3++;
        if(timestate2 == 1 && timestate3 == 3){
          timestate3 = 4;
        }        
      }
      if(round(millis() / 1000) % 2 == 0){
        for(int i = 0; i < 3; i++){
          int j;
          j = i + 15;
          leds[j] = CRGB(0, 0, 0);
          FastLED.show();
        }
        if(timestate3 != 4){
          int j;
          j = timestate3 + 14;
          leds[j] = CRGB(green, red, blue); 
        }
        else{
          leds[15] = CRGB(0, 0, 0);
          leds[16] = CRGB(0, 0, 0);
          leds[17] = CRGB(0, 0, 0);       
        }
      }
      else{
        for(int i = 0; i < 3; i++){
          int j;
          j = i + 15;
          leds[j] = CRGB(0, 0, 0);
          FastLED.show();
        }  
      }
      FastLED.show();     
    }
    for(int i = 0; i < 3; i++){
      int j;
      j = i + 15;
      leds[j] = CRGB(0, 0, 0);
      FastLED.show();
    }
    int tasnyakindic;
    tasnyakindic = timestate3 + 14;
    if(timestate3 != 4){
      leds[tasnyakindic] = CRGB(green, red, blue);
    }
    else{
      leds[15] = CRGB(0, 0, 0);
      leds[16] = CRGB(0, 0, 0);
      leds[17] = CRGB(0, 0, 0);
    }   
    FastLED.show(); 
    while(timestate == 4 && timesetmode == 1){
      if(!digitalRead(nextbutpin)){        
        minutesmiv = timestate4;
        timestate++;
      }
      if(timestate == 6){
        timestate = 1;
      }
      if(!digitalRead(endbutpin)){
        timesetmode = 0;
      }
      if(!digitalRead(switchbutpin)){
        int j;
        if(timestate3 != 4){
          j == 10;          
        }
        else{
          j == 11;
        }
        if(timestate4 == j){  
          timestate4 = 1;        
        }
        timestate4++;
      }
      
      if(round(millis() / 1000) % 2 == 0){
        for(int i = 0; i < 10; i++){
          int j;
          j = i + 18;
          leds[j] = CRGB(0, 0, 0);
          FastLED.show();
        }
        if(timestate4 != 10){
          int j;
          j = timestate4 + 17;
          leds[j] = CRGB(green, red, blue);
        }
        else{
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
      }
      else{
        for(int i = 0; i < 9; i++){
          int j;
          j = i + 18;
          leds[j] = CRGB(0, 0, 0);
          FastLED.show();
        }  
      } 
      FastLED.show();    
    }
    int miavorindic;
    miavorindic = timestate4 + 17;  
    for(int i = 0; i < 3; i++){
      int j;
      j = i + 15;
      leds[j] = CRGB(0, 0, 0);
      FastLED.show();
    }
    if(timestate4 != 10){
      leds[miavorindic] = CRGB(green, red, blue);
    }
    else{
      leds[15] = CRGB(0, 0, 0);
      leds[16] = CRGB(0, 0, 0);
      leds[17] = CRGB(0, 0, 0);
    }  
    FastLED.show();           
    while(timestate == 5 && timesetmode == 1){
      if(!digitalRead(nextbutpin)){        
        day = timestate5;
        timestate++;
      }
      if(timestate == 6){
        timestate = 1;
      }
      if(!digitalRead(endbutpin)){
        timesetmode = 0;
      }
      if(!digitalRead(switchbutpin)){
        if(timestate5 == 8){  
          timestate5 = 1;        
        }
        timestate5++;
      }
      if(round(millis() / 1000) % 2 == 0){
        for(int i = 0; i < 7; i++){
          int j;
          j = i + 19;
          leds[j] = CRGB(0, 0, 0);
          FastLED.show();
        }
        int j;
        j = timestate5 + 28;
        leds[j] = CRGB(green, red, blue);      
      }
      else{
        for(int i = 0; i < 7; i++){
          int j;
          j = i + 29;
          leds[j] = CRGB(0, 0, 0);
          FastLED.show();
        }  
      }
      FastLED.show();    
    }
    for(int i = 0; i < 7; i++){
      int j;
      j = i + 29;
      leds[j] = CRGB(0, 0, 0);
      FastLED.show();
    }
    int orindic;
    orindic = timestate5 + 28;
    leds[orindic] = CRGB(green, red, blue);
    FastLED.show();
    if(pakas1 == 1){
      if(minutestas == 1){
        if(minutesmiv == 1){
          minutes = 49;     
        }
        if(minutesmiv == 2){
          minutes = 48;    
        }
        if(minutesmiv == 3){
          minutes = 47;    
        }
        if(minutesmiv == 4){
          minutes = 46;    
        }
        if(minutesmiv == 5){
          minutes = 45;    
        }
        if(minutesmiv == 6){
          minutes = 44;    
        }
        if(minutesmiv == 7){
          minutes = 43;    
        }
        if(minutesmiv == 8){
          minutes = 42;    
        }
        if(minutesmiv == 9){
          minutes = 41;    
        }
        if(minutesmiv == 10){
          minutes = 50;    
        }
      } 
      if(minutestas == 2){
        if(minutesmiv == 1){
          minutes = 39;     
        }
        if(minutesmiv == 2){
          minutes = 38;    
        }
        if(minutesmiv == 3){
          minutes = 37;    
        }
        if(minutesmiv == 4){
          minutes = 36;    
        }
        if(minutesmiv == 5){
          minutes = 35;    
        }
        if(minutesmiv == 6){
          minutes = 34;    
        }
        if(minutesmiv == 7){
          minutes = 33;    
        }
        if(minutesmiv == 8){
          minutes = 32;    
        }
        if(minutesmiv == 9){
          minutes = 31;    
        }
        if(minutesmiv == 10){
          minutes = 40;    
        }
      }
      if(minutestas == 4){
        if(minutesmiv == 1){
          minutes = 59;     
        }
        if(minutesmiv == 2){
          minutes = 58;    
        }
        if(minutesmiv == 3){
          minutes = 57;    
        }
        if(minutesmiv == 4){
          minutes = 56;    
        }
        if(minutesmiv == 5){
          minutes = 55;    
        }
        if(minutesmiv == 6){
          minutes = 54;    
        }
        if(minutesmiv == 7){
          minutes = 53;    
        }
        if(minutesmiv == 8){
          minutes = 52;    
        }
        if(minutesmiv == 9){
          minutes = 51;    
        }
      }        
    }
    rtc.setTime(hours, minutes, seconds);
    if(day == 1){
      rtc.setDOW(MONDAY);
    }
    if(day == 2){
      rtc.setDOW(TUESDAY);
    }
    if(day == 3){
      rtc.setDOW(WEDNESDAY);
    }
    if(day == 4){
      rtc.setDOW(THURSDAY);
    }
    if(day == 5){
      rtc.setDOW(FRIDAY);
    }
    if(day == 6){
      rtc.setDOW(SATURDAY);
    }
    if(day == 7){
      rtc.setDOW(SUNDAY);
    }
  }
