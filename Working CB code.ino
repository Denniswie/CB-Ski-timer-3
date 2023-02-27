// initial configurations
//-------------------------------------------
#include <LiquidCrystal.h>

#define gate 11 // was "button"
#define beam 9
#define reset 10

// set some global variables
int timerMode =0;
long startTime;

// screen pin configuration
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
//-------------------------------------------

// setup - runs only once when first powered up
//---------------------------------------------
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(gate, INPUT_PULLUP);
  pinMode(beam, INPUT_PULLUP);
  pinMode(reset, INPUT_PULLUP);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ready for a run.");
  
}
//---------------------------------------------  
// modified main loop
//---------------------------------------------
void loop(){ //             if #0
  lcd.setCursor(0,1);
  if(digitalRead(gate)==LOW) {    //if #1
    if(timerMode  ==0){                  // if #2
	  startTime=millis();
	  timerMode++;
	  lcd.clear();lcd.setCursor(0,1); lcd.print("Running    ");
	  }                                    // if #2
  }                              // if #1
  
  if(timerMode ==1){             // if #3
	lcd.setCursor(12,1);
	lcd.print((millis()-startTime)/1000.0);

    if(digitalRead(beam) == LOW){          // if #4
      timerMode = 0;
       lcd.setCursor(0,1); lcd.print("Time=      ");
       lcd.setCursor(0,0); lcd.print("Press Reset");
	  while (digitalRead(reset) == HIGH ) { delay(50); }
	  lcd.setCursor(0,0); lcd.print("Press to Start   ");
    while(digitalRead(gate)==LOW){ lcd.clear(); lcd.print("Gate Open !     "); delay(50);}
    lcd.clear(); lcd.print("Ready for Run   ");
      }                                      // if #4
  }                                // if #3
}                         // if #0