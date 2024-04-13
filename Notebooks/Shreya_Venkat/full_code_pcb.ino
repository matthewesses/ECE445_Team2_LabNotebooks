#include <Wire.h>

#define LIDAR_ADDRESS 0x62 // LiDAR's I2C address
#define INIT_REG 0x00
#define INIT_DATA 0x04
#define TWO_BYTE 0x8f

// represents all pins that are connected to hall-effect sensors
int hallPins[] = {8, 9, 10, 11, 56, 57, 55, 52, 53, 4, 2, 3};

// represents all pins that are connected to motors
int motorPins[] = {14, 15, 16, 17, 20, 21, 22, 23, 41, 42, 43, 40};

// represents all values received from hall effect sensors
int hallVals[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

// represents all values written to motors
int motorVals[] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

void setup() {
  // setup code
  for (int i = 0; i < 12; i++)
  {
    pinMode(hallPins[i], INPUT);
  }
  for (int i = 0; i < 12; i++)
  {
    pinMode(motorPins[i], OUTPUT);
  }
  
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
     if (distance <= 150)
     {
        for (int i = 0; i < 12; i++)
        {
          hallVals[i] = digitalRead(hallPins[i]);
        }
        for (int i = 0; i < 12; i++)
        {
          motorVals[i] = ~(hallVals[i]);
          digitalWrite(motorPins[i], motorVals[i]);
        }
        delay(1000);
     }
  }
  else
  {
     Serial.println("Error: Distance could not be read");
  }
  
  delay(1000);
}
