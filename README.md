# ESP32 Bluetooth HID Joystick Mouse

A DIY, wireless peripheral that turns an analog joystick and push buttons into a fully functional Bluetooth mouse. This project leverages the ESP32's BLE (Bluetooth Low Energy) capabilities to act as a standard Human Interface Device (HID).

##  Features
- **Wireless Connectivity:** Pairs with Windows, macOS, Android, and iOS via Bluetooth.
- **Precision Movement:** Analog joystick mapping with software-defined deadzones to prevent cursor drift.
- **Dual-Mode Center Click:** - **Short Press:** Left Click.
  - **Hold + Direction:** Vertical and Horizontal Scrolling.
- **Right Click:** Dedicated physical button.
- **Memory Optimized:** Uses the NimBLE stack for a lightweight footprint.

##  Components
- **Microcontroller:** ESP32 DevKit V1
- **Input:** 2-Axis Analog Joystick (KY-023)
- **Buttons:** 2x Tactile Push Buttons
- **Power:** USB-C/Micro-USB (or LiPo battery for true wireless)

- ##  Logic Flow
The project implements a custom timing logic to distinguish between a "Click" and a "Scroll" action using the same physical button:
1. **Idle:** Stick movement = Cursor movement.
2. **Button Down:** Starts a timer (`millis()`).
3. **Movement while Down:** If the stick moves beyond the deadzone while the button is held, the device switches to `Mouse.move(0,0,V,H)` mode (Scrolling).
4. **Release:** If released within 200ms without significant movement, a `MOUSE_LEFT` click is sent.
