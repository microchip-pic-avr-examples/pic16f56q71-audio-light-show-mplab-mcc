/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "msgeq.h"
#include "dmx.h"
#include "dma.h"
#include "visuals.h"

/* Purpose for each file in the project:
 * dma.c
 * dmx.c - handles 
 * msgeq.c
 * modes.c

*/

/*
    Main application
*/

int main(void)
{
    // MCC Generated function - initializes clock, I/O pins, the ADC,
    // UART2 (for printf), and the interrupt handler framework
//    __delay_ms(1000);
    SYSTEM_Initialize();
    DMX_Initialize(); // Initialize DMX (bare metal code)
    DMA_Initialize(); // Use DMA to transfer data from dmxData[] array to DMX RX FIFO.
    
    INTERRUPT_GlobalInterruptHighEnable(); // Enable the Global High Interrupts 
    INTERRUPT_GlobalInterruptLowEnable(); // Enable the Global Low Interrupts 
            
    while(1)
    {        
        MODES_T mode = getMode(); // read I/O to determine mode
        getAudioLevels(); // capture audio frequency data & store in array
        // converts ADC frequency readings into a DMX data array dmxData[]
        switch(mode){
            case STANDBY:
                standby();
                break;
            case REACTIVE:
                reactive();
                break;
            case VISUALIZER:
                visualizer();
                break;
        }
        
        if(DGO == 0){ // ensures hardware and software sync
            DMX_sync();
            DMAnCON0bits.SIRQEN = 1;
        }
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", getAudioData(0), getAudioData(1), getAudioData(2), getAudioData(3), getAudioData(4), getAudioData(5), getAudioData(6));
    }    
}