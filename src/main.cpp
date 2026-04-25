#include <SoftwareSerial.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <RTCMemory.h>

#include <header.hpp>

unsigned long t_delay = 15000; // каждые 15 сек. измерения температуры
uint32_t myTimer1;

RTCMemory<MyData> rtcMemory;

int initTemp = 70;

// 14400 - Самарское время 3600*4
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 14400, 60000);

MyData *dataRtc;

void setNewTemp(String newTemp)
{
  dataRtc->s_t = newTemp.toInt();

  rtcMemory.save();
}

void setup(void)
{

  // Serial.begin(115200);
  Serial.begin(9600);
  Serial.println();

  wifiConnect();

  initSauna();

  // setDisplay();
  // setSensors();

  rtcMemory.begin();

  dataRtc = rtcMemory.getData();

  if (!dataRtc->s_t)
    dataRtc->s_t = initTemp;

  rtcMemory.save();

  mqttPublishFloat("TempSaunaInit: ", dataRtc->s_t, "*C", mqttpTopicInitTemp);

  // buttonSetup();

  setupTft();
}

void loop()
{
  loopTft();
  // buttonLoop();
  // if (wifiIsConnected())
  // {
  //   if (mqttConnected())
  //   {
  //     mqttLoop();
  //     // loopSensors();

  //     // if (millis() - myTimer1 >= t_delay)
  //     // {
  //     //   loopTemperature();
  //     //   myTimer1 = millis();
  //     // }
  //   }
  // }
}
