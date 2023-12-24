// Project of @Carbon_gtv, support me on instagram, donations are welcome!

const int valveShiftUpPin = 2; // Pin für das Hochschaltventil
const int valveShiftDownPin = 3; // Pin für das Herunterschaltventil
const int ignitionInterruptPin = 6; // Pin für die Zündunterbrechung
const int throttleBlipPin = 7; // Pin für das Throttle Blip
const int buttonShiftUp = 4; // Pin für den Hochschaltknopf
const int buttonShiftDown = 5; // Pin für den Herunterschaltknopf

void setup() {
  pinMode(valveShiftUpPin, OUTPUT);
  pinMode(valveShiftDownPin, OUTPUT);
  pinMode(ignitionInterruptPin, OUTPUT);
  pinMode(throttleBlipPin, OUTPUT);
  pinMode(buttonShiftUp, INPUT_PULLUP);
  pinMode(buttonShiftDown, INPUT_PULLUP);
  // Initialisiere alle Pins in ausgeschaltetem Zustand
  digitalWrite(valveShiftUpPin, LOW);
  digitalWrite(valveShiftDownPin, LOW);
  digitalWrite(ignitionInterruptPin, LOW);
  digitalWrite(throttleBlipPin, LOW);
}

void loop() {
  if (digitalRead(buttonShiftUp) == LOW) {
    // Zündunterbrechung und dann Hochschalten
    digitalWrite(ignitionInterruptPin, HIGH);
    delay(50); // Verzögerung für Zündunterbrechung, anpassbar
    digitalWrite(ignitionInterruptPin, LOW);
    shiftGear(true);
  }
  if (digitalRead(buttonShiftDown) == LOW) {
    // Throttle Blip und dann Herunterschalten
    digitalWrite(throttleBlipPin, HIGH);
    delay(50); // Verzögerung für Throttle Blip, anpassbar
    digitalWrite(throttleBlipPin, LOW);
    shiftGear(false);
  }
}

void shiftGear(bool shiftUp) {
  int valvePin = shiftUp ? valveShiftUpPin : valveShiftDownPin;
  digitalWrite(valvePin, HIGH); // Aktiviere Ventil
  delay(100); // Kurzer Stoß
  digitalWrite(valvePin, LOW); // Deaktiviere Ventil
}
