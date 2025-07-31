# Smart Energy Meter using ESP32

This project uses an ESP32 to measure energy consumption (voltage, current) and display real-time stats on a web dashboard. Data is also pushed to the cloud via MQTT.

## Features:
- Wi-Fi enabled ESP32 firmware
- OLED display for local monitoring
- MQTT publishing to broker
- Web dashboard to visualize real-time data

## Hardware:
- ESP32
- ACS712 Current Sensor
- ZMPT101B Voltage Sensor
- OLED Display (I2C)
- Optional: SD Card Module, RTC Module

## Web Dashboard:
- Simple React/HTML UI for real-time monitoring
- Node-RED or Flask backend to collect and serve data

MIT License.
