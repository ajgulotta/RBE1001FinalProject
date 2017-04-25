#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int Trig_pin =  8;   // pin for triggering pulse
const int Echo_pin = 7;     // pin for recieving echo
long duration;


void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println ("Starting");
  // initialize the pulse pin as output:
  pinMode(Trig_pin, OUTPUT);      
  // initialize the echo_pin pin as an input:
  pinMode(Echo_pin, INPUT);     
  
  //test code to be removed
}

void loop(){
  lcd.setCursor(0, 0);
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin,HIGH);
   
    
   
   Serial.println("Duration:  ");
   Serial.println(duration, DEC);

  lcd.print(duration, DEC);
  lcd.print("                ");

}
