#include <LiquidCrystal.h>

const int reset = 12, enable = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(reset, enable, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  // set up LCD with (cols, rows)
  lcd.begin(16,2);
  //lcd.print("hello, abcdefghijklmnop");
  lcd.print("---0---1---2---3---4");
  lcd.setCursor(0,1);
  lcd.print("                    ---5---6---7---8---9"); 
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  // set cursor location. start is (0,0)
  // lcd.setCursor(0,1);
  for(int posC = 0; posC < 5; posC++){
    // length of string scrolled is 40 regardless of print length
    lcd.scrollDisplayLeft();
    delay(250);
    }
  //lcd.print(millis() / 1000); // num seconds since reset
  
}
