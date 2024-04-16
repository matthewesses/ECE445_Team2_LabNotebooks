// represents all pins that are connected to hall-effect sensors
int hallPins[] = {31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53};

// represents all pins that are connected to motors
int motorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11};

// represents all values received from hall effect sensors
int hallVals[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

// represents all values written to motors
int motorVals[] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
                  

void setup() {
  for (int i = 0; i < 12; i++)
  {
    pinMode(hallPins[i], INPUT);
  }
  for (int i = 0; i < 12; i++)
  {
    pinMode(motorPins[i], OUTPUT);
  }
}

void loop() {
  // get readings from all hall effect sensor pins
  for (int i = 0; i < 12; i++)
  {
    hallVals[i] = digitalRead(hallPins[i]);
  }
  for (int i = 0; i < 12; i++)
  {
    motorVals[i] = ~(hallVals[i]);
    if (motorVals[i] == 1)
    {
      Serial.println("Motor " + i + " is on!");
    }
    digitalWrite(motorPins[i], motorVals[i]);
  }
  delay(1000);
}
