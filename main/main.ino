const int muxOnePins[4] = {3, 4, 5, 6};
const int muxTwoPins[4] = {9, 10, 11, 12};
const int inputPin = 8;

void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < 4; i++) {
    pinMode(muxOnePins[i], OUTPUT);
    pinMode(muxTwoPins[i], OUTPUT);
  }
  pinMode(inputPin, INPUT_PULLUP);
}

void setMultiplexerPins(const int* pins, int value) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(pins[i], (value >> i) & 0x01);
  }
}

void resetMultiplexerPins() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(muxOnePins[i], LOW);
    digitalWrite(muxTwoPins[i], LOW);
  }
}

void loop() {
  int randomNum = random(1, 21);
  Serial.print("Random number between 1 and 20: ");
  Serial.println(randomNum);

  if (randomNum <= 10) {
    randomNum = (randomNum + 3) & 0x0F;
    setMultiplexerPins(muxOnePins, randomNum);
  } else {
    randomNum = (randomNum - 7) & 0x0F;
    setMultiplexerPins(muxTwoPins, randomNum);
  }

  Serial.println("Press the switch");
  while (digitalRead(inputPin) == HIGH) {
    // Wait for input
  }

  Serial.println("Switch pressed");
  resetMultiplexerPins();

  delay(1000);
}
