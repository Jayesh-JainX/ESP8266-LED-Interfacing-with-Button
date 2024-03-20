#define LED_PIN1 D1
#define LED_PIN2 D2
#define LED_PIN3 D3
#define BUTTON_PIN D4
#define LED_PIN4 D6 

bool ledState = false; // Variable to store the current LED state
bool buttonState = false; // Variable to store the current button state
bool lastButtonState = false; // Variable to store the previous button state
unsigned long lastDebounceTime = 0; // Last time the button state changed
unsigned long debounceDelay = 50; // Debounce time in milliseconds

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Enable internal pull-up resistor for the button pin
}

void loop() {
  // Read the state of the button
  bool reading = digitalRead(BUTTON_PIN);

  // Check if the button state has changed
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // Update the debounce time
  }

  // Check if debounce time has passed
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Check if the button state has changed and stable
    if (reading != buttonState) {
      buttonState = reading; // Update the button state

      // Check if the button is pressed
      if (buttonState == LOW) {
        // Toggle the LED state
        ledState = !ledState;

        // Update the LED based on the ledState
        if(ledState){
          resumeLEDs();
        } else {
          alternateLEDs();
        }
      }
    }
  }

  // Update lastButtonState
  lastButtonState = reading;
}

void alternateLEDs() {
  do {
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN4, LOW);
    delay(1000);

    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN3, HIGH);
    digitalWrite(LED_PIN4, HIGH);
    delay(1000);
    
    // Read the button state
    buttonState = digitalRead(BUTTON_PIN);
  } while (buttonState == HIGH);
}

void resumeLEDs() {
  do {
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN4, LOW);
    delay(1000);

    digitalWrite(LED_PIN1, LOW); 
    digitalWrite(LED_PIN2, HIGH); 
    digitalWrite(LED_PIN3, LOW); 
    digitalWrite(LED_PIN4, LOW);
    delay(1000); 

    digitalWrite(LED_PIN1, LOW); 
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, HIGH);
    digitalWrite(LED_PIN4, LOW);
    delay(1000);

    digitalWrite(LED_PIN1, LOW); 
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN3, LOW);
    digitalWrite(LED_PIN4, HIGH);
    delay(1000); 
    
    buttonState = digitalRead(BUTTON_PIN);
  } while (buttonState == HIGH);
}
