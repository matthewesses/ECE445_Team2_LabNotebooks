// represents all pins that are connected to hall-effect sensors
int hallPins[] = {8, 9, 10, 11, 56, 57, 55, 52, 53, 4, 2, 3};

// represents all pins that are connected to motors
int motorPins[] = {14, 15, 16, 17, 20, 21, 22, 23, 41, 42, 43, 40};

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
    digitalWrite(motorPins[i], motorVals[i]);
  }
  delay(1000);
}
