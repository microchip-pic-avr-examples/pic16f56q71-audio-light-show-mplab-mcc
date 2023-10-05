/**
 * PWM1 Generated Driver API Header File.
 * 
 * @file ccp1.h
 * 
 * @defgroup pwm1 PWM1
 * 
 * @brief This file contains the API prototypes for the PWM1 module.
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

#ifndef PWM1_H
#define PWM1_H

 /**
   Section: Included Files
 */

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

 /**
 * @ingroup pwm1
 * @brief Initializes the CCP1 module. This is called only once before calling other CCP1 APIs.
 * @param None.
 * @return None.
 */
void PWM1_Initialize(void);

/**
 * @ingroup pwm1
 * @brief Loads the 16-bit duty cycle value.
 * @pre PWM1_Initialize() is already called.
 * @param dutyValue - 16-bit duty cycle value.
 * @return None.
 */
void PWM1_LoadDutyValue(uint16_t dutyValue);

/**
 * @ingroup pwm1
 * @brief Returns the PWM output status.
 * @pre PWM1_Initialize() is already called.
 * @param None.
 * @retval True - CCP1 PWM output is high
 * @retval False - CCP1 PWM output is low
 */
bool PWM1_OutputStatusGet(void);

#endif //PWM1_H
/**
 End of File
*/
