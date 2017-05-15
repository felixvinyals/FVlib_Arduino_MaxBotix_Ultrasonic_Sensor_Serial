#include "MaxBotix_Ultrasonic_Sensor.h"

MaxBotix::MaxBotix(byte _pinRx, byte _pinTx) : serialMaxBotix(_pinRx, _pinTx)
{
  byte pinTx;
  byte pinRx;

  pinTx = _pinTx;
  pinRx = _pinRx;

  serialMaxBotix.begin(9600);
}

int MaxBotix::getDistance() {
  unsigned long lastTime = millis();
  boolean streamBeguin = false;
  int distance = 0;
  
  while(serialMaxBotix.available() > 0) serialMaxBotix.read();

  while ((millis() - lastTime) < 1000) {
    if (serialMaxBotix.available()) {
      char rxData = serialMaxBotix.read();

      if (streamBeguin == false) {
        if (rxData == 'R') {
          streamBeguin = true;
        }
      }
      else {
        if ((rxData >= '0') && (rxData <= '9'))
          distance = (distance * 10) + (rxData - '0');
        else if (rxData == 13) return(distance);
        else return -2;
      }
    }
  }
  return -1; // Timeout
}
