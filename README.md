# **Project Work I**  
## **Arduino Bluetooth-Controlled RC Car with ESP32-CAM Upgrade Attempt**

**Submitted To:**  
**Md. Shadmim Hassan Sifat**  
Lecturer, Department of CSE, SUST  

**Submitted By:**  
**Md. Meheduz Zaman**  
Reg: 2023331064  
Department of CSE, SUST  

---

##**Project Overview**
This project presents a **Bluetooth-controlled RC car using Arduino**, later extended with an **ESP32-CAM module** to attempt **live video streaming**.  
All **Bluetooth features are fully working** — motor control, lights, horn, speed levels, and braking.  

In the **upgrade stage**, I tried to integrate **video streaming** using ESP32-CAM. Unfortunately, due to **camera module failure**, streaming could not be shown in the final demo — but I continued testing until the end and documented the process.

---

##**Working Features (Arduino Version – Fully Functional)**  
- Forward & backward movement  
- Left & right turning  
- Speed control (PWM)  
- Electronic brake using `'S'` command  
- Controlled via Bluetooth using mobile/PC app  

---

##**Hardware Used**

| Component | Purpose |
|-----------|--------|
| Arduino UNO | Main controller |
| L298N Motor Driver | Controls motors |
| DC Motors (×2) | Movement |
| HC-05 Bluetooth | Wireless control |
| Battery Pack | Power Supply |
| ESP32-CAM *(upgrade attempt)* | Video streaming (not working due to camera module issue) |

---

##**Bluetooth Command List**

| Command | Action |
|--------|-------|
| `F` | Forward |
| `B` | Backward |
| `L` | Left |
| `R` | Right |
| `S` | Brake / Stop |
| `W` / `w` | Front LED ON / OFF |
| `U` / `u` | Back LED ON / OFF |

---

##**How to Use**
1. Connect all hardware components
2. Upload Arduino code from Arduino IDE
3. Pair Bluetooth module with phone/PC
4. Send commands from any Bluetooth terminal app
5. Car will respond instantly

---

##**Working Demo**
**Watch Arduino Version Video:**  
https://drive.google.com/file/d/1i5NKKOEtDWRbgiqOLpSNPt2c54TIfO-Y/view?usp=share_link

---

##**ESP32-CAM Video Streaming Attempt**

### **Goal:**  
Add live camera feed using ESP32-CAM.  
Tested using Wi-Fi streaming & raw RGB methods.

### **Tried Approaches:**
- MJPEG streaming via Wi-Fi  
- Raw RGB data streaming to PC  
- Python OpenCV testing  
- Pin reconfiguration tests  

### **Issue Faced:**  
The module returned camera initialization error.  
So streaming could not be completed:
I tested until the last stage — but the hardware issue prevented final streaming output.

---

##**Conclusion**
- **Bluetooth RC Car is fully successful.**
- **ESP32-CAM upgrade was attempted seriously**, but due to camera failure, streaming wasn’t possible.
- The project is working and ready for submission.
- Camera upgrade can be continued later with a new module.

---

##**Future Scope**
- Fix / replace camera module  
- Add IoT remote control using internet  
- Create Android app for UI control  
- Add ultrasonic obstacle detection  
- GPS + tracking system  

---

Engineering means trying, failing, and pushing forward.  
The car **moved**, **blinked**, **honked**, and **almost saw** —  
the next version will definitely see.

---
