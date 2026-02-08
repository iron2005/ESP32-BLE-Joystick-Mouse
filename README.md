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
