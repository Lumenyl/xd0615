#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() 
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("Please enter character string");
}
char a;
void loop() 
{
  if (Serial.available()>0)
  {
    lcd.clear();
    for (int i=0;i<32;i++)
    {
      a=Serial.read();
      int t=a;
      if (t==-1)
      {break;}
      if (i<16)
      {
      	lcd.setCursor(i, 0);
      	lcd.print(a);
      }
      else
      {
      	lcd.setCursor(i-16, 1);
      	lcd.print(a);
      }
  	}
  }
}
 