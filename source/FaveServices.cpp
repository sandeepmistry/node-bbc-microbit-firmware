#include "MicroBit.h"
#include "MicroBitSamples.h"
#include "MicroBitUARTService.h"
 
#ifdef MICROBIT_FAVE_SERVICES
 
MicroBit uBit;
 
//int connected = 0;
// 
//void onConnected(MicroBitEvent e)
//{
//    uBit.display.print("C");
//}
// 
//void onDisconnected(MicroBitEvent e)
//{
//    uBit.display.print("D");
//}
 
int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();
 
//    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_CONNECTED, onConnected);
//    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_DISCONNECTED, onDisconnected);
 
    new MicroBitLEDService(*uBit.ble, uBit.display);
    new MicroBitTemperatureService(*uBit.ble, uBit.thermometer);
    new MicroBitUARTService(*uBit.ble, 32, 32);
    new MicroBitAccelerometerService(*uBit.ble, uBit.accelerometer);
    new MicroBitMagnetometerService(*uBit.ble, uBit.compass);  
    new MicroBitButtonService(*uBit.ble);
    new MicroBitIOPinService(*uBit.ble, uBit.io);
   
    uBit.display.scroll(" ");
 
    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}
 
#endif