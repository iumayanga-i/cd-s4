#include "EmonLib.h"

EnergyMonitor SCT013;
int pinSCT = A0; // Sensor pin connected to A0

const int LED_PIN = 13; // Built-in LED on Arduino Uno

void setup() {
  Serial.begin(9600);
  

  // Configure SCT013 sensor
  // Use one of these based on your sensor type:
  // SCT013.current(pinSCT, 60.606); // For 100A:50mA sensor (ratio 2000:1 at 33Ohm)
  SCT013.current(pinSCT, 30);        // For 20A/1V sensor
  
  Serial.println("Arduino Current Monitor Started");
  Serial.println("================================");
  Serial.println();

}




void loop() {

  
  double Irms = SCT013.calcIrms(1480);
  double I_calibrated = 0.936609 * Irms - 0.115665;
//  
//  // Set readings below 0.1A to zero
  if (Irms < 0.1) {
    I_calibrated = 0.0;
  }

  Serial.print("  Current (Raw):  ");
  Serial.print(Irms, 3);
  Serial.print("    Current (Calibrated): ");
  Serial.print(I_calibrated, 2);
  Serial.println("");
  
  delay(300);
}
