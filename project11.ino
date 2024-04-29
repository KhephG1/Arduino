#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

const int switchpin = 6;

int switchstate = 0;

int prevswitchstate = 0;

int reply;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Roll the");
  lcd.setCursor(0,1);
  lcd.print("Dice!");
  pinMode(switchpin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchstate = digitalRead(switchpin);
  if(switchstate !=prevswitchstate){
    if(switchstate ==LOW){
      reply = random(6);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Dice lands on:");
      lcd.setCursor(0,1);

      switch(reply){
        case 0:
        lcd.print(1);
        break;
        case 1:
        lcd.print(2);
        break;
        case 2:
        lcd.print(3);
        break;
        case 3:
        lcd.print(4);
        break;
        case 4:
        lcd.print(5);
        break;
        case 5:
        lcd.print(6);
        break;
      }
    }
  }
  prevswitchstate = switchstate;
  
}
