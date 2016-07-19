//ADD 1 PROGRAM    //crank powered micro:bit
#include "MicroBit.h"
#include "MicroBitSamples.h"
#include "PacketBuffer.h"
#include "ManagedString.h"
#include "DiscoveredCharacteristic.h"
#include "MicroBitImage.h"
#include "ManagedString1.h"
#include "stdint.h"
#include "stddef.h"
#include "stdlib.h"
#ifdef MICROBIT_SAMPLE_SIMPLE_RADIO_TX

MicroBit    uBit;

void onData(MicroBitEvent) {
     
}

int main()
{
 // Initialise the micro:bit runtime.
    uBit.init();
    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onData);
    uBit.radio.enable();
    while (true) {
//pulls last value from the server micro:bit
    ManagedString b(uBit.radio.datagram.recv());
//takes pulled value converts it to a int after it's converted to a char
    int c = atoi(b.toCharArray());
    uBit.display.scroll(c);
        while (1){  
//takes the int and adds 1 to it 
            ManagedString d(c+1);
//sends the new int to the server for storage                 
            uBit.radio.datagram.send(d);
//delay for server to recieve the data and send new a value back
            uBit.sleep(500);
//restart outer program
            break;
        }     
}
}
/*
i'm almost completely certain that this microbit is doing everything that it needs to   any changes are most likely to be added
to the server microbit to make this run better   
but i may be wrong   all C++ i know i've learned in the past 2 weeks  so  yeah  good luck

if cranked at right time the two microbit's mirror eachother showing syncornization and saved data   if there is even a small delay 
between the two then numbers repeat or jump randomly around at points  
*/
#endif