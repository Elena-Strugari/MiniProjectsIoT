const int buton = 2;
const int ledRosu = 11;  
const int ledAlbastru = 10; 
const int ledVerde = 9; 


int stare = 0; // 0 = oprit, 1 = rece, 2 = cald
int intensitate = 255; 
bool apasat = false;
unsigned long tApasare = 0;

void setLumina(int stare, int intensitate) {
  int rosu, verde, albastru;

  if (stare == 1) { // Lumina rece
    rosu = map(190, 0, 255, 0, intensitate);
    verde = map(220, 0, 255, 0, intensitate);
    albastru = map(255, 0, 255, 0, intensitate);
  } else if (stare == 2) { // Lumina neutra
    rosu = map(255, 0, 255, 0, intensitate);
    verde = map(255, 0, 255, 0, intensitate);
    albastru = map(255, 0, 255, 0, intensitate);
  } else if (stare == 3) { // Lumina calda
    rosu = map(255, 0, 255, 0, intensitate);
    verde = map(180, 0, 255, 0, intensitate);
    albastru = map(130, 0, 255, 0, intensitate);
  } else { // Lumina oprita
    rosu = verde = albastru = 0;
  }

  analogWrite(ledRosu, rosu);
  analogWrite(ledVerde, verde);
  analogWrite(ledAlbastru, albastru);
}


void setup() {
  pinMode(buton, INPUT_PULLUP);
  pinMode(ledRosu, OUTPUT);
  pinMode(ledAlbastru, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
  int citire = digitalRead(buton);
  Serial.println(citire);
delay(100);


  if (citire == LOW && !apasat) {
    apasat = true;
    tApasare = millis();  
  }

  if (citire == HIGH && apasat) {
    if (millis() - tApasare < 500) { 
      stare = (stare + 1) % 4; 
    }
    apasat = false;
  }

  if (apasat && millis() - tApasare > 500) {
    intensitate = map(analogRead(A0), 0, 1023, 0, 255); 
  }

 setLumina(stare, intensitate);
}
