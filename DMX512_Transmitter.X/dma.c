//#include <pic18f56q71.h>

#include "dma.h"
#include "visuals.h"
#include "mcc_generated_files/system/system.h"

void DMA_Initialize(void) {
    // Select DMA Instance 0
    DMASELECT = 0x00;
    
    // DMA moves data from a data array into the DMX transmit buffer (U1TX)
    DMAnSSA = (uint24_t)&dmxData;
    DMAnDSA = (uint16_t)&U1TXB;
    
    DMAnCON1bits.SMR = 0x00; // Source is in SFR/GPR data space (location of data memory))
    DMAnCON1bits.SSTP = 1; // Don't transmit more data when a transmission finishes
    
    DMAnCON1bits.SMODE = 0x01; // Source ptr incremements after each transfer to iterate through array
    DMAnCON1bits.DMODE = 0x00; // Dest ptr stays the same after each transfer (always points to TX buffer)
    
    // Set source and destination data size (+1 includes the start code)
    DMAnSSZ = NODES*3+1;
            
    DMAnDSZ = 0x01; // destination always 1 byte at a time
    
    // Enable hardware trigger for starting DMA transfer
    DMAnSIRQ = IRQ_U1TX;
    
    // Sequence gives DMA acess to SFR/GPR data space
    INTCON0bits.GIE = 0; // Disable Interrupts;
    DMA1PR = 0x07; // Change the priority only if needed
    PRLOCK = 0x55;
    PRLOCK = 0xAA;
    PRLOCKbits.PRLOCKED = 1; // Grant memory access to peripherals;
    INTCON0bits.GIE = 1; // Enable Interrupts;
    
    DMAnCON0bits.SIRQEN = 1;
    DMAnCON0bits.EN = 1;
}