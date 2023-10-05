#include "mcc_generated_files/system/system.h"

void TMR0_Initialize(void){
    T0CON1bits.CS = 0x02; // Fosc/4 clock selection
    T0CON0bits.MD16 = 1; // 16-bit timer mode
    TMR0H = 0xFC;
    TMR0L = 0x00; // Clock period for 55us
    PIE3bits.TMR0IE = 1;
}

// Used to generate the >50us break required as a reset for WS2812 leds
void __interrupt(irq(IRQ_TMR0)) TMR0_INT(){
    T0CON0bits.EN = 0; // disable tmr0
    TMR0H = 0xFC; // reset the counter to original value
    TMR0L = 0x00;
    PIR3bits.TMR0IF = 0; // clear the interrupt flag
    DMAnCON0bits.SIRQEN = 1; // Starts another DMA transfer
}
