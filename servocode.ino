#include <Servo.h>
int servoPin = 4;
Servo myservo;
int angle = 0;
  
void setup() {
  // put your setup code here, to run once:
    myservo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int angle = 0; angle < 180; angle++)
{
  myservo.write(angle);
  delay(15);
}

for (int angle = 180; angle > 0; angle--)
{
  myservo.write(angle);
  delay(15);
}
}
