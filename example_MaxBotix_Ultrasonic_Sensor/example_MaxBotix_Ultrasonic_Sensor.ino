#include "MaxBotix_Ultrasonic_Sensor.h"

#define TxPin 48
#define RxPin 49 // This pin is not implemented in the MaxBotix sensor but is needed to initialize the SoftwareSerial Library that is inside this MaxBotix library.

MaxBotix sensor_ultrasonic(TxPin, RxPin);

void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.println(sensor_ultrasonic.getDistance());
}
