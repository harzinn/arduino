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
  // Blink LEDs with varying speeds
  blinkAllLeds(1000); // Blink for 1 second
  blinkAllLeds(500);  // Blink for half a second
  blinkAllLeds(100);  // Blink very quickly (100ms)
}

void blinkAllLeds(int speed) {
  // Blink all LEDs with the specified speed
  for (int i = 0; i < numLeds; i++) {
    blinkL(myLeds[i], speed);
  }
}

void blinkL(int led, int speed) {
  // Blink an LED with the specified speed
  digitalWrite(led, HIGH);
  delay(speed);
  digitalWrite(led, LOW);
  delay(speed);
}
