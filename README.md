# Module 3.1 homework — Light Sensor with LED

## Task

1. Connect an LDR (light-dependent resistor) to the ESP32 as a voltage divider and connect its output to one of the ADC1 channels.
2. Connect an LED to any available GPIO.
3. Read values from the ADC in **oneshot** mode.
4. Implement a **Simple Moving Average (SMA)** to filter the light readings.
5. Using the filtered data:
   - when it gets dark, the LED turns **on**;
   - when it gets light, the LED turns **off**.
6. The LED must not flicker when the light level changes slightly.
7. Use **two thresholds (hysteresis)** to prevent flickering.
