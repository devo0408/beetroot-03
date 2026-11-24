# Task 3.2 — ADC + potentiometer

## Task

1. Connect a potentiometer (~10 kΩ) as a voltage divider.
2. Take into account the reference voltage, attenuation and resolution. They can also be added to the table for information.
3. Configure the ADC and read a value every ~100 ms.
4. Take several measurements. For each measurement:
   - read the RAW ADC value and calculate the voltage using the formula;
   - read the voltage using the calibrated ADC;
   - calculate the error (%) between the calculated and the calibrated voltage.
5. Print a table to the serial console.

## Wiring

```
              ┌──────────────────────────────┐
 3V3 ─────┬───┤ 3V3                          │
          │   │                              │
       ┌──┴─┐ │                              │
       │    │ │                              │
       │POT │◄├─ wiper ──────────► PA1       │  ADC1_IN1
       │10k │ │                   (ADC1_IN1) │
       │    │ │                              │
       └──┬─┘ │                              │
          │   │                              │
 GND ─────┴───┤ GND                          │
              │                              │
              │ PA9  (USART1_TX) ────────────┼──► RX  ┐
              │ PA10 (USART1_RX) ◄───────────┼─── TX  │ USB-UART
              │ GND ─────────────────────────┼─── GND ┘ adapter ──► PC
              └──────────────────────────────┘
```

## Formulas

| Value | Formula |
|---|---|
| Calculated voltage | `v_raw = raw * 3.3 / 4095` |
| Real VDDA | `vdda = 3.3 * VREFINT_CAL / vrefint_raw` |
| Calibrated voltage | `v_cal = raw * vdda / 4095` |
| Error, % | `err = (v_raw - v_cal) / v_cal * 100` |
