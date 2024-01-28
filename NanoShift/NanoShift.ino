#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int valveShiftUpPin = 2; // Pin für das Hochschaltventil
const int valveShiftDownPin = 3; // Pin für das Herunterschaltventil
const int ignitionInterruptPin = 6; // Pin für Zündunterbrechung, standardmäßig LOW
const int throttleBlipPin = 7;      // Pin für Autoblip, standardmäßig LOW
const int buttonShiftUp = 4; // Pin für den Hochschaltknopf
const int buttonShiftDown = 5; // Pin für den Herunterschaltknopf

void setup() {
  Serial.begin(9600);

  pinMode(valveShiftUpPin, OUTPUT);
  digitalWrite(valveShiftUpPin, HIGH); // Initial HIGH, Relais ist inaktiv
  
  pinMode(valveShiftDownPin, OUTPUT);
  digitalWrite(valveShiftDownPin, HIGH); // Initial HIGH, Relais ist inaktiv

  pinMode(ignitionInterruptPin, OUTPUT);
  digitalWrite(ignitionInterruptPin, LOW); // Initial LOW, Zündung nicht unterbrochen

  pinMode(throttleBlipPin, OUTPUT);
  digitalWrite(throttleBlipPin, LOW); // Initial LOW, kein Autoblip

  pinMode(buttonShiftUp, INPUT_PULLUP);
  pinMode(buttonShiftDown, INPUT_PULLUP);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.display();
  delay(2000); // Pause für den Ladebildschirm
  displayReady(); // Zeigt "READY" an
}

void loop() {
  if (digitalRead(buttonShiftUp) == LOW) {
    performShift(true);
  } else if (digitalRead(buttonShiftDown) == LOW) {
    performShift(false);
  }
}

void performShift(bool shiftUp) {
  display.clearDisplay(); // Display vor der Anzeige löschen

  if(shiftUp) {
    digitalWrite(ignitionInterruptPin, HIGH); // Zündunterbrechung aktivieren
    delay(200); // Zündunterbrechungsdauer
    digitalWrite(ignitionInterruptPin, LOW); // Zündunterbrechung deaktivieren

    // Hochschalten
    digitalWrite(valveShiftUpPin, LOW); // Relais aktivieren
    displayMessage("UP", 5); // Größere Schriftgröße für "UP"
    delay(200); // Relais aktivierungszeit
    digitalWrite(valveShiftUpPin, HIGH); // Relais deaktivieren
  } else {
    digitalWrite(throttleBlipPin, HIGH); // Autoblip aktivieren
    delay(200); // Autoblip-Dauer
    digitalWrite(throttleBlipPin, LOW); // Autoblip deaktivieren

    // Herunterschalten
    digitalWrite(valveShiftDownPin, LOW); // Relais aktivieren
    displayMessage("DOWN", 5); // Größere Schriftgröße für "DOWN"
    delay(200); // Relais aktivierungszeit
    digitalWrite(valveShiftDownPin, HIGH); // Relais deaktivieren
  }
  
  delay(350); // Wartezeit nach dem Schalten
  displayReady(); // Zurück zu READY
}

void displayReady() {
  displayMessage("READY", 4); // Größere Schriftgröße für "READY"
}

void displayMessage(const char* message, int size) {
  display.clearDisplay();
  display.setTextSize(size);
  display.setTextColor(WHITE);
  display.setCursor(0, (SCREEN_HEIGHT - 8 * size) / 2); // Zentriert den Text vertikal
  display.print(message);
  display.display();
  Serial.println(String("Display shows '") + message + "'");
}
