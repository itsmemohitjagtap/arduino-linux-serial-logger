# Linux Arduino Data Logger

A simple Linux-based serial data logging system using Arduino and C.

This project demonstrates how Linux treats serial ports as files and how sensor data can be logged efficiently using the Linux file system without complex system APIs.

---

## 📌 Project Overview

- Arduino reads distance data from an ultrasonic sensor
- Detection data is sent over USB serial
- Linux reads the serial port (`/dev/ttyUSB*`) as a file
- A C program logs timestamped data into a CSV file
- Data is logged only when the distance value changes

This project helped me understand **real-world OS–hardware interaction** instead of relying on GUI tools like Serial Monitor.

---

## 🔑 Key Learnings

- Only **one process** can access a serial port at a time
- Serial ports in Linux behave like **regular files**
- File reading and appending in Linux is simple and powerful
- Linux avoids heavy APIs required in Windows for serial communication
- Difference between monitoring data and **real data logging**
- Practical use of Linux file system concepts

---

## ⚙️ How It Works

1. Ultrasonic sensor measures distance
2. Arduino sends detection data via Serial
3. Linux reads the serial port as a file
4. C program parses the data
5. Timestamp is added
6. Data is appended to a CSV log file

---

## 🛠 Build & Run (Linux)

```bash
gcc linux/serial_logger.c -o serial_logger
stty -F /dev/ttyUSB0 9600 raw
./serial_logger
````````````````````````
---
##🧰 Hardware Used

Atmega328P
Ultrasonic Sensor (HC-SR04)
USB Cable (for serial communicatoin)
Ubuntu Linux (22.04 LTS)

---

## 🧑‍💻 Designed By

- **Mohit Jagtap**
- Electronics & Telecommunication Engineering
- Dr. D. Y. Patil Institute of Engineering Management and Research
- Akurdi, Pune

