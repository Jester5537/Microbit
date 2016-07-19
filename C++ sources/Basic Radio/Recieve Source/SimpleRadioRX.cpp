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

//ManagedString b(uBit.radio.datagram.recv());

void onData(MicroBitEvent) {
    while (1){
        ManagedString c("12");
            uBit.display.scroll(c,100);
            int j = atoi(c.toCharArray());
            uBit.display.scroll(j+1);
}

}

int main()
{
 // Initialise the micro:bit runtime.
    uBit.init();
    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onData);
    uBit.radio.enable();

    while(1)
        uBit.sleep(100);       
}
#endif