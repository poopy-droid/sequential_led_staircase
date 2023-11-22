const int pirPinUp = 2;    // PIR sensor for upward sequence connected to digital pin 2
const int pirPinDown = 3;  // PIR sensor for downward sequence connected to digital pin 3
const int numLeds = 20;     // Number of LEDs
int ledPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5, 14, 15, 16};  // LED pins

void setup() {
  pinMode(pirPinUp, INPUT);
  pinMode(pirPinDown, INPUT);
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);  // Turn off all LEDs at the beginning
  }
}

void loop() {
  // Read the PIR sensor inputs
  int pirStateUp = digitalRead(pirPinUp);
  int pirStateDown = digitalRead(pirPinDown);

  // If PIR sensor for upward sequence is triggered, turn on LEDs sequentially
  if (pirStateUp == HIGH) {
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(100);  // Adjust the delay as needed
    }

    // Wait for some time with all LEDs on
    delay(2000);  // Adjust the delay as needed

    // Turn off LEDs sequentially
    for (int i = numLeds - 1; i >= 0; i--) {
      digitalWrite(ledPins[i], LOW);
      delay(100);  // Adjust the delay as needed
    }
  }

  // If PIR sensor for downward sequence is triggered, turn on LEDs sequentially
  if (pirStateDown == HIGH) {
    for (int i = numLeds - 1; i >= 0; i--) {
      digitalWrite(ledPins[i], HIGH);
      delay(100);  // Adjust the delay as needed
    }

    // Wait for some time with all LEDs on
    delay(2000);  // Adjust the delay as needed

    // Turn off LEDs sequentially
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], LOW);
      delay(100);  // Adjust the delay as needed
    }
  }
}