/*
  Пример использования библиотеки HTU21D_Simple для работы с датчиком HTU21D на платах
  Elbear Ace-Nano и Ace-UNO.
  Подключение датчика:
  - SDA (данные) подключается к A4 (Ace-Nano/UNO).
  - SCL (тактовый сигнал) подключается к A5 (Ace-Nano/UNO).
  - VCC — к 3.3V, GND — к земле платы.
  Функции библиотеки:
  - begin(): инициализация датчика, возвращает true при успешном подключении.
  - readTemperature(): возвращает температуру в градусах Цельсия.
  - readHumidity(): возвращает относительную влажность в процентах.
  - `V-1.0.0`
*/
#include "HTU21D_Simple.h"
HTU21D_Simple sensor;
unsigned long previousMillis = 0;
const unsigned long interval = 2000; // Интервал между измерениями (мс)
void setup() {
  Serial.begin(9600);
  if (!sensor.begin()) {
    Serial.println("HTU21D не найден. Проверьте соединение.");
    while (1); // Остановить выполнение
  }
  Serial.println("HTU21D инициализирован успешно!");
}
void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    float temp = sensor.readTemperature();
    float hum = sensor.readHumidity();
    Serial.print("T = ");
    Serial.print(temp, 2); // 2 знака после запятой
    Serial.print(" *C, H = ");
    Serial.print(hum, 2); // 2 знака после запятой
    Serial.println(" %");
  }
}
