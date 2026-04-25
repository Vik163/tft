
#include <header.hpp>

#define BUTTON_PIN D7
int prev_button_state = LOW; // Предыдущее состояние входного вывода
int button_state;            // Текущее значение входного вывода

boolean k_switch = false; // ключ включения. Указывает состояние реле (вкл или откл)
boolean s_switch = false; // состояние кнопки (true когда нажата)

void buttonSetup()
{
   pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void buttonLoop()
{
   button_state = digitalRead(BUTTON_PIN);

   if (prev_button_state == HIGH && button_state == LOW && !s_switch)
   {
      if (!k_switch)
      {
         k_switch = true;
         handTurnOn(); // включает и отправляет статус включения брокеру
         // задержка нужна, чтобы смягчить баг. При измерении температуры происходит задержка времени,
         // которая вызывает быстрое включение и отключение кнопки (кнопка перещёлкивает)
         delay(500);
      }
      else
      {
         k_switch = false;
         handTurnOff();
         delay(500);
      }

      s_switch = true;
      prev_button_state = button_state; // сохранить последнее состояние
   }
   else if (prev_button_state == LOW && button_state == HIGH)
   {
      s_switch = false;
      prev_button_state = button_state; // сохранить последнее состояние
   }
}
