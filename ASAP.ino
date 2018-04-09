#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int MQ2InPin = A2;
const int MQ2OutPin = A3;
const int ledPin = 13;
const int fanPin = 9;

float fanValue = 0;
float fanValue1 = 0;
int in2Value = 0;
int out2Value = 0;
int sensorFan = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT); 
}

void loop() {
  in2Value = analogRead(MQ2InPin);  
  out2Value = analogRead(MQ2OutPin);
  Serial.print("In : ");
  Serial.println(in2Value);  
  if (in2Value >= 100 && in2Value <= 150) {
    //PWMValue
    analogWrite(fanPin, 70);
    //LED
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    
  } else if (in2Value > 150 && in2Value <= 500){
    //PWMValue
    analogWrite(fanPin, 200);
    //LED
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
  } else if (in2Value > 500) {
    //PWMValue
    analogWrite(fanPin, 255);
    //LED
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
  }
  else {
    //PWMValue
    digitalWrite(fanPin,LOW );
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
  analogRead(9);
  //Deteksi Voltage
  fanValue = analogRead (fanPin);
  fanValue1 = analogRead(fanPin);
  Serial.println(fanValue1);
  fanValue = fanValue * (5.0 / 1023);
  Serial.println (fanValue);
  Serial.print("outmq = " );
  Serial.println(out2Value); 
  lcd.begin(16, 2);
  lcd.print("Asap  = ");
  lcd.print(in2Value);
  lcd.print(" ppm");
  lcd.setCursor(0, 1);
  lcd.print("Volt  = ");
  lcd.print(fanValue);
  lcd.print(" V");
         
}
