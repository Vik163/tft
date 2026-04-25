
#include <header.hpp>

// LiquidCrystal_I2C lcd(0x27, 16, 2);

// byte charSh[] = {
//     0x00,
//     0x00,
//     0x15,
//     0x15,
//     0x15,
//     0x15,
//     0x1F,
//     0x00};

// byte charD[] = {
//     0x0E,
//     0x0A,
//     0x0A,
//     0x0A,
//     0x0A,
//     0x0A,
//     0x1F,
//     0x11};
// byte charN[] = {
//     0x00,
//     0x00,
//     0x11,
//     0x11,
//     0x1F,
//     0x11,
//     0x11,
//     0x00};
// byte charHeat[] = {
//     0x0A,
//     0x05,
//     0x05,
//     0x0A,
//     0x14,
//     0x14,
//     0x0A,
//     0x00};

// // слово сауна (curs положение курсора)
// void writeSauna()
// {
//    lcd.createChar(2, charN);
//    lcd.createChar(1, charHeat);

//    lcd.setCursor(0, 0);
//    lcd.print("Cay");
//    lcd.setCursor(3, 0);
//    lcd.write(2);
//    lcd.setCursor(4, 0);
//    lcd.print("a");
// }

// // слово душ (curs положение курсора)
// void writeShower()
// {
//    lcd.createChar(3, charD);
//    lcd.createChar(4, charSh);

//    lcd.setCursor(0, 1);
//    lcd.write(3);
//    lcd.setCursor(1, 1);
//    lcd.print("y");
//    lcd.setCursor(2, 1);
//    lcd.write(4);
// }

// void setDisplay()
// {
//    lcd.begin();
//    lcd.backlight();
//    lcd.home();
//    lcd.clear();

//    writeSauna();
//    writeShower();
// }

// // рисует установленную температуру
// void writeDefT()
// {
//    lcd.setCursor(6, 0);
//    lcd.print(def_temp);
// }

// // рисует установленную температуру с нагревом
// void writeHeat()
// {
//    lcd.setCursor(9, 0);
//    lcd.write(1);
//    writeDefT();
// }

// // удаляет с экрана установленную температуру с нагревом при полном отключении с кнопки или с телефона.
// // либо удаляет только нагрев при остывании
// void delHeat()
// {
//    if (!k_switch)
//    {
//       lcd.setCursor(6, 0);
//       lcd.print(" ");
//       lcd.setCursor(7, 0);
//       lcd.print(" ");
//    }

//    lcd.setCursor(9, 0);
//    lcd.print(" ");
// }

// void loopDisplay(int i, float temperature)
// {
//    String strT = String(round(temperature * 10) / 10);

//    // температура с двух датчиков (i - номер датчика)
//    lcd.setCursor(12, i);
//    lcd.print(strT);
// }

// // else if (show == 1)
// // {
// //   lcd.clear();
// //   lcd.print("Cursor On");
// //   lcd.cursor();
// // }
// // else if (show == 2)
// // {
// //   lcd.clear();
// //   lcd.print("Cursor Blink");
// //   lcd.blink();
// // }
// // else if (show == 3)
// // {
// //   lcd.clear();
// //   lcd.print("Cursor OFF");
// //   lcd.noBlink();
// //   lcd.noCursor();
// // }
// // else if (show == 4)
// // {
// //   lcd.clear();
// //   lcd.print("Display Off");
// //   lcd.noDisplay();
// // }
// // else if (show == 5)
// // {
// //   lcd.clear();
// //   lcd.print("Display On");
// //   lcd.display();
// // }