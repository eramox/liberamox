#include "Arduino.h"

#include "include/Autotest.h"

// The loop function is called in an endless loop
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

Autotest a = Autotest();
Autotest b = Autotest(3000);

// the setup function runs once when you press reset or power the board
void loop() {
	a.run();
	b.run();
}
