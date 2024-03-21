#define BLYNK_TEMPLATE_ID "TMPL3DHPRNsOg"
#define BLYNK_TEMPLATE_NAME "LED Control"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial

#define APP_DEBUG
#define LED_PIN2 D2
#define LED_PIN3 D3 
#define LED_PIN4 D6
#define LED_PIN1 D10

#include "BlynkEdgent.h"

bool alternate = false;

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT); 
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  
  if (alternate) {
    alternateLEDs();
  } else {
    resumeLEDs();
  }
  
  // Delay between LED changes
  delay(1000);
}

void alternateLEDs() {
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN4, LOW); // Turn off the new LED
  delay(1000);

  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  digitalWrite(LED_PIN3, HIGH);
  digitalWrite(LED_PIN4, HIGH); // Turn on the new LED
  delay(1000);
}

void resumeLEDs() {
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, HIGH);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN4, LOW); // Turn off the new LED
  delay(1000);

  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, HIGH);
  digitalWrite(LED_PIN4, LOW); // Turn off the new LED
  delay(1000);

  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN4, HIGH); // Turn off the new LED
  delay(1000);
}

BLYNK_WRITE(V0) {
  int value = param.asInt();
  
  if (value == 1) {
    alternate = true;
  } else {
    alternate = false;
  }
}
