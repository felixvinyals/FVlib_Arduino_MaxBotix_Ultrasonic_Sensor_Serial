
#ifndef MaxBotix_Ultrasonic_Sensor_h
  #define MaxBotix_Ultrasonic_Sensor_h
  #include <Arduino.h>
  #include <avr/pgmspace.h>
  #include <SoftwareSerial.h>

  class MaxBotix {
    public:
      MaxBotix(byte _pinTx, byte _pinRx);
      int getDistance();
      byte pinTx;
      byte pinRx;
      SoftwareSerial serialMaxBotix;

    private:



  };
#endif
