/*

Example of BH1750 library usage.

This example initalises the BH1750 object using the default
high resolution mode and then makes a light level reading every second.

Connection:
 VCC-5v
 GND-GND
 SCL-SCL(analog pin 5)
 SDA-SDA(analog pin 4)
 ADD-NC or GND

*/

#include <Wire.h>
#include <BH1750.h>


BH1750 lightMeter;


void setup(){
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  lightMeter.begin();
  Serial.println("Running...");
}


void loop() {
  uint16_t lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  if(lux<100)
  {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }
  else
  if(lux>=950)
  {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }
  else 
  if(lux>=100)
  {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
  }
  delay(1000);
}
