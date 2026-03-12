# Smart Hall Monitoring & Fire Alarm System

## Project Overview
This system monitors a hall for temperature, humidity, human presence, and smoke. It counts people entering using a color sensor, detects motion via a PIR sensor, and triggers alarms in case of smoke. Exit lights indicate the safe path during emergencies, and a buzzer alerts occupants in case of fire.

---

## System Functions

1. **Temperature & Humidity Monitoring**
   - Continuously measures the hall’s temperature and humidity using the DHT11 sensor.
   - Provides real-time data for safety and comfort monitoring.

2. **Motion Detection**
   - Detects human presence using a PIR sensor.
   - Automatically turns on hall lights when people are detected.

3. **People Counting**
   - Uses a TCS3200 color sensor to detect color-coded cards.
   - Counts people entering or leaving, keeping track of occupancy.

4. **Smoke / Fire Detection**
   - MQ-2 sensor monitors smoke levels.
   - Triggers a buzzer alarm and activates exit lights when smoke is detected.

5. **Exit Guidance**
   - Six LED lights sequentially blink to indicate safe exit paths during emergencies.
   - Enhances evacuation efficiency in case of fire.

---

## Applications

- **Smart Halls & Auditoriums** – Monitor occupancy and environmental conditions in real time.
- **Fire Safety Systems** – Immediate alert through buzzer and visual exit lights.
- **Event Management** – Track audience attendance and control lighting automatically.
- **Educational Facilities** – Teach IoT and safety automation using sensors and microcontrollers.
- **Industrial & Public Spaces** – Integrate environmental monitoring with emergency response systems.

---

## Components & Connections

| Component             | ESP32 Pin       | Notes / Description                  |
|----------------------|----------------|--------------------------------------|
| DHT11 (Temp & Humidity) | GPIO 2         | Data pin connected to ESP32          |
| PIR Motion Sensor      | GPIO 3         | Motion detection input                |
| Hall Light / LED       | GPIO 4         | Lights when motion detected          |
| Buzzer (Fire Alarm)    | GPIO 5         | Activates on smoke detection         |
| Exit LED 1             | GPIO 6         | Sequential blinking on fire          |
| Exit LED 2             | GPIO 7         | Sequential blinking on fire          |
| Exit LED 3             | GPIO 8         | Sequential blinking on fire          |
| Exit LED 4             | GPIO 9         | Sequential blinking on fire          |
| Exit LED 5             | GPIO 10        | Sequential blinking on fire          |
| Exit LED 6             | GPIO 13        | Sequential blinking on fire          |
| TCS3200 Color Sensor S2| GPIO 11        | Control pin                           |
| TCS3200 Color Sensor S3| GPIO 12        | Control pin                           |
| TCS3200 Color Sensor Out| A1            | Analog output for color reading       |
| MQ-2 Smoke Sensor      | A0             | Analog output for smoke level         |

**Power Supply Notes:**  
- ESP32: 5V / 3.3V (depending on board)  
- LEDs: connect in series with 220Ω resistors  
- Buzzer: active buzzer recommended (direct 5V/3.3V)  

---

## Conclusion

The **Smart Hall Monitoring & Fire Alarm System** provides an integrated approach to safety, occupancy management, and environmental monitoring. By combining sensors such as DHT11, PIR, TCS3200, and MQ-2 with a buzzer and LED exit indicators, the system enhances safety awareness and ensures timely response to emergencies. This project demonstrates the practical applications of IoT in smart building management and can be scaled or adapted for various environments, offering both educational value and real-world utility.

---

## Notes

- This project uses an ESP32 microcontroller for controlling all sensors and outputs.
- Buzzer is used instead of servo motor for fire alarm.
- Exit LEDs blink sequentially when smoke is detected to guide evacuation.
- Color sensor detects blue cards for people counting and green cards for admin access.
