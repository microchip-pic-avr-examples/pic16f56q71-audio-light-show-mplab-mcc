#include <pic18f56q71.h>

#include "mcc_generated_files/system/system.h"
#include "ws2812.h"
#include "dma.h"

// Reads I/O ports to change which node the DMX receiver is
uint8_t getNodeNum(void){
    return ((!IO_RD1_GetValue() << 2) | (!IO_RD2_GetValue() << 1) | !IO_RD3_GetValue());
}


uint8_t DMX_Initialize(void){
    U1CON0 = 0x9A;
    U1CON1 = 0x88;
    U1CON2 = 0xA0;
    U1ERRIE = 0x0E;
    U1FIFO = 0x20;
    U1BRG = 0x3F;   
    U1P2 = getNodeNum()*3; 
    U1P3 = getNodeNum()*3 + 2;
    if(U1P2 > 18 || U1P3 > 20){ // no valid data selected for application
        return 1;
    }
    // set RX pin = RC1
    U1RXPPSbits.PORT = 0b010; // PORT C (A=0, B=1, C=2)
    U1RXPPSbits.PIN = 0b001; // pin 1
    ANSELCbits.ANSELC1 = 0; // disable analog on that pin
    
    PIE4bits.U1EIE = 1;
    return 0;
}

void __interrupt(irq(IRQ_U1E)) DMX_ERR_INT(){
    if(U1ERRIEbits.RXFOIE && U1ERRIRbits.RXFOIF){ // RX buffer overflowed, meaning incoming DMX data got corrupted
        U1ERRIR = 0; // clear all UART errors
        RESET();
//        U1CON1bits.ON = 0; // disable DMX temporarily
//        U1FIFObits.RXBE = 1; // clear UART fifo buffer
//        U1CON1bits.ON = 1; // enable DMX       
    } else {
        U1ERRIR = 0; // clear all UART errors
    }
}