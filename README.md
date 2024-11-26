# **Smart Parking System**
A simulation project for a Smart Parking System integrating Mobile App, ESP32 microcontroller, and Firebase Realtime Database to optimize parking space management.

---

## **Table of Contents**
- [**Smart Parking System**](#smart-parking-system)
  - [**Table of Contents**](#table-of-contents)
  - [**Overview**](#overview)
  - [**Features**](#features)
  - [**System Architecture**](#system-architecture)
  - [**Tools and Technologies**](#tools-and-technologies)
    - [**IoT Hardware**](#iot-hardware)
    - [**Mobile Application**](#mobile-application)
    - [**Development Tools**](#development-tools)
  - [**How It Works**](#how-it-works)
  - [**Future Enhancements**](#future-enhancements)
  - [**Contributors**](#contributors)
  - [**Contributing**](#contributing)
  - [**License**](#license)

---

## **Overview**
The Smart Parking System aims to address urban parking challenges by providing real-time updates on parking slot availability. Using ESP32 and ultrasonic sensors, the system dynamically updates a Firebase Realtime Database, which communicates with a mobile app to notify users of parking availability and automate gate operations.

---

## **Features**
- **Real-Time Slot Availability:**
  - Displays the availability of parking slots through a mobile app interface.
- **Automated Gate Operation:**
  - Opens only when a slot is available.
  - Prevents entry when the parking is full.
- **Ultrasonic-Based Detection:**
  - Detects vehicle presence in parking slots and updates the system.
- **Firebase Integration:**
  - Ensures live synchronization between the parking lot hardware and the mobile app.
- **Mobile App GUI:**
  - Provides an intuitive interface for users to view parking slot statuses.

---

## **System Architecture**
The system comprises three key components:
1. **IoT Hardware:**
   - ESP32 microcontroller for communication and control.
   - Ultrasonic sensors for detecting parking slot occupancy.
   - Servo motor for gate automation.
2. **Backend:**
   - Firebase Realtime Database to store and manage parking data.
3. **Frontend:**
   - Mobile application built with Java, integrated with Firebase to display real-time data.

---

## **Tools and Technologies**
### **IoT Hardware**
- ESP32 Microcontroller
- Ultrasonic Sensors
- Servo Motor
- Jumper Wires
- Power Supply

### **Mobile Application**
- **Language:** Java
- **Database:** Firebase Realtime Database
- **IDE:** Android Studio

### **Development Tools**
- Arduino IDE for programming the ESP32
- Firebase Console for managing the database
- Android Studio for mobile app development

---

## **How It Works**
1. **Slot Availability Check:**
   - Ultrasonic sensors detect the presence or absence of vehicles in parking slots.
   - Data is sent to the ESP32 microcontroller, which updates Firebase.
2. **Gate Automation:**
   - If a slot is available, the gate opens automatically upon vehicle detection at the entry.
   - If no slots are available, the gate remains closed, and a notification is displayed.
3. **Mobile App Updates:**
   - Firebase pushes real-time data to the mobile app.
   - The app GUI updates to show the current parking slot status.
4. **Dynamic Parking Slot Management:**
   - When a vehicle parks in a slot, the system marks it as occupied, updating both the database and the app.

---

## **Future Enhancements**
- **Payment Integration:**
  - Add automated billing and payment for parking.
- **Advanced Sensors:**
  - Upgrade to image-based sensors for enhanced accuracy.
- **Navigation Assistance:**
  - Provide directions to the nearest available slot.
- **Scalability:**
  - Expand the system to manage multi-level parking lots.

---
## **Contributors**
This project was collaboratively developed by the following team members:

- [Lakmal][SEU_IS_18_ICT_026](https://www.linkedin.com/in/lakmal133571bb/)
- [Sandun][SEU_IS_18_ICT_004](https://www.linkedin.com/in/sandun-dilshan-783b1b201?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app)
- [Muditha][SEU_IS_18_ICT_69]()
- [Kavindu][SEU_IS_18_ICT_068]()


## **Contributing**
We welcome contributions to enhance the Smart Parking System. To contribute:
1. Fork the repository.
2. Create a new branch for your feature or fix.
3. Commit your changes and push them to your fork.
4. Submit a pull request with a detailed explanation.

---

## **License**
This project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute this project in accordance with the license terms.

---

Thank you for exploring the **Smart Parking System** project. For any queries or feedback, feel free to open an issue or contact us.
