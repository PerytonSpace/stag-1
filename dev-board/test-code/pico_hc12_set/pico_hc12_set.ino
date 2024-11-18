//#define HWSERIAL Serial3
 #include <Arduino.h>
//#define HC12 Serial2 
//AT+B115200
//AT+C004
// OK+C004
// OK+B115200

void setup() {


  // Serial1.setTX(0);
  // Serial1.setRX(1);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);

  Serial2.setTX(8);
  Serial2.setRX(9);
  
  
  Serial.begin(115200);
  //Set Serial.begin(xxx to the same as HC12 when changing settings
  //Serial1.begin(9600);
  // GPS_SERIAL.begin(9600);
  //Serial2.begin(115200);
  Serial2.begin(115200);

  // Serial.begin(9600);

  // Serial1.begin(9600);
  delay(2000);
  Serial.println("START");

}

void loop() {
  // while (Serial1.available()) {
  //   Serial.write(Serial1.read());
  // }
  // while (Serial.available()) {
  //   Serial1.write(Serial.read());
  // }
  while (Serial2.available()) {
    Serial.write(Serial2.read());
  }
  while (Serial.available()) {
    Serial2.write(Serial.read());
  }

}
