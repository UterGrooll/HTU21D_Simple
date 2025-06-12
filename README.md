# 🌡️ HTU21D_Simple

> Простая и лёгкая библиотека для работы с цифровым датчиком **HTU21D** по интерфейсу **I²C** (Wire) для Arduino и совместимых плат.

📦 **Версия библиотеки:** `v1.0.0`

---

## 📌 Возможности

- ✅ Поддержка температурного и влажностного сенсора **HTU21D**
- 🧰 Использует **"чистый" Wire**, без лишних зависимостей
- 📦 Лёгкая интеграция в любой Arduino-проект
- 🧪 Пример использования в папке [`examples/`](examples/)
- 🖼️ Схема подключения в папке [`schematics/`](schematics/)

---

## 🛠️ Установка

### Установка вручную (Arduino IDE)

1. Скачайте и распакуйте архив библиотеки (например, `HTU21D_Simple.zip`) в папку:

   ```
   C:\Users\<Ваше_Имя>\Documents\Arduino\libraries\HTU21D_Simple
   ```

2. Перезапустите Arduino IDE, если она была открыта.

3. Откройте пример из папки [`examples/`](examples/)

---

## 🔌 Подключение датчика

| HTU21D Pin | Arduino (Uno / Nano) |
|------------|----------------------|
| VCC        | 3.3V                 |
| GND        | GND                  |
| SDA        | A4                   |
| SCL        | A5                   |

📂 *См. полную схему подключения в папке [`schematics/`](schematics/)*

---

## 🧪 Пример использования

```cpp
#include "HTU21D_Simple.h"

HTU21D_Simple sensor;

void setup() {
  Serial.begin(9600);
  sensor.begin(); // Инициализация датчика
}

void loop() {
  float temperature = sensor.readTemperature();
  float humidity = sensor.readHumidity();

  Serial.print("T = ");
  Serial.print(temperature);
  Serial.print(" *C, H = ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000);
}
```

---

## 📘 API

| Метод                     | Описание                                                           |
|--------------------------|--------------------------------------------------------------------|
| `bool begin()`            | Инициализация I²C и датчика. Возвращает `true`, если датчик найден |
| `float readTemperature()` | Возвращает температуру в градусах Цельсия                          |
| `float readHumidity()`    | Возвращает относительную влажность в процентах                     |

---

## 🖼️ Скриншот (Serial Monitor)

```
T = 25.61 *C, H = 55.60 %
T = 25.62 *C, H = 55.62 %
```

---

## 💬 Планы на будущее

- [ ] Поддержка других сенсоров: AHT10, BME280, BMP280
- [ ] Совместимость с PlatformIO
- [ ] Поддержка нестандартных I²C-контроллеров
- [ ] Пример с OLED-дисплеем

---

## 🔐 Лицензия

[MIT License](LICENSE)

---

## 🙌 Автор

Разработано с ❤️ для платформ **Elbear Ace-Nano / Ace-Uno**