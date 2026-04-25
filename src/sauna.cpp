#include <header.hpp>

#define PIN_SAUNA D6

void turnOn()
{
   pinMode(PIN_SAUNA, HIGH); // заменил digitalWrite на pinMode (реле не выключалось https://community.alexgyver.ru/threads/rele-ne-vykljuchaetsja-esp8266.7815/)
   // writeHeat();              // отображет на дисплее нагрев
   mqttPublish("SaunaHeat: ", "heat", mqttpTopicSaunaHeat);
}

void turnOff()
{
   pinMode(PIN_SAUNA, LOW); // выключаем светодиод
   // delHeat();               // удаляет на дисплее нагрев
   mqttPublish("SaunaHeat: ", "cool", mqttpTopicSaunaHeat);
}

void initSauna()
{
   pinMode(PIN_SAUNA, LOW);
}

void handTurnOn()
{
   turnOn();
   mqttPublish("SaunaStatus: ", "1", mqttpTopicSaunaStatus); // меняет состояние кнопки в брокере
}

void handTurnOff()
{
   turnOff();
   mqttPublish("SaunaStatus: ", "0", mqttpTopicSaunaStatus);
}
