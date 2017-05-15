#include "MaxBotix_Ultrasonic_Sensor.h"

#define RxPin 50  // This pin is not implemented in the MaxBotix 
                  // sensor but is needed to initialize the 
                  // SoftwareSerial Library that is inside this MaxBotix library.
#define TxPin 51

MaxBotix ultrasonicSensor(RxPin, TxPin);

void setup() {
  Serial.begin(9600);
  Serial.println("Fi setup");
}

void loop() {
  int distance;

  distance = ultrasonicSensor.getDistance();

  if (distance == -1) {
    Serial.println("Timeout");  
  }
  
  else if (distance == -2) {
    Serial.println("Invalid Data");  
  }

  else {
    Serial.print("Distance: ");
    Serial.println(distance);  
  }
}


