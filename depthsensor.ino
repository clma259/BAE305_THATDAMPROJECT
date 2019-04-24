// the actual value of the 'other' resistor
#define SERIESRESISTOR 546    
 
// What pin to connect the sensor to
#define SENSORPIN A0 
 
void setup(void) {
  Serial.begin(9600);
}
 
void loop(void) {
 
 
 float reading1 = analogRead(SENSORPIN);
 
  Serial.print("Analog reading "); 
  Serial.println(reading1);
 
  // convert the value to resistance
  float reading2 = (1023 / reading1)-1  ;
  Serial.print("reading2 ");
  Serial.println(reading2);
  // convert value to inches using formula: y = 2430 - (569/3)x
  float reading3 = (SERIESRESISTOR / reading2);
  Serial.print("Sensor depth "); 
  Serial.println(reading3);

 
  delay(1000);
}
