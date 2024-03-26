#include <Wire.h>

#define LIDAR_ADDRESS 0x62 // LiDAR's I2C address
#define INIT_REG 0x00
#define INIT_DATA 0x04

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(LIDAR_ADDRESS);
  Wire.write(INIT_REG);
  Wire.write(INIT_DATA);
  Wire.endTransmission();

  delay(10);
  
  Wire.requestFrom(LIDAR_ADDRESS, 1);
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  delay(800);
}
