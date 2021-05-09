#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 7, 6, 5, 4);

#define in 8
#define out 9
#define led 10
#define buzz 11

int count = 0;

void setup()
{
  int count = 0;
  lcd.begin(16, 2);
  lcd.print("Visitor Counter");
  delay(1000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0, 1);
  lcd.print(count);
}

void loop(){//loops the process
while(count>=0)
{
  int in_value = digitalRead(in);//variable 1: walking inside
  int out_value = digitalRead(out);//variable 2: walking outside
  
  if (in_value == LOW )//
  {
    count++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0, 1);
    lcd.print(count);
    delay(1000);
  }
  
  if (out_value == LOW && count > 0)
  {
    count--;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0, 1);
    lcd.print(count);
    delay(1000);
  }
  
  if (count>count || count<count)
  {
    delay(2300);
  }
  
  if (count == 0)
  {
    lcd.clear();
    digitalWrite(led, LOW);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0, 1);
    lcd.print("Light is Off");
    delay(200);
  }

  else
  {
    digitalWrite(led, HIGH);
  }

  if(count > 5)
  {
    digitalWrite(buzz, HIGH);
  }
  else
  {
    digitalWrite(buzz, LOW);
  }
}
}
