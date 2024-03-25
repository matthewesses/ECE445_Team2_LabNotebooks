#include <Wire.h>

#define LIDAR_ADDRESS 0x62 // LiDAR's I2C address

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(LIDAR_ADDRESS, 3);
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  delay(800);
}
