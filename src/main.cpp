/**
* @file main.cpp
 * @brief MG995 Closed-Loop Axis Control System
 * @author Rohit Chauhan
 * @date 2026-02-12
 *
 * @details
 * This program implements PWM-based control of MG995 servo motor.
 * The system accepts angle input via Serial Monitor and moves
 * the servo after validating input range (0–180 degrees).
 */

#include <Arduino.h>
#include <Servo.h>

Servo myservo;
int echopin = 10;
int trigpin = 9;

void setup() {
    pinMode(trigpin, OUTPUT);
    pinMode(echopin, INPUT);
    Serial.begin(9600);
    myservo.attach(3);
}

void loop() {


    digitalWrite(trigpin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin, LOW);
    long duration = pulseIn(echopin, HIGH);
    long distance = (duration * 0.034) / 2;

    if (distance < 15) {
        myservo.write(90);
    } else {
        myservo.write(0);
    }

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
}
