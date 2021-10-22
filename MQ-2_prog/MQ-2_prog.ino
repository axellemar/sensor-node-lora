#include <MQ2.h>
#include <SPI.h>
#include <LoRa.h>
int counter = 0;
int redLed = 4;
int greenLed = 12;
int smokeA0 = A0;
// Your threshold value
int sensorThres = 400;


void setup() {

   while (!Serial);
  if (!LoRa.begin(865E6)) {
    Serial.println("LoRa failed!");
    while (1);
}
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
 
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Value: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    Serial.println("detect fumée");
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  }
  else
  {
    Serial.println("no fumée");
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
  }
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(2000);
}
