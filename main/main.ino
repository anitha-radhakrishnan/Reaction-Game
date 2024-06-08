const int multiplexerOne[4] = {5,4,3,2}; 
const int multiplexerTwo[4] = {9,8,7,6}; 
const int inputPin = 12; 

void setup() {
  // Initialize serial communication
  Serial.begin(9600); 
  randomSeed(analogRead(A0));
  
  // Initialize the Multiplexer pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(multiplexerOne[i], OUTPUT);
    pinMode(multiplexerTwo[i], OUTPUT);
  }
  // Set input pin with internal pullup
  pinMode(inputPin, INPUT_PULLUP); 
}

void loop() {
  //Generate random number between 1 and 20
  int randomNum = random(1, 21); 
  Serial.print("Random number between 1 and 20: ");
  Serial.println(randomNum);

  //choose mux
  if (randomNum <= 10) {
    randomNum += 3; // Add 3 to the random number
    //Binary conversion
    // Mask with 0x0F to get only the lower 4 bits
    randomNum = randomNum & 0x0F; 

     // Set the multiplexer based on the binary representation
    for (int i = 0; i < 4; i++) {
      Serial.print((randomNum >> i) & 0x01);
      digitalWrite(multiplexerOne[i], (randomNum >> i) & 0x01); // Extract each bit and set the LED
    }
    Serial.println("");
  } 
  
  else {
    randomNum -= 7; // Subtract 7 from the random number
    
    //Binary conversion
    // Mask with 0x0F to get only the lower 4 bits
    randomNum = randomNum & 0x0F;

    // Set the multiplexer based on the binary representation
    for (int i = 0; i < 4; i++) {
      Serial.print((randomNum >> i) & 0x01);
      digitalWrite(multiplexerTwo[i], (randomNum >> i) & 0x01); // Extract each bit and set the LED
    }
    Serial.println("");

  }

  // Wait for the input from pin 8
  Serial.println("Press the switch");
  while (digitalRead(inputPin) == HIGH) {
    // Do nothing, just wait
  }

  Serial.println("Switch pressed");
  //Reset multiplexer
  for (int i = 0; i < 4; i++) {
      digitalWrite(multiplexerOne[i],LOW );
      digitalWrite(multiplexerTwo[i],LOW );
  }

  delay(1000); // Wait for 1 second before restarting the loop
}
