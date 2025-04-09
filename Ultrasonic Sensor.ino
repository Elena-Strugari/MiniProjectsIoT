// C++ code
//

int trigPin=10;
int echoPin=9;
long time;
int distance; 

void setup()
{
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  time= pulseIn(echoPin, HIGH); // time of the signal
  distance = time* 0.034/2; // speed of sound in air (cm/microsec)
  // the distance is from the sensor to the object,
  //not both directions
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
}