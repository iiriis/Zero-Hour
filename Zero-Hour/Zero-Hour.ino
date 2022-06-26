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

  Serial.print(LIS.getAccelerationX()); Serial.print("  ");
  Serial.print(LIS.getAccelerationY()); Serial.print("  ");
  Serial.println(LIS.getAccelerationZ());
}
