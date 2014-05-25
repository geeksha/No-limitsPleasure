#include <IRremote.h>

IRsend irsend;
/ These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin11 = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin12 = A1;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue1 = 0;        // value read from the pot
int sensorValue2 = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

int ledPin =13;

void setup() { 
   pinMode(ledPin, OUTPUT); 
   Serial.begin(9600); 
   //pinMode(buttonPin1, INPUT);
   //pinMode(buttonPin2, INPUT);
}
void loop() { 

  sensorValue1 = analogRead(analogInPin11);   
  sensorValue2 = analogRead(analogInPin12); 

  int sensorState1 = analogRead(analogInPin11);
  int sensorState2 = analogRead(analogInPin12);

//sensor1   
   if (sensorState1 == HIGH) {  
     analogWrite(ledPin, LOW);
       for (int i = 0; i < 3; i++) {
        irsend.sendSony(0xa90, 12); // Sony TV power code
        delay(40);
      }
  } 
  else {
     analogWrite(ledPin, HIGH);
    }

//sensor2    
   if (sensorState2 == HIGH) {  
      analogWrite(ledPin, LOW);
        for (int i = 0; i < 3; i++) {
        irsend.sendSony(0xa80, 12); // Sony TV power code
        delay(40);
      }
   } 
   else {
      analogWrite(ledPin, HIGH);
    } 

  Serial.print("sensor1 = " );                       
  Serial.println(sensorValue1);      
  Serial.print("sensor2 = " );                       
  Serial.println(sensorValue2); 

  delay(2); 

   }



