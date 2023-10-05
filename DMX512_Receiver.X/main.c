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
#include "dmx.h"
#include "dma.h"
#include "spi.h"
#include "tmr0.h"
#include "ws2812.h"

/*
 The receiver code flow can be broken down into 3 parts:
 * 1. DMX data is moved from the UART RX buffer to an array, rxData[], via DMA
 * 2. The main while loop converts the data in rxData[] into WS2812 G,R,B values stored in ledData[]
 * 3. DMA moves the WS2812 data from ledData[] into the SPI TX FIFO. By AND/ORing
 * a PWM & SPI signal in a CLC, any data sent out the SPI module is logically converted into the WS2812 protocol equivalent,
 * allowing the SPI peripheral to drive WS2812 leds
*/
int main(void)
{
//    setAllLeds(green);
    for(int i = 0; i < 11; i++){
        setLed(i, green);
    }
    for(int i = 11; i < 22; i++){
        setLed(i, yellow);
    }
    for(int i = 22; i < 25; i++){
        setLed(i, red);
    }    
    for(int i = 25; i < 34; i++){
        setLed(i, off);
    }    
    SYSTEM_Initialize(); // Initializes all the MCC generated functionality
    TMR0_Initialize(); // Generates a 60us interrupt for the WS2812 reset signal
    if(DMX_Initialize()){  // DMX initialize (bare metal code) checks if valid data selection is occurring
        setAllLeds(red);
    }
    SPI1_Initialize(); // Setup WS2812 communications
    DMA_Initialize(); // DMA initialize (bare metal code))
    
    INTERRUPT_GlobalInterruptHighEnable(); // Enable the Global High Interrupts 
    INTERRUPT_GlobalInterruptLowEnable(); // Enable the Global Low Interrupts 

    while(1){
        dmxToLed(); // Converts the DMX command data into WS2812 G,R,B equivalent
        //printf("%d,%d,%d,%d,%d,%d,%d\n",IO_RD1_GetValue(),IO_RD2_GetValue(),IO_RD3_GetValue(),IO_RD4_GetValue(),IO_RD5_GetValue(),IO_RD6_GetValue(),IO_RD7_GetValue());
//        printf("%d\n", getNodeNum());
    }
}