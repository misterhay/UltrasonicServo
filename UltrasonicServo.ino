#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 

const int triggerPin = 12;
const int echoPin = 11;
const int speakerPin = 13;
const int maxDuration = 3000;
int noEcho = 0;
int maxSensorDelay = 18000;
int servoPosition = 50;
int frequency = 120;
//long duration;

void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
//  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speakerPin, OUTPUT);
} 
 
void loop() 
{ 
  long duration;
  
  // The ultrasonic sensor is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);
  
  // measure the duration to find the distance
  duration = pulseIn(echoPin, HIGH);
//  Serial.println(duration);
  
  // constrain the values to eliminate values that are measurement errors
  duration = constrain(duration, 500, 2300);
  
  // map the duration measurement to a range for playing on the speaker
  frequency = map(duration, 0, 2300, 120, 400);
  // play the tone for 10 milliseconds
  tone(speakerPin, frequency, 10);
  
  // map the duration measurement to a range for the servo position
  servoPosition = map(duration, 0, 2300, 50, 100);
  // set the servo position to the newly maped value
  myservo.write(servoPosition);
  // allow some time for the servo to reach position 
  delay(100);
}
