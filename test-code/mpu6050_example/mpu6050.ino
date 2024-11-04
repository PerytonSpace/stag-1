/*
    MPU6050 (accelerometer) and Raspberry Pi Pico in Arduino IDE. Tested on breadboard
    and the Dev Board.

    Features:
        - output data from MPU6050 in Serial Monitor.
*/

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);
  while (!Serial) {
    delay(10); // will pause Zero, Leonardo, etc until serial console opens
  }

  // On Peryton Dev Board
  Wire.setSDA(8);
  Wire.setSCL(9);
  
  // On breadbord or others
  // Wire.setSDA(20);
  // Wire.setSCL(21);
  
  // !! CHECK THE ADDRESS [0x68] - normal, [0x69] - on Peryton Dev Board
  if (!mpu.begin(0x69,&Wire,0)) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("");
  delay(100);
}

void loop() {

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  Serial.print("AccelX:");
  Serial.print(a.acceleration.x);
  Serial.print(",");
  Serial.print("AccelY:");
  Serial.print(a.acceleration.y);
  Serial.print(",");
  Serial.print("AccelZ:");
  Serial.print(a.acceleration.z);
//  Serial.print(", ");
//  Serial.print("GyroX:");
//  Serial.print(g.gyro.x);
//  Serial.print(",");
//  Serial.print("GyroY:");
//  Serial.print(g.gyro.y);
//  Serial.print(",");
//  Serial.print("GyroZ:");
//  Serial.print(g.gyro.z);
  Serial.println("");

  delay(50);
}