// C++ code
//
float temp;
float vout;
float vout1;
int LED=13;
int gasSenzor;
int piezo=7;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(piezo, OUTPUT);
  
  Serial.begin(9600);

}

void loop()
{
  vout= analogRead(A1);
  vout1=(vout/1023)*5000; // transfor value(0-1023) in mV(milivolti)
  temp= (vout1-500)/10;  //transf mV in degree
  gasSenzor= analogRead(A0);
  if(temp>=80)
  {
    digitalWrite(LED,HIGH);
  }
  else
    digitalWrite(LED,LOW);
  
  if(gasSenzor>=100)
  {
    digitalWrite(piezo,HIGH);
  }
  else
    digitalWrite(piezo,LOW);
  
  Serial.print("Degree= ");
  Serial.print(temp);
  Serial.print("     GasSenzor= ");
  Serial.print(gasSenzor);
  Serial.println();
  delay(1000);
  
}