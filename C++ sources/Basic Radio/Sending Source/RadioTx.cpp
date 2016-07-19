#include "MicroBit.h"
#include "MicroBitSamples.h"
#include "PacketBuffer.h"
#include "ManagedString.h"
#include "MemberFunctionCallback.h"
#include "ManagedType.h"

#ifdef MICROBIT_SAMPLE_SIMPLE_RADIO_TX
#define x
MicroBit    uBit;

int main()
{
   // Initialise the micro:bit runtime.
    uBit.init();
    uBit.radio.enable();
  
  while (1){

ManagedString b(uBit.radio.datagram.recv());
        uBit.display.scroll(b);
        }
}
#endif