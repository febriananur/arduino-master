// defines pins numbers
const int trigPin = 11;
const int echoPin = 10;
const int relayPin = 13;

// defines variables
long duration;
int distance;
long distancemm;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(relayPin, OUTPUT);// Control Pin 
//Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
distancemm = distance*10+30;

//Control 
if (distancemm <=100)
{
 for (int i=0; i <= 50; i++){
      digitalWrite(relayPin, HIGH);
      delay(10);
   }
   
}
else if (distancemm >= 121)
{
  digitalWrite(relayPin, LOW); 
}
else
{
  //Safe! Continue usual tasks...
}

// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);
//Serial.print("Distance: ");
//Serial.print(distancemm);
//Serial.println("mm");
delay(250);
}
