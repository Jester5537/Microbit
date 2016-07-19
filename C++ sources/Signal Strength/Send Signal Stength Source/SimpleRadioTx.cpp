#include "MicroBit.h"
#include "MicroBitSamples.h"

#ifdef MICROBIT_SAMPLE_SIMPLE_RADIO_TX
#define x
MicroBit    uBit;

int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();
    uBit.radio.enable();
        
        PacketBuffer b(4);
        b = 4;
        uBit.display.print(b);             
    while(1)
    {
        
        
        if (uBit.buttonA.isPressed())
            uBit.radio.datagram.send(b);

        else if (uBit.buttonB.isPressed())
            uBit.radio.datagram.send("B");

        uBit.sleep(100);
    }
}

#endif