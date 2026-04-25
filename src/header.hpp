#include <ESP8266mDNS.h>
#include <ArduinoJson.h>
#include <stdint.h> // для определения uint8_t

typedef struct
{
   int s_t;
} MyData;

void wifiConnect();     // wifiConnect.cpp устанавливает соединение и синхронизирует время
bool wifiIsConnected(); // возвращает true если связь установлена

void setNewTemp(String newTemp);

// void setDisplay();
// void loopDisplay(int i, float temperature);
// void delHeat();
// void writeDefT();
// void writeHeat();

void initSauna();
void handTurnOn();
void handTurnOff();
void turnOn();
void turnOff();

void setSensors();
void loopSensors();
void loopTemperature();

void buttonSetup();
void buttonLoop();

bool mqttConnected(); // mqttConnect.cpp  устанавливает соединение с брокером
void mqttLoop();      // mqttConnect.cpp -> main.cpp  вызывается в цикле

// void setTrustAnchors(); // httpConnect.cpp -> wifiConnect.cpp  добавляет сертификат

void mqttPublishFloat(const char *title, float value, const char *item, const char *topic); // mqttConnect.cpp -> dht.cpp, pzem.cpp
void mqttPublish(const char *title, const char *value, const char *topic);                  // mqttConnect.cpp -> login.cpp
// отправляет данные брокеру

// mqttControl.cpp -> mqttConnect.cpp Функция обратного вызова при поступлении входящего сообщения от брокера
void mqttOnIncomingMsg(char *topic, uint8_t *payload, unsigned int length);

const char mqttpTopicSaunaSwitch[] = "home/sauna/switch";
const char mqttpTopicSaunaHeat[] = "home/sauna/heat";
const char mqttpTopicTemp[] = "home/sauna/temp";
const char mqttpTopicInitTemp[] = "home/sauna/temp-def";
const char mqttpTopicSaunaStatus[] = "home/sauna/switch-status";
// const char mqttpTopicTempStatus[] = "home/sauna/temp-status";

extern String def_temp;
extern boolean k_switch;

void setupTft();
void loopTft();