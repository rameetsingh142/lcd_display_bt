#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
char val; 
int c=0;
int r=0;
int R=0;
void setup() {
 // put your setup code here, to run once:

Serial.begin(9600);
lcd.begin(16,2);
lcd.clear();
lcd.setCursor(0,0);
//lcd.print(val);

}

void loop() {
 // put your main code here, to run repeatedly:
if(Serial.available())
{
 val = Serial.read();
 if((c<=15)&&(r==0))
 {
 lcd.write(val);
 c++;
 lcd.setCursor(c,r);
 
 }
 if(c>15)
 {
   lcd.setCursor(R,1);
   lcd.write(val);
   R++;
 }
 if(R>15)
 {
   lcd.clear();
   lcd.setCursor(0,0);
   c=0;
   r=0;
   R=0;
 }
 }
delay(200);
}
