#include "mcc_generated_files/system/system.h"
#include "dmx.h"
#include "ws2812.h" // Gives access to rxData[] and ledData[]
#include "dma.h"

void DMA_Initialize(void){
    SetArbitrationPriorities();
    DMA1_Initialize();
    DMA2_Initialize();
}

void DMA1_Initialize(void){
    // DMA setup for DMX (UART1)
    
    // Select DMA Instance 0 for DMX (UART))
    DMASELECT = 0x00;
    
    // DMA moves data from the RX buffer to the data array
    DMAnSSA = (uint24_t)&U1RXB;
    DMAnDSA = (uint16_t)&rxData;
    
    DMAnCON1bits.SMR = 0x00; // Source is in SFR/GPR data space (location of data memory))
    //DMAnCON1bits.DSTP = 1; // Don't transmit more data when a transmission finishes
    
    DMAnCON1bits.SMODE = 0x00; // Source ptr stays the same after each transfer (always points to the RX buffer)
    DMAnCON1bits.DMODE = 0x01; // Dest ptr incremements after each transfer to iterate through array
    
    // Source is always 1 byte
    DMAnSSZ = 0x01;
            
    DMAnDSZ = 0x04; // Destination is 4 bytes
    
    // Enable hardware trigger for starting DMA transfer
    DMAnSIRQ = IRQ_U1RX;
    
    DMAnCON0bits.SIRQEN = 1;
    DMAnCON0bits.EN = 1;
}

void DMA2_Initialize(void){
    // DMA setup for SPI
    // Select DMA Instance 1 for SPI
    DMASELECT = 0x01;
    
    // DMA moves data from the RX buffer to the data array
    DMAnSSA = (uint24_t)&ledData;
    DMAnDSA = (uint16_t)&SPI1TXB;
    
    DMAnCON1bits.SMR = 0x00; // Source is in SFR/GPR data space (location of data memory))
    DMAnCON1bits.SSTP = 1; // Don't transmit more data when a transmission finishes
    
    DMAnCON1bits.SMODE = 0x01; // Source ptr incremements after each transfer to iterate through array
    DMAnCON1bits.DMODE = 0x00; // Dest ptr stays the same after each transfer (always points to the RX buffer)
    
    // Source is 3 bytes per LED
    DMAnSSZ = NUM_LEDS * 3;
            
    DMAnDSZ = 0x01; // Dest is always 1 byte
    
    // Enable hardware trigger for starting DMA transfer
    DMAnSIRQ = IRQ_SPI1TX; // IRQ triggers when there is still space in TX FIFO

    DMAnCON0bits.SIRQEN = 1;
    DMAnCON0bits.EN = 1;
}

void SetArbitrationPriorities(void){
    // Sequence gives DMA access to SFR/GPR data space
    INTCON0bits.GIE = 0; // Disable Interrupts;
    PRLOCK = 0x55;
    PRLOCK = 0xAA;
    PRLOCKbits.PRLOCKED = 0; // Allow changing priority settings;
    INTCON0bits.GIE = 1; // Enable Interrupts;
    
    DMA2PR = 0x05; // SPI DMA has 2nd highest priority
    DMA1PR = 0x06; // DMX DMA above MAIN priority
    ISRPR = 0x01; // ISRs have highest priority
    MAINPR = 0x07; // Lowest priority
    
    INTCON0bits.GIE = 0; // Disable Interrupts;
    PRLOCK = 0x55;
    PRLOCK = 0xAA;
    PRLOCKbits.PRLOCKED = 1; // Grant memory access
}