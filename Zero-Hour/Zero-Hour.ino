#include "LIS3DHTR.h"
#include <TinyGPSPlus.h>
#include <Wire.h>



LIS3DHTR<TwoWire> LIS;
#define WIRE Wire

TinyGPSPlus gps;

TaskHandle_t t1;

String lat = "INV", lon = "INV", msg = "";

void setup() {

  Serial.begin(115200);
  accelInit();
  gpsInit();

}

void accelInit()
{
  while (!Serial) {};
  LIS.begin(WIRE, 0x19);
  delay(100);
  LIS.setOutputDataRate(LIS3DHTR_DATARATE_5KHZ);
  LIS.setHighSolution(true);
}

void gpsInit()
{
  Serial2.begin(9600);
  Serial.println("GPS Initialized");
  xTaskCreatePinnedToCore(runGPS,
                          "t1",
                          3000,
                          NULL,
                          1,
                          &t1,
                          1);
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
}

void runGPS(void *pv)
{

  for (;;)
  {
    boolean flag = false;
    while (Serial2.available() > 0)
      if (gps.encode(Serial2.read()))
        flag = true;

    if (flag && gps.location.isValid())
    {
      lat = String(gps.location.lat(), 6);
      lon = String(gps.location.lng(), 6);
      msg = lat + " , " + lon;

      Serial.println(msg);
    }
    else
      Serial.println("Invalid");
    delay(1000);
  }

}
