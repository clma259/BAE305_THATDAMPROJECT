#define SERIESRESISTOR 546  //actual value of resistor in circuit
#define SENSORPIN A0 //depth sensor connected here
//pinMode(9, OUTPUT);
#include <Servo.h> // calls the library that sees physical motors
int servoPin = 4; //links pin 4 on arduino
Servo myservo; //assigning
int angle = 0;//servi position in degrees void setup()
bool GateClosed = true; //Starting with gate closed

void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(servoPin); 
}

void loop(void) {
while (true)
{
  float reading1 = analogRead(SENSORPIN);
  //Serial.print("Analog reading "); 
  //Serial.println(reading1);
  // convert the value to resistance
  float reading2 = (1023 / reading1)-1  ;
  //Serial.print("reading2 ");
  //Serial.println(reading2);
  // convert value to inches using formula: y = 2430 - (569/3)x
  float reading3 = (SERIESRESISTOR / reading2);
  Serial.print("Sensor depth "); 
  Serial.println(reading3);
  delay(500); 
  

if(reading3 < 1900 ) //if reading is deeper than 5" open gate
  {
    if (GateClosed)//gate initially closed -> OPEN GATE
    {
      myservo.write(140);
      delay(400); //adjust length of time to open gate
      myservo.write(90); //stop motor
      GateClosed = false; // GATE IS OPEN
    }
    else 
    {
      continue; //goes back to reading
    }
    
  }
else  // if reading is <= 5" close gate
  {
    if (GateClosed) // gate already is closed
    {
      continue;
    }
    else // CLOSE GATE
    {
      myservo.write(20);
      delay(400); //adjust length of time to close gate
      myservo.write(91); //stop motor
      GateClosed = true; //GATE IS CLOSED
    }
  }
}
}
