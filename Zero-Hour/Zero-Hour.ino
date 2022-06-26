#include "LIS3DHTR.h"
#include "twilio.hpp"
#include <TinyGPSPlus.h>
#include <Wire.h>



LIS3DHTR<TwoWire> LIS;
#define WIRE Wire

TinyGPSPlus gps;

TaskHandle_t t1;

static const char *ssid = "YOUR_WIFI_SSID";
static const char *password = "YOUR_WIFI_PASSWORD";

String lat = "INV", lon = "INV", msg = "";
boolean gpsStat = false, acclStat = false, wiFiStat = false;

static const char *from_number = "YOUR_TWILIO_NUMBER";


String to_numbers[] = {"YOUR_TO_MESSAGE_NUMBER_0", "YOUR_TO_MESSAGE_NUMBER_1", "YOUR_TO_MESSAGE_NUMBER_2"};


Twilio *twilio;

void setup() {

  Serial.begin(115200);
  pinMode(2, OUTPUT);
  accelInit();
  gpsInit();
  setupWiFiAndTwilio();

}


void loop() {

  boolean f = checkAccident();
 
  
  String response;
  if(f)
  {
    boolean success = false;
    
    for (int i = 0; i < 3; i++)
    {
      msg = "YOUR_NAME Had an Accident at location " + msg + " Please Help";
      success = twilio->send_message(to_numbers[i], from_number, msg, response);
    }

    if(success)
    {
    Serial.println("Message Sent");
    digitalWrite(2, HIGH);
    }
    delay(3000);
  }

  
}



void accelInit()
{

  LIS.begin(WIRE, 0x19);
  delay(100);
  LIS.setOutputDataRate(LIS3DHTR_DATARATE_5KHZ);
  LIS.setHighSolution(true);

  if (!LIS)
  {
    acclStat = false;
    Serial.println("LIS3DHTR didn't connect.");
    while (1);
    return;
  }

  else
    acclStat = true;
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


boolean checkAccident()
{
  float xacl = LIS.getAccelerationX();
  float yacl = LIS.getAccelerationY();
  float zacl = LIS.getAccelerationZ();

//Serial.printf("%f %f %f\n", xacl, yacl, zacl);

  if (abs(xacl) > 15 || abs(yacl) > 15 || abs(zacl) > 15)
  {
    Serial.println("Accident Happened");
    return true;
  }

  return false;
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

      //Serial.println(msg);
      gpsStat = true;
    }
    else
    {
      Serial.println("Invalid");
      gpsStat = false;
    }
    delay(1000);
  }

}


void setupWiFiAndTwilio()
{

  static const char *account_sid = "YOUR_TWILIO_ACC_SID";
  static const char *auth_token = "YOUR_AUTH_TOKEN";
  


  Serial.print("Connecting to WiFi network ;");
  Serial.print(ssid);
  Serial.println("'...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting...");
    delay(500);
  }
  

   Serial.println("Connected!");

   twilio = new Twilio(account_sid, auth_token);

   
}


