#include "MaxBotix_Ultrasonic_Sensor.h"

MaxBotix::MaxBotix(byte _pinTx, byte _pinRx) {
  byte pinTx;
  byte pinRx;

  pinTx = _pinTx;
  pinRx = _pinRx;

  SoftwareSerial serialMaxBotix(pinRx, pinTx, false);
  serialMaxBotix.begin(9600);
}

int MaxBotix::getDistance() {
  unsigned long lastTime = millis();
  boolean streamBeguin = false;
  int distance = 0;

  while ((millis() - lastTime) < 100) {
    if ((*serialMaxBotix).available()) {
      char rxData = (*serialMaxBotix).read();
      if (rxData == 'R') streamBeguin = true;
      if (streamBeguin == true) {
        if ((rxData >= '0') && (rxData <= '9')) distance = (distance * 10) + (rxData - '0');
        else if (rxData == 'R') return distance;
        else return -2; // Not valid recieved character
      }
    }
  }
  return -1; // Timeout
}
