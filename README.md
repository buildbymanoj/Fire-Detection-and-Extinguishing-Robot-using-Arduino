# 🔥 Flame Detection and Extinguishing Robot using Arduino

This project is an autonomous firefighting robot built using Arduino. It detects flames using analog flame sensors positioned at the front, left, and right of the robot. When fire is detected in any direction, it stops and activates a servo-mounted water pump to extinguish the fire by spraying in a sweeping motion. The robot uses an L298N motor driver for movement and can also make direction-based turns if necessary.

## 🚀 Features

- Detects fire using flame sensors
- Direction-specific fire extinguishing with servo sweep
- Activates water pump during firefighting
- Autonomous motion and directional control
- Serial output of flame sensor values for debugging

## 🧰 Components Used

- Arduino Uno/Nano
- Flame Sensors (3x)
- L298N Motor Driver
- DC Motors (2x)
- Servo Motor (e.g., SG90)
- Water Pump Module
- Power Supply (LiPo or 9V Battery)
- Chassis, Wheels, Water Tank
- Connecting Wires

## 🔌 Pin Configuration

| Component         | Arduino Pin |
|------------------|-------------|
| Motor ENA        | D10         |
| Motor IN1        | D9          |
| Motor IN2        | D8          |
| Motor IN3        | D7          |
| Motor IN4        | D6          |
| Motor ENB        | D5          |
| Flame Sensor Right | A0        |
| Flame Sensor Front | A1        |
| Flame Sensor Left  | A2        |
| Servo Motor      | D3          |
| Water Pump       | A5          |

## 📋 Working Principle

1. On startup, the servo performs a sweep for calibration.
2. Flame sensors constantly read analog values:
   - If flame detected in front (`A1`): Spray straight with center sweep.
   - If flame detected on right (`A0`): Spray right and sweep.
   - If flame detected on left (`A2`): Spray left and sweep.
3. If no flame is detected:
   - If mid-range sensor values are detected: move forward and turn accordingly.
   - Otherwise, robot stops and keeps spraying water as a precaution.
4. All sensor readings are logged to the Serial Monitor.

## 📟 Flame Sensor Thresholds (Adjust as needed)

- Flame Detected:
  - Front (`s2 < 200`)
  - Right (`s1 < 100`)
  - Left (`s3 < 100`)
- Movement Range:
  - `101 ≤ sensor value ≤ 800` → indicates possible signal reflection or safe zone.

## 🔧 Key Functions in Code

- `servoPulse(pin, angle)` – Generates PWM to rotate the servo motor
- `forword()` – Moves robot forward
- `turnLeft()` / `turnRight()` – Turns robot
- `Stop()` – Stops robot movement
- Pump is controlled using `digitalWrite(pump, HIGH/LOW)`

## 🧪 How to Use

1. Wire all components as per the above pin configuration.
2. Upload the Arduino sketch from `fire_bot.ino` (or equivalent file).
3. Power the system using a battery pack.
4. Place a candle or lighter flame in front of the robot and observe its behavior.
5. Use the Serial Monitor at 9600 baud to see sensor values and debug.

## 🧠 Tips for Better Results

- Adjust sensor angle slightly outward for wider flame detection.
- Fine-tune threshold values for your specific flame sensors.
- Use a small water container and low-voltage pump for safe demo.

## 💡 Future Improvements

- Add ultrasonic sensor for obstacle detection
- Use flame sensors with digital output for simpler detection
- Add temperature sensor or smoke sensor for multi-parameter firefighting
- Include a buzzer or LED indicator when fire is detected

---

> ⚠️ **Disclaimer**: This robot is meant for educational and demonstration purposes only. Do not use with large or uncontrolled fires. Always test in a safe and supervised environment.

