#include <Wire.h>

#define LIDAR_ADDRESS 0x62 // LiDAR's I2C address
#define INIT_REG 0x00
#define INIT_DATA 0x04
#define TWO_BYTE 0x8f

void setup() {
  // setup code
  Wire.begin();
  Serial.begin(9600);
}

void loop() {

  // initialize the LiDAR sensor to get accurate measurements
  Wire.beginTransmission((int)LIDAR_ADDRESS);
  Wire.write((int)INIT_REG);
  Wire.write((int)INIT_DATA);
  Wire.endTransmission();

  delay(20);

  // send the register that needs to be read from: 0x8f
  Wire.beginTransmission((int)LIDAR_ADDRESS);
  Wire.write((int)TWO_BYTE);
  Wire.endTransmission();
  
  delay(20);
   
  // request data from the TWO_BYTE register
  int distance = 0;
  Wire.requestFrom((int)LIDAR_ADDRESS, 2);
  if (Wire.available() >= 2) {
     int upperByte = Wire.read(); //read upper 8 bits
     upperByte = upperByte << 8; //shift to make room for lower 8 bits
     int lowerByte = Wire.read(); //read lower 8 bits
     distance = upperByte | lowerByte; //combine to create final distance value
     Serial.println("Distance: " + String(distance) + "cm");
  }
  else
  {
     Serial.println("Error: Distance could not be read");
  }
  
  delay(800);
}
