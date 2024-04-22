#include <TinyStepper_28BYJ_48.h>

// array of haptic motors
int motorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11};


#define HALL_EFFECT_PIN

const int MOTOR_PIN_IN1 = 2;
const int MOTOR_PIN_IN2 = 3;
const int MOTOR_PIN_IN3 = 4;
const int MOTOR_PIN_IN4 = 5;

const int rev_steps = 2048;

TinyStepper_28BYJ_48 stepper;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  stepper.connectToPins(MOTOR_PIN_IN1, MOTOR_PIN_IN2, MOTOR_PIN_IN3, MOTOR_PIN_IN4);
  stepper.setSpeedInStepsPerSecond(256);
  stepper.setAccelerationInStepsPerSecondPerSecond(512);
//  int setCount = 10;
//  digitalRead(HALL_EFFECT_PIN) == HIGH
  while (digitalRead(HALL_EFFECT_PIN) == HIGH)
  {
    stepper.moveRelativeInSteps(1);
//    setCount--;
  }
}

void loop() {
  stepper.setSpeedInStepsPerSecond(600);
  stepper.setAccelerationInStepsPerSecondPerSecond(1000);
//  stepper.moveRelativeInSteps(2048 * 5);
  int loopCount = 0;
  while(loopCount < 12)
  {
    stepper.moveRelativeInSteps(2048/12);
    // if lidar measurement <= 150, write high signal to motor
    int lidarDist = getLidarDistance();
    if (lidarDist <= 150)
    {
      digitalWrite(motorPins[loopCount], HIGH);
      delay(5000);
    }
    loopCount++;
    digitalWrite(motorPins[loopCount], LOW);
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
