#include <TinyStepper_28BYJ_48.h>
#include <Wire.h>

#define LIDAR_ADDRESS 0x62 // LiDAR's I2C address
#define INIT_REG 0x00
#define INIT_DATA 0x04
#define TWO_BYTE 0x8f

// array of haptic motors
int motorPins[] = {A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15};


//#define HALL_EFFECT_PIN

//const int MOTOR_PIN_IN1 = 2;
//const int MOTOR_PIN_IN2 = 3;
//const int MOTOR_PIN_IN3 = 4;
//const int MOTOR_PIN_IN4 = 5;

//const int rev_steps = 2048;

//TinyStepper_28BYJ_48 stepper;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  for (int i = 0; i < 12; i++)
  {
    pinMode(motorPins[i], OUTPUT);
    analogWrite(motorPins[i], LOW);
  }
  
//  stepper.connectToPins(MOTOR_PIN_IN1, MOTOR_PIN_IN2, MOTOR_PIN_IN3, MOTOR_PIN_IN4);
//  stepper.setSpeedInStepsPerSecond(256);
//  stepper.setAccelerationInStepsPerSecondPerSecond(512);
  
  int setCount = 10;
//  digitalRead(HALL_EFFECT_PIN) == HIGH
//  while (setCount > 0)
//  {
//    stepper.moveRelativeInSteps(1);
//    setCount--;
//  }
}

void loop() {
//  stepper.setSpeedInStepsPerSecond(600);
//  stepper.setAccelerationInStepsPerSecondPerSecond(1000);
  int loopCount = 0;
  while(loopCount < 12)
  {
//    stepper.moveRelativeInSteps(2048/12);
    // if lidar measurement <= 150, write high signal to motor
    int lidarDist = getLidarDistance();
    Serial.println("Distance: " + String(lidarDist) + "cm");
    if (lidarDist <= 150)
    {
      Serial.println("The motor should be on: " + String(loopCount));
      delay(2000);
      analogWrite(motorPins[loopCount], 100);
      delay(2000);
    }
    analogWrite(motorPins[loopCount], LOW);
    loopCount++;
    delay(2000);
  }
  delay(2000);
  
}

int getLidarDistance()
{
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
     return distance;
//     Serial.println("Distance: " + String(distance) + "cm");
  }
  else
  {
     Serial.println("Error: Distance could not be read");
  }
  
  delay(800);
}
