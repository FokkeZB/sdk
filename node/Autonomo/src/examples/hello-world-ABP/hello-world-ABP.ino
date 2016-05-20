#define DEBUG

#include "TheThingsUno.h"

// Set your device address
const byte devAddr[4] = {0x02, 0xDE, 0xAE, 0x00};

// Set your NwkSKey and AppSKey
const byte nwkSKey[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};
const byte appSKey[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

#define debugSerial Serial
#define loraSerial Serial1

TheThingsUno ttu;

void setup()
{
  debugSerial.begin(115200);
  loraSerial.begin(57600);

  delay(3000);
  
  ttu.init(loraSerial, debugSerial); //Initializing...
  
  ttu.reset();
  ttu.personalize(devAddr, nwkSKey, appSKey);
  ttu.showStatus();

   debugSerial.println("Setup for The Things Network complete");

  delay(2000);
}

void loop() {
  ttu.sendString("Hello world!");

  delay(5000);
}