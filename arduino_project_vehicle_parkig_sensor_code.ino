#include <LiquidCrystal.h>

const int trigPin = 1; 
const int echoPin = 2; 
const int buzzerPin = 3; 
const int redLedPin = 4; 
const int yellowLedPin = 5; 
const int greenLedPin = 6; 
LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzerPin, OUTPUT);
pinMode(redLedPin, OUTPUT);
pinMode(yellowLedPin, OUTPUT);
pinMode(greenLedPin, OUTPUT);

lcd.begin(16, 2);
lcd.print("WELCOME !");
lcd.setCursor(0, 1);
lcd.print("VEHICLE PARKING");                
delay(2000);
}


void loop() 
{
long duration, distance;                              
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
                                             
distance = duration * 0.034 / 2;
                                            
lcd.clear();                                                                    
if (distance < 5) {
digitalWrite(redLedPin, HIGH);
digitalWrite(yellowLedPin, LOW);
digitalWrite(greenLedPin, LOW);
tone(buzzerPin, 1500, 1000); 
lcd.print("NO SPACE AREA");
}
else if (distance < 15) {

digitalWrite(redLedPin, LOW);
digitalWrite(yellowLedPin, HIGH);
digitalWrite(greenLedPin, LOW);
lcd.print("PARKING HERE");
tone(buzzerPin, 1500, 500); 
} 
else {

digitalWrite(redLedPin, LOW);
digitalWrite(yellowLedPin, LOW);
digitalWrite(greenLedPin, HIGH);
lcd.print("AVAILABLE SPACE AREA");
noTone(buzzerPin); 
}
delay(1000); 
}
