#include <SPI.h>
#include <LoRa.h>

int led = 8; 
int digitalPin = 2; 
int analogPin = A0; 
int digitalVal; 
int analogVal; 
int counter = 0;
int flamme = 0;

void setup() {

  Serial.begin(9600);
  while (!Serial);
   Serial.println("LoRa Sender");
  if (!LoRa.begin(865E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  pinMode(led, OUTPUT);
  pinMode(digitalPin, INPUT);
  //pinMode(analogPin, OUTPUT);  
}

void loop() 
{
  digitalVal = digitalRead(digitalPin);
   if(digitalVal == HIGH) // flame détecté
  {
    Serial.println("FLAMME FLAMME FLAMME");
    digitalWrite(led, HIGH); //Allume la led
  }
  else
  {
    Serial.println("no flamme");
    digitalWrite(led, LOW); //éteint la led
    
  }
 analogVal = analogRead(analogPin); 
    Serial.println(analogVal);
  LoRa.beginPacket();
  delay(1000);

}
