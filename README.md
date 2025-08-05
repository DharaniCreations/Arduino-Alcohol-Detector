# 🍷 Arduino Alcohol Detector using MQ-3 Sensor

This project demonstrates how to create a simple and functional **alcohol detection system** using an **Arduino** and an **MQ-3 gas sensor**. The system detects the presence of alcohol vapor (ethanol) and alerts the user via **LED indicators**, a **buzzer**, and serial output. It’s a great beginner-friendly project to learn about gas sensors, analog input reading, and simple embedded alert systems.

---

## 📦 Components Required

| Component         | Quantity |
|------------------|----------|
| Arduino Uno/Nano | 1        |
| MQ-3 Alcohol Sensor | 1     |
| Red LED (Alert)  | 1        |
| Green LED (Safe) | 1        |
| 220Ω Resistors   | 2        |
| Buzzer (optional)| 1        |
| Jumper Wires     | As needed |
| Breadboard       | 1        |

---

## ⚙️ How It Works

- The **MQ-3 sensor** outputs an analog voltage based on the alcohol concentration in the air.
- The **Arduino reads** the analog value using the **A0 pin**.
- If the sensor value exceeds a **predefined threshold**, the red LED and buzzer are activated.
- If the value is below the threshold, the green LED remains ON.
- The sensor values are also printed in the **Serial Monitor** for testing and calibration.

---

## 🔌 Circuit Connections

### MQ-3 Sensor:
- **VCC** → 5V  
- **GND** → GND  
- **AOUT** → A0 (Analog Input)

### LEDs:
- **Green LED**: Anode → D8, Cathode → GND via 220Ω resistor  
- **Red LED**: Anode → D9, Cathode → GND via 220Ω resistor

### Buzzer (Optional):
- Positive → D10  
- Negative → GND

---

## 💻 Arduino Code

```cpp
const int sensorPin = A0;
const int greenLED = 8;
const int redLED = 9;
const int buzzer = 10; // optional
const int threshold = 300; // Calibrate for accuracy

void setup() {
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Alcohol Level: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, LOW);
  }

  delay(500);
}
