#include <xc.h>
#include <stdio.h>
#include "mcu.h"
#include "eusart.h"
#include "lora.h"

void main(void) {
    SYSTEM_Initialize();
    uint16_t counter = 0;
    
    //EUSART_SendString("### INIT ###\n");
    int a = 0;
    char msg[40];
    
    while(!begin(915000000)){
        //EUSART_SendString("INIT LORA FAILED\n");
        __delay_ms(1000);
    }
    
    while(1){
        while(beginPacket(false) == 0){
            //EUSART_SendString("waiting for radio ...\n");
            __delay_ms(250);
        }
        
        sprintf(msg, "Sending packet %d\n", counter++);
        //EUSART_SendString(msg);
        
        beginPacket(false);
        sendString("UFC - CAMPUS QUIXADA");     //sending byte 10 to router
        endPacket(false);
    }
}
