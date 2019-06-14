#include <toneAC.h>

const int trigPinF = 7;
const int echoPinF = 6;
const int trigPinV = 5;
const int echoPinV = 4;
bool noteCorrection =  true;
void setup() {
    Serial.begin(9600);
}

void loop() {
float durationF, distanceF;
pinMode(trigPinF, OUTPUT);
pinMode(echoPinF, INPUT);

digitalWrite(trigPinF, LOW);
delayMicroseconds(2);
digitalWrite(trigPinF, HIGH);
delayMicroseconds(5);
digitalWrite(trigPinF, LOW);
durationF = pulseIn(echoPinF, HIGH);
distanceF = secondsToDistance(durationF);

float durationV, distanceV;
pinMode(trigPinV, OUTPUT);
pinMode(echoPinV, INPUT);

digitalWrite(trigPinV, LOW);
delayMicroseconds(2);
digitalWrite(trigPinV, HIGH);
delayMicroseconds(5);
digitalWrite(trigPinV, LOW);
durationV = pulseIn(echoPinV, HIGH);
distanceV = secondsToDistance(durationV);

MakeSound(distanceF,distanceV);
}

float secondsToDistance(float seconds) {
return seconds * 0.034 / 2;
}
