int limitSwitch = 13;
int state = LOW;

void setup() {
  
  Serial.begin(9600);
  pinMode(limitSwitch,INPUT);
  
}

void loop() {
  
    int val = digitalRead(limitSwitch);

    if( val != state ){
       state = val;
//       Serial.print("Terdeteksi = ");
       if( state == 0 )
         Serial.println( "sampah elektrtonik" );
       else
         Serial.println( "non elekttronik");
    }
}
