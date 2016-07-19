//ADD 1 PROGRAM    //continuously powwered micro:bit
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
#ifdef MICROBIT_SAMPLE_SIMPLE_RADIO_RX

MicroBit    uBit;

void onData(MicroBitEvent) {
    

}
int main()
{
 // Initialise the micro:bit runtime.
    uBit.init();
    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onData);
    uBit.radio.enable();
//starts off exchange by sending initial value of 0
uBit.radio.datagram.send("0");
while(true){
//receives value from crank powered micro:bit 
    ManagedString b(uBit.radio.datagram.recv());
//changes recieved value to into after converting to char
    int c = atoi(b.toCharArray());        
    uBit.display.scroll(c);
//takes int and adds 1 to it 
        ManagedString d(c+1);
//sends new int
        uBit.radio.datagram.send(d);
//slight delay for other micro;bit to run 
        uBit.sleep(500);
    }     
}

/*
clears memeory after loop    need to find a way to loop the int vlaue gained at the end to the 
beggining of program to be continuously sent until it recieves a new value

*/
#endif