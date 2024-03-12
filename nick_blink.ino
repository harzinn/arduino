// myLeds is an array of the pins the LEDs are connected to
int myLeds[] = { 9, 10, 11, 12, 13 };
const int numLeds = sizeof(myLeds) / sizeof(myLeds[0]); // Calculate the number of LEDs dynamically

void setup() {
  // Set each LED pin as output
  for (int i = 0; i < numLeds; i++) {
    pinMode(myLeds[i], OUTPUT);
  }
}

void loop() {
  // Blink LEDs with varying speeds in forward and then reverse order
  blinkAllLeds(1000, false); // Blink for 1 second, forward
  blinkAllLeds(500, false);  // Blink for half a second, forward
  blinkAllLeds(100, false);  // Blink very quickly (100ms), forward

  blinkAllLeds(1000, true); // Blink for 1 second, reverse
  blinkAllLeds(500, true);  // Blink for half a second, reverse
  blinkAllLeds(100, true);  // Blink very quickly (100ms), reverse
}

void blinkAllLeds(int speed, bool reverse) {
  // Blink all LEDs with the specified speed, in forward or reverse order
  if (!reverse) {
    for (int i = 0; i < numLeds; i++) {
      blinkL(myLeds[i], speed);
    }
  } else {
    for (int i = numLeds - 1; i >= 0; i--) {
      blinkL(myLeds[i], speed);
    }
  }
}

void blinkL(int led, int speed) {
  // Blink an LED with the specified speed
  digitalWrite(led, HIGH);
  delay(speed);
  digitalWrite(led, LOW);
  delay(speed);
}