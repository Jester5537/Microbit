#include "MicroBit.h"
#include "MicroBitSamples.h"
#include "PacketBuffer.h"

#ifdef MICROBIT_SAMPLE_SIMPLE_RADIO_RX

MicroBit    uBit;

void onData(MicroBitEvent)
{

   
    PacketBuffer b;
    b = uBit.radio.datagram.recv();
    
    
    uBit.display.scroll(b.getRSSI());
    
    
    //ubit.display.print(b)//
    //ManagedString s = uBit.radio.datagram.recv();//

    //if (b == 10)//
    uBit.display.print(b);

    /*if (b9)
        uBit.display.scroll(b);
        
    if (b == 3)
        uBit.display.print(b);*/
        
        
}

int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();

    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onData);
    uBit.radio.enable();

 

    while(1)
        uBit.sleep(1000);
        
}

#endif