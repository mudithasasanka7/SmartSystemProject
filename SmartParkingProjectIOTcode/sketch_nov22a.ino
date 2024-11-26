#include <WiFi.h>
#include <FirebaseESP32.h>
#include <ESP32Servo.h>

// Replace with your network credentials
const char* ssid = "Redmi Note 13 Pro+ 5G";
const char* password = "11115555";

// Firebase project details
#define FIREBASE_HOST "smart-parking-system-b0b1a-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "AIzaSyDu_vQoGLoiNFrwEtSYPbnhi_W724MqjPg"

// Define pins for the primary ultrasonic sensor
#define TRIG_PIN 13
#define ECHO_PIN 12

// Define pins for additional ultrasonic sensors
int trigPins[] = {27, 25, 32, 34};
int echoPins[] = {26, 33, 35, 18};

// Define servo motor pin
#define SERVO_PIN 14

// Create pointers for FirebaseConfig and FirebaseAuth
FirebaseConfig firebaseConfig;
FirebaseAuth firebaseAuth;

// Create a FirebaseData object to interact with Firebase
FirebaseData firebaseData;

// Create a Servo object
Servo gateServo;

// Function to measure distance from a given ultrasonic sensor
float getStableDistance(int trigPin, int echoPin) {
  long duration;
  float distance;
  float total = 0;
  int samples = 5; // Number of readings for averaging

  for (int i = 0; i < samples; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration * 0.034) / 2; // Convert to cm
    total += distance;
    delay(10); // Small delay between samples
  }

  return total / samples; // Return average distance
}

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  // Set Firebase configuration
  firebaseConfig.host = FIREBASE_HOST;
  firebaseConfig.api_key = FIREBASE_AUTH;

  // If no authentication, leave these blank
  firebaseAuth.user.email = "sandun@gmail.com";
  firebaseAuth.user.password = "123456";

  // Initialize Firebase
  Firebase.begin(&firebaseConfig, &firebaseAuth);

  if (Firebase.ready()) {
    Serial.println("Connected to Firebase!");
  } else {
    Serial.println("Failed to connect to Firebase.");
  }

  // Configure ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  for (int i = 0; i < 4; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
  }

  // Attach servo to the pin
  gateServo.attach(SERVO_PIN);
  gateServo.write(0); // Ensure gate is initially closed
}

void loop() {
  // Measure distance from the primary sensor
  float primaryDistance = getStableDistance(TRIG_PIN, ECHO_PIN);
  Serial.print("Distance from primary sensor: ");
  Serial.print(primaryDistance);
  Serial.println(" cm");

  // Control the servo motor based on distance
  if (primaryDistance <= 10.0) {
    Serial.println("Object detected within 10 cm. Opening gate...");
    gateServo.write(90);  // Open gate
    delay(5000);          // Keep gate open for 5 seconds
    Serial.println("Closing gate...");
    gateServo.write(0);   // Close gate
  }

  // Measure and send data for additional sensors
  for (int i = 0; i < 4; i++) {
    float distance = getStableDistance(trigPins[i], echoPins[i]);
    String path = "/space" + String(i + 1) + "/status";
    bool status = distance >= 10.0; // Detect if within 70 cm

    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(distance);
    Serial.println(" cm");

    if (Firebase.setBool(firebaseData, path, status)) {
      Serial.println("Data successfully sent to Firebase");
    } else {
      Serial.println("Failed to send data to Firebase");
      Serial.println("Error: " + firebaseData.errorReason());
    }

    delay(50); // Prevent interference between sensors
  }

  delay(1000); // Delay between loops
}
