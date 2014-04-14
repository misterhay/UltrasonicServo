#include <Ultrasonic.h>

#include <Servo.h>

int item;

Ultrasonic ultrasonic_1(1);

Servo servo_1;

void setup()
{
  ultrasonic_1.MeasureInCentimeters();
  servo_1.attach(1);
}


void loop()
{
  item = ultrasonic_1.RangeInCentimeters();;
  servo_1.write((item));
  delay((100));
}
