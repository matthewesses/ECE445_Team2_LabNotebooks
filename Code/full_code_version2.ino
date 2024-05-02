#include <TinyStepper_28BYJ_48.h>
#include <Wire.h>

#define LIDAR_ADDRESS 0x62 // LiDAR's I2C address
#define INIT_REG 0x00
#define INIT_DATA 0x04
#define TWO_BYTE 0x8f

// array of haptic motors
int motorPins[] = {A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15};


#define HALL_EFFECT_PIN 8
#define DOPPLER_PIN A0

const int MOTOR_PIN_IN1 = 13;
const int MOTOR_PIN_IN2 = 12;
const int MOTOR_PIN_IN3 = 11;
const int MOTOR_PIN_IN4 = 10;

const int rev_steps = 2048;

TinyStepper_28BYJ_48 stepper;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  for (int i = 0; i < 12; i++)
  {
    pinMode(motorPins[i], OUTPUT);
    analogWrite(motorPins[i], LOW);
  }
  pinMode(DOPPLER_PIN, INPUT);
  pinMode(HALL_EFFECT_PIN, INPUT);
  pinMode(A4, OUTPUT);
  
  stepper.connectToPins(MOTOR_PIN_IN1, MOTOR_PIN_IN2, MOTOR_PIN_IN3, MOTOR_PIN_IN4);
  stepper.setSpeedInStepsPerSecond(256);
  stepper.setAccelerationInStepsPerSecondPerSecond(512);
  
  //int setCount = 10;
  while (digitalRead(HALL_EFFECT_PIN) == HIGH)
  {
    stepper.moveRelativeInSteps(1);
  }
  Serial.println("Done :)");
  delay(2000);
}

void loop() {
  stepper.setSpeedInStepsPerSecond(600);
  stepper.setAccelerationInStepsPerSecondPerSecond(1000);
  int loopCount = 0;
  while(loopCount < 12)
  {
    stepper.moveRelativeInSteps(2048/24);
    if (digitalRead(DOPPLER_PIN) == 0)
    {
      Serial.println("Doppler on!");
      analogWrite(motorPins[0], 255);
      delay(700);
      analogWrite(motorPins[0], LOW);
    }
    int lidarDist = getLidarDistance();
    Serial.println("Distance: " + String(lidarDist) + "cm");
    if (lidarDist <= 150)
    {
      Serial.println("The motor should be on: " + String(loopCount));
      analogWrite(motorPins[loopCount], 255);
      delay(700);
    }
    analogWrite(motorPins[loopCount], LOW);
    loopCount++;
    delay(700);
  }
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
