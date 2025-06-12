````markdown
# 🌡️ HTU21D_Simple

> Простая и лёгкая библиотека для работы с цифровым датчиком **HTU21D** по интерфейсу **I²C** (Wire) для Arduino и совместимых плат.

📦 **Версия библиотеки**: `V-1.0.0`

---

## 📌 Возможности

- ✅ Поддержка температурного и влажностного сенсора **HTU21D**
- 🧰 Использует **"чистый" Wire**, без лишних зависимостей
- 📦 Лёгкая интеграция в любой проект
- 🧪 Пример использования в папке `examples/`
- 🖼️ Схема подключения в папке `schematics/`

---

## 🛠️ Установка

### 📁 Arduino IDE

1. Скачайте или клонируйте репозиторий:

```bash
   git clone https://github.com/your_username/HTU21D_Simple.git

```

2. Поместите папку `HTU21D_Simple` в директорию `libraries` вашей Arduino IDE:

   * Пример: `C:\Users\<Имя>\Documents\Arduino\libraries\`
3. Перезапустите Arduino IDE.
4. Откройте пример: **Файл > Примеры > HTU21D\_Simple > HTU21D\_Serial**

---

## 🔌 Подключение датчика

| HTU21D Pin | Elbear Ace-Nano / Uno |
| ---------- | --------------------- |
| VCC        | 3.3V                  |
| GND        | GND                   |
| SDA        | A4                    |
| SCL        | A5                    |

📂 *Полная схема подключения — в папке [`schematics/`](schematics/)*

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
| ------------------------- | ------------------------------------------------------------------ |
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

* [ ] Поддержка других сенсоров: AHT10, BME280, BMP280
* [ ] Совместимость с PlatformIO
* [ ] Поддержка нестандартных I²C контроллеров
* [ ] Пример с OLED-дисплеем

---

## 🙌 Автор

Разработано с ❤️ для платформ **Elbear Ace-Nano / Ace-Uno**