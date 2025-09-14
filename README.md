# Arduino Bluetooth Control Car

## Description
This project is a Bluetooth-controlled RC car using an Arduino. Commands sent from a mobile app or PC control the car's movement, lights, horn, and electronic braking system.

## Features
- Forward and backward motor control
- Left and right turning (with adjustable turn radius)
- Front, back, and parking LED lights control
- Horn on/off control
- Multiple speed levels (low to high)
- Electronic brake with the 'S' command for instant stopping

## Hardware Requirements
- Arduino board (UNO/Nano/any PWM-supported board)
- Motor driver (e.g., L298N)
- Two DC motors (left and right side)
- LEDs (front, back, parking) with resistors
- Horn or buzzer
- Bluetooth module (HC-05 or equivalent)
- Power supply (battery or adapter)

## Usage
1. Connect the hardware: motors, LEDs, horn, and Bluetooth module to the appropriate Arduino pins.
2. Upload the Arduino code using the Arduino IDE (select correct BOARD and PORT).
3. Pair your mobile/PC app with the Bluetooth module.
4. Send character commands from the app, e.g.:
   - `'F'` = Forward
   - `'B'` = Backward
   - `'L'` = Left
   - `'R'` = Right
   - `'W'` = Front LED On
   - `'w'` = Front LED Off
   - `'U'` = Back LED On
   - `'u'` = Back LED Off
   - `'V'` = Horn On
   - `'v'` = Horn Off
   - `'S'` = Brake
5. The car responds to the commands accordingly.

## Video Demo
[Watch the project video](https://drive.google.com/file/d/1i5NKKOEtDWRbgiqOLpSNPt2c54TIfO-Y/view?usp=share_link)
