#include "mcc_generated_files/system/system.h"
#include "ws2812.h"

// Initializes a SPI Host
void SPI1_Initialize(void)
{
    SPI1CON0bits.MST = 1; // Host mode
    SPI1CON0bits.BMODE = 1; // Byte Mode
    SPI1CON2bits.TXR = 1; // Enable TX
    SPI1CON2bits.RXR = 0; // Disable RX
    SPI1CLK = 0x06; // Select TMR2_Postscaler_OUT as Clock Sources
    SPI1BAUD = 0x00; //From a 16MHz clock, 800kHz SCK
    SPI1TWIDTH = 0; //Set Width to 8-bits (n = 0)
    SPI1TCNT = NUM_LEDS * 3; // Number of bytes to transfer (doesn't matter when BMODE = 1)
    //SDO Config - RB3
    TRISB3 = 0;
    RB3PPS = 0x1E;
    //SCK Config - RB1
    TRISB1 = 0;
    RB1PPS = 0x1D;
    PIE3bits.SPI1IE = 1; // Enable system-level SPI interrupts SPI1INT
    SPI1INTEbits.SRMTIE = 1; // Enable interrupt when a SPI transfer completes
    SPI1CON0bits.EN = 1; // Enable SPI
}

// Triggers when any of the SPI1 interrupts are set
void __interrupt(irq(IRQ_SPI1), base(8)) SPI_INT(){
    if (SPI1INTFbits.SRMTIF == 1) { // all the bytes have been transferred
        SPI1INTF = 0x00; // clear SPI flags
        // start timer 0, which takes 60us to generate an interrupt. After that,
        // the timer callback will re-enable DMA for more data to be  transfered to the WS2812's
        T0CON0bits.EN = 1;
    }
}
