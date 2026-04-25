#include <PubSubClient.h>
#include <ESP8266mDNS.h>
// #include "esp_sntp.h"

#include <header.hpp>
#include <credentialMqtt.hpp>

const char mqttpTopicDiviceStatus[] = "home/sauna/status";

const char *mqttpDiviceStatusOn = "online";
const char *mqttpDiviceStatusOff = "offline";
const int mqttpDiviceStatusQos = 1;
const bool mqttpDiviceStatusRetained = true;

// Корневой сертификат
WiFiClient wifiClientMqtt;
// BearSSL::WiFiClientSecure wifiClientMqtt;
// BearSSL::X509List certISRG(ISRG_Root_x1);
PubSubClient mqttClient(wifiClientMqtt);

bool mqttConnected()
{
   if (!mqttClient.connected())
   {
      Serial.print("Connecting to mqtt: ");
      mqttClient.setServer(mqttServer, mqttPort);

      if (mqttClient.connect(mqttClientId, mqttUser, mqttPass, mqttpTopicDiviceStatus, mqttpDiviceStatusQos, mqttpDiviceStatusRetained, mqttpDiviceStatusOff))
      {
         Serial.println("ok");
         mqttClient.publish(mqttpTopicDiviceStatus, mqttpDiviceStatusOn, mqttpDiviceStatusRetained);
         mqttClient.subscribe(mqttpTopicSaunaSwitch, mqttpDiviceStatusQos);
         mqttClient.subscribe(mqttpTopicSaunaStatus, mqttpDiviceStatusQos);
         mqttClient.subscribe(mqttpTopicTemp, mqttpDiviceStatusQos);
         mqttClient.subscribe(mqttpTopicInitTemp, mqttpDiviceStatusQos);

         mqttClient.setCallback(mqttOnIncomingMsg);

         handTurnOff();
      }
      else
      {
         Serial.print(" Mqtt failed, error code: ");
         Serial.print(mqttClient.state());
         Serial.println("!");
      }
      return mqttClient.connected();
   };
   return true;
}

/**
 * функция добавления сертификата
 */
// void setTrustAnchors() {
// wifiClientMqtt.setTrustAnchors(&certISRG);
// };

void mqttPublishFloat(const char *title, float value, const char *item, const char *topic)
{
   if (value != NAN)
   {
      // printf("%s%.1f %s\n", title, value, item);
   }
   else
      printf("Error reading: %s\n", title);

   String str_temp(value);
   mqttClient.publish(topic, str_temp.c_str(), mqttpDiviceStatusRetained);
}

void mqttPublish(const char *title, const char *value, const char *topic)
{
   mqttClient.publish(topic, value, mqttpDiviceStatusRetained);
}

void mqttLoop()
{
   mqttClient.loop();
};
