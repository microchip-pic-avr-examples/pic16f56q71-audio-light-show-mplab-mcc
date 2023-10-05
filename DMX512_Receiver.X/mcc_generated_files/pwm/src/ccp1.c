/**
 * PWM1 Generated Driver File.
 * 
 * @file ccp1.c
 * 
 * @ingroup pwm1
 * 
 * @brief This file contains the API implementations for the PWM1 driver.
 *
 * @version PWM1 Driver Version 2.0.2
*/
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

 /**
   Section: Included Files
 */

#include <xc.h>
#include "../ccp1.h"

/**
  Section: Macro Declarations
*/

#define PWM1_INITIALIZE_DUTY_VALUE    25

/**
  Section: PWM1 Module APIs
*/

void PWM1_Initialize(void) 
{
    // Set the PWM1 to the options selected in the User Interface
    
    // CCPM PWM; EN enabled; FMT right_aligned; 
    CCP1CON = 0x8C;
    
    // CCPRH 0; 
    CCPR1H = 0x0;
    
    // CCPRL 25; 
    CCPR1L = 0x19;
    
    // Selecting Timer 2
    CCPTMRS0bits.C1TSEL = 0x1;
}

void PWM1_LoadDutyValue(uint16_t dutyValue) 
{
	  dutyValue &= 0x03FF;
    
    // Load duty cycle value
    if(CCP1CONbits.FMT)
    {
        dutyValue <<= 6;
        CCPR1H = (uint8_t)(dutyValue >> 8);
        CCPR1L = (uint8_t)dutyValue;
    }
    else
    {
        CCPR1H = (uint8_t)(dutyValue >> 8);
        CCPR1L = (uint8_t)dutyValue;
    }
}

bool PWM1_OutputStatusGet(void)
{
    // Returns the output status
    return(CCP1CONbits.OUT);
}

/**
 End of File
*/
