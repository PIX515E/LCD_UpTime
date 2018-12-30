/*
Created by: PIX515E
Last Edited: 5/9/2013 6:25 PM CST
A simple Unit Uptime display via LCD.
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long t = 0;
int s = 0;
int m = 0;
int h = 0;
int i = 0;
int scroll = 0;

byte timer1[8] = {
  B01110,
  B11011,
  B00100,
  B01010,
  B00100,
  B11011,
  B01110,
};

byte timer2[8] = {
  B01111,
  B01110,
  B00100,
  B01010,
  B00100,
  B01110,
  B11110,
};

byte timer3[8] = {
  B00011,
  B00111,
  B00110,
  B01010,
  B01100,
  B11100,
  B11000,
};

byte timer4[8] = {
  B00000,
  B00110,
  B00111,
  B11011,
  B11100,
  B01100,
  B00000,
};

byte timer5[8] = {
  B00000,
  B00100,
  B01110,
  B11011,
  B01110,
  B00100,
  B00000,
};

byte timer6[8] = {
  B00000,
  B01100,
  B11100,
  B11011,
  B00111,
  B00110,
  B00000,
};

byte timer7[8] = {
  B11000,
  B11100,
  B01100,
  B01010,
  B00110,
  B00111,
  B00011,
};

byte timer8[8] = {
  B11110,
  B01110,
  B00100,
  B01010,
  B00100,
  B01110,
  B01111,
};

void timer() {
  t = millis()/1000;
  s = t-(m*60+h*3600);
  m = (t-h*3600)/60;
  h = t/3600;
  i++;
  if (i > 7) {
    i = 0;
  }
  lcd.write(byte(i));
  lcd.print(" ");
  if (h > 9) {
    lcd.print(h);
    lcd.print("h| ");
  }
  else {
    lcd.print(h);
    lcd.print(" h| ");
  }
  if (m > 9) {
    lcd.print(m);
    lcd.print("m| ");
  }
  else {
    lcd.print(m);
    lcd.print(" m| ");
  }
  if (s > 9 ) {
    lcd.print(s);
    lcd.print("s] ");
  }
  else {
    lcd.print(s);
    lcd.print(" s] ");
  }
}

void scroller() {
  for (scroll = 36; scroll > 24; scroll--) {
    lcd.setCursor(-1*scroll, 0);
    lcd.print(" ");
    lcd.print("Up Time Is:");
    lcd.print("                ");
    lcd.setCursor(0, 1);
    timer();
    delay(100);
  }
  for (scroll = 0; scroll < 16; scroll++) {
    lcd.setCursor(scroll, 0);
    lcd.print(" ");
    lcd.print("Up Time Is:");
    lcd.print("                ");
    lcd.setCursor(0, 1);
    timer();
    delay(100);
  }
}


void setup() {
  lcd.createChar(0, timer1);
  lcd.createChar(1, timer2);
  lcd.createChar(2, timer3);
  lcd.createChar(3, timer4);
  lcd.createChar(4, timer5);
  lcd.createChar(5, timer6);
  lcd.createChar(6, timer7);
  lcd.createChar(7, timer8);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // print the number of seconds since reset:
  scroller();
}
