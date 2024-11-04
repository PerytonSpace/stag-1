/*
    This code is for Raspberry Pi pico in Arduino IDE. Tested on breadboard 
    with pico, MPU6050, and a passive buzzer in Oct. 2024.
    
    Features:
        - when the MPU6050's data is outside the boundary, the buzzer sounds.
*/

#include <Wire.h>

#define MPU6050_ADDR 0x68  // MPU6050 I2C address
#define BUZZER_PIN 15      // Buzzer connected to GP15
#define X_THRESHOLD 20000  // Define threshold range for x-axis
#define Y_THRESHOLD 20000  // Define threshold range for y-axis
#define Z_THRESHOLD 20000  // Define threshold range for z-axis

void setup() {
  Wire.begin();
  Serial.begin(9600);           // Initialize Serial Monitor
  pinMode(BUZZER_PIN, OUTPUT);  // Set buzzer pin as output

  // Initialize MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B);             // Access the power management register
  Wire.write(0x00);             // Wake the MPU6050 up
  Wire.endTransmission();
}

void loop() {
  int16_t accX, accY, accZ;

  // Request data from MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B); // Starting register for accel data
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 6, true);

  // Read accelerometer values
  accX = (Wire.read() << 8 | Wire.read());  // X-axis value
  accY = (Wire.read() << 8 | Wire.read());  // Y-axis value
  accZ = (Wire.read() << 8 | Wire.read());  // Z-axis value

  // Print axis values to console
  Serial.print("X: "); Serial.print(accX);
  Serial.print(" | Y: "); Serial.print(accY);
  Serial.print(" | Z: "); Serial.println(accZ);

  // Check if values are outside the thresholds
  if (abs(accX) > X_THRESHOLD || abs(accY) > Y_THRESHOLD || abs(accZ) > Z_THRESHOLD) {
    digitalWrite(BUZZER_PIN, HIGH);  // Sound the buzzer
    Serial.println("Buzzer ON - Threshold exceeded!");
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Turn off the buzzer
    Serial.println("Buzzer OFF - Within threshold.");
  }

  delay(100);  // Adjust delay as needed for readability
}