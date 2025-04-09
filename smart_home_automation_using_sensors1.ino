#include <LiquidCrystal.h>

// LCD: rs, en, d4, d5, d6, d7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// --- Ultrasound sensor ---
int distanceThreshold = 0;
int cm = 0;
int inches = 0;

// --- Relay Control ---
int releNO = 13;
int inputPir = 8;
int val = 0;
int resultadoSensorLDR;
int sensorLDR = A0;

// --- Gas sensor ---
const int PINO_SGAS = A1;

// --- Ultrasonic distance function ---
long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  // LCD setup
  lcd.begin(16, 2);

  // I/O setup
  pinMode(releNO, OUTPUT);
  pinMode(inputPir, INPUT);
  pinMode(sensorLDR, INPUT);

  Serial.begin(9600);
}

void loop() {
  distanceThreshold=350;
  cm= 0.01723 * readUltrasonicDistance(7,6);
  inches=(cm /2.54);
  
  lcd.setCursor(0,0);
  lcd.print("D:");
  lcd.print(cm);
  lcd.print("cm");
  delay(10);
  
  resultadoSensorLDR = analogRead(sensorLDR);

  if (resultadoSensorLDR < 600) {
    val = digitalRead(inputPir);

    if (val == HIGH) {
      digitalWrite(releNO, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("L1: On ");
      delay(5000);
    } else {
      digitalWrite(releNO, LOW);
      lcd.setCursor(0, 1);
      lcd.print("L1: Off");
      delay(300);
    }
  } else {
    digitalWrite(releNO, LOW);
    Serial.println(resultadoSensorLDR);
    delay(500);
  }

  // --- Gas sensor reading ---
  int color = analogRead(PINO_SGAS);
  lcd.setCursor(8, 0);

  if (color <= 85) {
    lcd.print("G:Low ");
  } else if (color <= 120) {
    lcd.print("G:Med ");
  } else if (color <= 200) {
    lcd.print("G:High");
  } else if (color <= 300) {
    lcd.print("G:Ext ");
  }

  delay(500); // Mică pauză între cicluri
}
