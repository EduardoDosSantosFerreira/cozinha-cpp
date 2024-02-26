// C++ code
//
#include <Servo.h>

int Cabinet = 0;

int PIRS = 0;

int Gass = 0;

int Temps = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_5;

void setup()
{
  Serial.begin(9600);
  servo_5.attach(5, 500, 2500);
  pinMode(10, INPUT);
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(6, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  Cabinet = 0.01723 * readUltrasonicDistance(3, 3);
  Serial.println(Cabinet);
  if (Cabinet < 15) {
    servo_5.write(90);
    delay(5000); // Wait for 5000 millisecond(s)
  } else {
    servo_5.write(0);
  }
  PIRS = digitalRead(10);
  Serial.println(PIRS);
  if (PIRS == HIGH) {
    digitalWrite(9, HIGH);
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(9, LOW);
    digitalWrite(7, LOW);
  }
  Temps = (-40 + 0.488155 * (analogRead(A1) - 20));
  Serial.println(Temps);
  if (Temps >= 30) {
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(6, LOW);
  }
  Gass = analogRead(A0);
  Serial.println(Gass);
  if (Gass >= 220) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
}