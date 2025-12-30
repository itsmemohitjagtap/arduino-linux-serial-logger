#include <Arduino.h>
#define TRIG_PIN 9
#define ECHO_PIN 10

#define OBJECT_THRESHOLD_CM 30   

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);
  Serial.println("Ultrasonic sensor started...");
}

long measureDistanceCm() {
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration / 29 / 2;

  return distance;
}

void loop() {
  long distance = measureDistanceCm();

  if (distance > 0 && distance < OBJECT_THRESHOLD_CM) {
    Serial.print("Object detected, distance = ");
    Serial.print(distance);
    Serial.println(" cm");
  } else {
    Serial.println("No object");
  }

  delay(500);  
}
