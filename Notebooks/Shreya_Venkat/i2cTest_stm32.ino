#include <Wire.h>

#define LIDAR_ADDRESS 0x62 // LiDAR's I2C address
#define INIT_REG 0x00
#define INIT_DATA 0x04

void setup() {
  // setup code
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // attempt to initialize the LiDAR before communication
  Wire.beginTransmission(LIDAR_ADDRESS);
  Wire.write(INIT_REG);
  Wire.write(INIT_DATA);
  Wire.endTransmission();

  delay(10);

  // once initialization is successful, request data
  Wire.requestFrom(LIDAR_ADDRESS, 1);
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  delay(800);
}
