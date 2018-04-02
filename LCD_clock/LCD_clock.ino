#include <LiquidCrystal.h>

const int reset = 12, enable = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(reset, enable, d4, d5, d6, d7);

String s = "";
int sec=55, minute=59, hour=23, day=364, week=0, yr=0;
int timeSinceStart = 2, compareTime = 3, x=5;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  delay(1000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  compareTime = millis()/1000;
  if (compareTime - timeSinceStart > 0){
    sec += 1;
    timeSinceStart = millis() / 1000;
    
    if (sec == 60){
      minute += 1;
      sec = 0;
      }
    if (minute == 60){
      hour += 1;
      minute = 0;
      }
    if (hour == 24){
      day += 1;
      hour = 0;
      }
      /*
    if (day == 7){
      week += 1;
      day == 0;
      lcd.clear();
      }
    if (week == 52){
      year += 1;
      week = 0;
      lcd.clear();
      }
      */
    lcd.setCursor(0,0);
    s = "";
    if (day < 100)
      s += "0";
    if(day < 10)
      s += "0";
    s += day;
    s += ":";
    if (hour < 10)
      s += "0";
    s += hour;
    s += ":";
    if (minute < 10)
      s += "0";
    s += minute;
    s += ":";
    if (sec < 10)
      s += "0";
    s += sec;
    lcd.print(s);
    //lcd.print(sec);
  }
}
