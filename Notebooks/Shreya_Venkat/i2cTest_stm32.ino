#include <Wire.h>

#define LIDAR_ADDRESS 0x62 // LiDAR's I2C address
#
#define INIT_REG 0x00
#define INIT_DATA 0x04
#define UPPER_DIST_REG 0x0F
#define LOWER_DIST_REG 0x10

bool initialized = false;

void setup() {
  // setup code
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  // attempt to initialize the LiDAR before communication
  if (!initialized)
  {
    Wire.beginTransmission(LIDAR_ADDRESS);
    Wire.write(INIT_REG);
    Wire.write(INIT_DATA);
    if (Wire.endTransmission() != 0)
    {
      Serial.println("Error: Initialization Failed");
      delay(1000);
      return;
    }
    else
    {
      Serial.println("Initialization Success");
      initialized = true;
    }
  }
  else
  {
    Serial.println("Reached Part 2");
    Wire.beginTransmission(LIDAR_ADDRESS);
    Wire.write(UPPER_DIST_REG);
    if (Wire.endTransmission() != 0)
    {
      Serial.println("Error: Read request failed");
      delay(500);
      return;
    }
    delay(40);
    // once initialization is successful, request data
    Wire.requestFrom(LIDAR_ADDRESS, 1);
    if (Wire.available()) {
      byte c = Wire.read();
      Serial.print("Data read: ");
      Serial.print(c);
      Serial.println();
    }
    else
    {
      Serial.println("Error: Data not read");
    }
  }
  delay(800);
}
