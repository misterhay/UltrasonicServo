#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 

const int triggerPin = 12;
const int echoPin = 11;
const int maxDuration = 3000;
int noEcho = 0;
int maxSensorDelay = 18000;

 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); 
} 
 
void loop() 
{ 
  long duration;
  
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);
  
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  Serial.println(duration);
  
  duration = map(duration, 0, 2500, 50, 100);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(duration);                  // sets the servo position according to the scaled value 
  delay(100);                           // waits for the servo to get there 
} 
