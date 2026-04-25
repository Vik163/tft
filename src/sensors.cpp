#include <OneWire.h>
#include <DallasTemperature.h>

#include <header.hpp>

String def_temp = "70"; // температура по умолчанию

const int SensorDataPin = 14;

boolean k_on = false; // ключ запрета повторного включения (меняется после первого вызова)

float temp_s = 0;

OneWire oneWire(SensorDataPin);
DallasTemperature sensors(&oneWire);

int total_devices;
DeviceAddress sensor_address;

// void printAddress(DeviceAddress deviceAddress)
// {
//    for (uint8_t i = 0; i < 8; i++)
//    {
//       if (deviceAddress[i] < 16)
//          Serial.print("0");
//       Serial.print(deviceAddress[i], HEX);
//    }
// }

void setSensors()
{
   sensors.begin();

   total_devices = sensors.getDeviceCount(); // общее количество сенсоров и у каждого свой адрес

   // for (int i = 0; i < total_devices; i++)
   // {
   //    if (sensors.getAddress(sensor_address, i))
   //    {
   //       Serial.print("Found device ");
   //       Serial.print(i, DEC);
   //       Serial.print(" with address: ");
   //       printAddress(sensor_address); // разбивает общее количество по индексу и собственному адресу (284071540000001D)
   //       Serial.println();
   //    }
   //    else
   //    {
   //       Serial.print("Found device at ");
   //       Serial.print(i, DEC);
   //       Serial.print(" but could not detect address. Check circuit connection!");
   //    }
   // }
}

void loopTemperature()
{
   sensors.requestTemperatures();

   for (int i = 0; i < total_devices; i++)
   {

      if (sensors.getAddress(sensor_address, i))
      {
         float temperature = sensors.getTempC(sensor_address);

         if (i == 0)
         {
            mqttPublishFloat("TempSauna: ", temperature, "*C", mqttpTopicTemp);
            temp_s = temperature;
         }
         // loopDisplay(i, temperature);
      }
   }
}

void loopSensors()
{
   int t = def_temp.toInt(); // установленная температура
   int t_d = 2;              // разница градусов между включением и отключением

   if (temp_s + t_d <= t && !k_on && k_switch)
   {
      turnOn();
      k_on = true;
   }
   else if ((!k_switch && k_on) || (k_on && temp_s > t))
   {
      turnOff();
      k_on = false;
   }
}
