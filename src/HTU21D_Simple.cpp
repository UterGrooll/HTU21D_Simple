// Класс для работы с датчиком HTU21D через I2C
#include "HTU21D_Simple.h"
#include <Wire.h>

// Конструктор класса, принимает I2C-адрес датчика
HTU21D_Simple::HTU21D_Simple(uint8_t address) {
  _address = address; // Сохраняем адрес датчика
}

// Инициализация датчика и шины I2C
bool HTU21D_Simple::begin() {
  Wire.begin(); // Запуск I2C
  Wire.beginTransmission(_address); // Начало передачи к датчику
  return (Wire.endTransmission() == 0); // Проверка успешности связи
}

// Чтение температуры с датчика
float HTU21D_Simple::readTemperature() {
  Wire.beginTransmission(_address); // Начало передачи
  Wire.write(0xE3);  // Команда на чтение температуры
  Wire.endTransmission(); // Завершение передачи
  delay(50); // Ожидание готовности данных
  Wire.requestFrom(_address, (uint8_t)3); // Запрос 3 байт (2 данных + 1 CRC)
  if (Wire.available() < 2) return NAN; // Проверка наличия данных
  uint16_t t = Wire.read() << 8 | Wire.read(); // Считывание двух байт температуры
  return -46.85 + 175.72 * t / 65536.0; // Преобразование в градусы Цельсия
}

// Чтение влажности с датчика
float HTU21D_Simple::readHumidity() {
  Wire.beginTransmission(_address); // Начало передачи
  Wire.write(0xE5);  // Команда на чтение влажности
  Wire.endTransmission(); // Завершение передачи
  delay(50); // Ожидание готовности данных
  Wire.requestFrom(_address, (uint8_t)3); // Запрос 3 байт (2 данных + 1 CRC)
  if (Wire.available() < 2) return NAN; // Проверка наличия данных
  uint16_t h = Wire.read() << 8 | Wire.read(); // Считывание двух байт влажности
  return -6.0 + 125.0 * h / 65536.0; // Преобразование в относительную влажность (%)
}
