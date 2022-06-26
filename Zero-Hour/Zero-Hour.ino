#include "LIS3DHTR.h"
#include <Wire.h>



LIS3DHTR<TwoWire> LIS;
#define WIRE Wire



void setup() {

  Serial.begin(115200);
  while (!Serial) {};
  LIS.begin(WIRE, 0x19);
  delay(100);


  LIS.setOutputDataRate(LIS3DHTR_DATARATE_5KHZ);
  LIS.setHighSolution(true);

}

void loop() {
  if (!LIS)
  {
    Serial.println("LIS3DHTR didn't connect.");
    while (1);
    return;
  }

  float xacl = LIS.getAccelerationX();
  float yacl = LIS.getAccelerationY();
  float zacl = LIS.getAccelerationZ();


  if (abs(xacl) > 15 || abs(yacl) > 15 || abs(zacl) > 15)
  {
    Serial.println("Accident Happened");
    delay(3000);
  }

  Serial.print(xacl); Serial.print("  ");
  Serial.print(yacl); Serial.print("  ");
  Serial.println(zacl);
}
