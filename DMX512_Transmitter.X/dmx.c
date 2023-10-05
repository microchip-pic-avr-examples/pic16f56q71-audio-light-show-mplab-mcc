#include "mcc_generated_files/system/system.h"
#include "visuals.h"

/*
 * File:   dmx.c
 * Author: C70636
 *
 * Created on June 14, 2023, 10:38 PM
 */

void DMX_Initialize(void) {
    U1CON0 = 0xAA;
    U1CON1 = 0x80;
    U1CON2 = 0x20;
    U1ERRIR = 0x00;
    U1ERRIE = 0x00;
    U1UIR = 0x00;
    U1FIFO = 0x01;
    U1BRG = 0x3F;
    U1RXB = 0x00;
    U1TXB = 0x00;
    U1P1 = (NODES * 3) - 1; // transmit LEDS bytes
    U1P2 = 0x00;
    U1P3 = 0x00;
    U1TXCHK = 0x00;
    U1RXCHK = 0x00;
     
    // set TX pin = RC0
    RC0PPS = 0x15; 
}


// Ensures synchronization between DMX hardware & software
void DMX_sync(void){
    U1CON0bits.TXEN = 0; while(U1CON0bits.TXEN != 0);
    U1CON0bits.TXEN = 1;
}

void DMX_send_byte(uint8_t data){
    U1TXB = data;  
    while(U1TXMTIF==0); // wait for byte to finish sending
}

void DMX_send_bytes(uint8_t *data, uint8_t len){
    for(uint8_t i = 0; i < len; i++){
        DMX_send_byte(data[i]);
    }
}

void DMX_transsmision(uint8_t start_code, uint8_t *data, uint8_t data_len){
    DMX_send_byte(start_code);
    DMX_send_bytes(data, data_len);
    DMX_sync();
}