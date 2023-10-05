/**
 * TMR2 Generated Driver API Header File
 *
 * @file tmr2.h
 *  
 * @defgroup tmr2 TMR2
 *
 * @brief This file contains the API Prototypes and other data types for the TMR2 driver.
 *
 * @version TMR2 Driver Version 3.0.2
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

#ifndef TMR2_H
#define TMR2_H

#include <stdint.h>
#include <stdbool.h>
#include "timer_interface.h"

/**
 Section: Data Type Definitions
*/
/**
 @ingroup tmr2
 @struct TMR_INTERFACE
 @brief This is an instance of TMR_INTERFACE for TMR2 module.
 */
extern const struct TMR_INTERFACE tmr2;

/**
 * @ingroup tmr2
 * @enum TMR2_HLT_EXT_RESET_SOURCE
 * @brief Defines the several modes of operation of the timer with the HLT extension.
 */

typedef enum
{

	/* Roll-over Pulse mode clears the TMRx upon TMRx = PRx, then continue running.
	ON bit must be set and is not affected by Resets
	*/

   /* Roll-over Pulse mode indicates that Timer starts
   immediately upon ON = 1 (Software Control)
   */
   TMR2_ROP_STARTS_TMRON,

   /* Roll-over Pulse mode indicates that the Timer starts
       when ON = 1 and TMRx_ers = 1. Stops when TMRx_ers = 0
     */
   TMR2_ROP_STARTS_TMRON_ERSHIGH,

   /* Roll-over Pulse mode indicates that the Timer starts
      when ON = 1 and TMRx_ers = 0. Stops when TMRx_ers = 1
     */
   TMR2_ROP_STARTS_TMRON_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon rising or falling edge of TMRx_ers
     */
   TMR2_ROP_RESETS_ERSBOTHEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
    upon rising edge of TMRx_ers
     */
   TMR2_ROP_RESETS_ERSRISINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon falling edge of TMRx_ers
     */
   TMR2_ROP_RESETS_ERSFALLINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 0
     */
   TMR2_ROP_RESETS_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 1
     */
   TMR2_ROP_RESETS_ERSHIGH,

    /*In all One-Shot mode the timer resets and the ON bit is
	cleared when the timer value matches the PRx period
	value. The ON bit must be set by software to start
	another timer cycle.
	*/

   /* One shot mode indicates that the Timer starts
    immediately upon ON = 1 (Software Control)
     */
   TMR2_OS_STARTS_TMRON,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers
     */
   TMR2_OS_STARTS_ERSRISINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers
     */
   TMR2_OS_STARTS_ERSFALLINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when either a rising or falling edge is detected on TMRx_ers
     */
   TMR2_OS_STARTS_ERSBOTHEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers rising edge and resets on all
	subsequent TMRx_ers rising edges
     */
   TMR2_OS_STARTS_ERSFIRSTRISINGEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers falling edge and restarts on all
	subsequent TMRx_ers falling edges
     */
   TMR2_OS_STARTS_ERSFIRSTFALLINGEDGE,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 0
     */
   TMR2_OS_STARTS_ERSRISINGEDGEDETECT,
     /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 1
     */
   TMR2_OS_STARTS_ERSFALLINGEDGEDETECT,
   
   /* One shot mode indicates that the Timer starts
    when a TMRx_ers = 1,ON =1 and resets upon TMRx_ers =0
    */
   TMR2_OS_STARTS_TMRON_ERSHIGH = 0x16,
           
   /* One shot mode indicates that the Timer starts
     when a TMRx_ers = 0,ON = 1 and resets upon TMRx_ers =1 
    */
   TMR2_OS_STARTS_TMRON_ERSLOW = 0x17,
        
   /*In all Mono-Stable mode the ON bit must be initially set,but
     not cleared upon the TMRx = PRx, and the timer will start upon
     an TMRx_ers start event following TMRx = PRx.*/
               
   /* Mono Stable mode indicates that the Timer starts
      when a rising edge is detected on the TMRx_ers and ON = 1
    */
   TMR2_MS_STARTS_TMRON_ERSRISINGEDGEDETECT = 0x11,
           
   /* Mono Stable mode indicates that the Timer starts
      when a falling edge is detected on the TMRx_ers and ON = 1
    */
   TMR2_MS_STARTS_TMRON_ERSFALLINGEDGEDETECT = 0x12,
           
   /* Mono Stable mode indicates that the Timer starts
      when  either a rising or falling edge is detected on TMRx_ers 
      and ON = 1
    */
   TMR2_MS_STARTS_TMRON_ERSBOTHEDGE = 0x13
           
} TMR2_HLT_MODE;

/**
 * @ingroup tmr2
 * @enum TMR2_HLT_EXT_RESET_SOURCE
 * @brief Defines the different reset sources of the HLT.
 */
typedef enum
{
    /*
     * T2CKIPPS_PIN as the Timer external reset source
     */
    TMR2_T2CKIPPS_PIN =  0x0,   
    /*
     * TMR4_POSTSCALED as the Timer external reset source
     */
    TMR2_TMR4_POSTSCALED =  0x2,   
    /*
     * CCP1OUT as the Timer external reset source
     */
    TMR2_CCP1OUT =  0x4,   
    /*
     * CCP2OUT as the Timer external reset source
     */
    TMR2_CCP2OUT =  0x5,   
    /*
     * PWM1_OUT1 as the Timer external reset source
     */
    TMR2_PWM1_OUT1 =  0x6,   
    /*
     * PWM1_OUT2 as the Timer external reset source
     */
    TMR2_PWM1_OUT2 =  0x7,   
    /*
     * PWM2_OUT1 as the Timer external reset source
     */
    TMR2_PWM2_OUT1 =  0x8,   
    /*
     * PWM2_OUT2 as the Timer external reset source
     */
    TMR2_PWM2_OUT2 =  0x9,   
    /*
     * PWM3_OUT1 as the Timer external reset source
     */
    TMR2_PWM3_OUT1 =  0xa,   
    /*
     * PWM3_OUT2 as the Timer external reset source
     */
    TMR2_PWM3_OUT2 =  0xb,   
    /*
     * CMP1OUT as the Timer external reset source
     */
    TMR2_CMP1OUT =  0xc,   
    /*
     * CMP2OUT as the Timer external reset source
     */
    TMR2_CMP2OUT =  0xd,   
    /*
     * ZCDOUT as the Timer external reset source
     */
    TMR2_ZCDOUT =  0xe,   
    /*
     * CLC1_OUT as the Timer external reset source
     */
    TMR2_CLC1_OUT =  0xf,   
    /*
     * CLC2_OUT as the Timer external reset source
     */
    TMR2_CLC2_OUT =  0x10,   
    /*
     * CLC3_OUT as the Timer external reset source
     */
    TMR2_CLC3_OUT =  0x11,   
    /*
     * CLC4_OUT as the Timer external reset source
     */
    TMR2_CLC4_OUT =  0x12,   
    /*
     * CLC5_OUT as the Timer external reset source
     */
    TMR2_CLC5_OUT =  0x13,   
    /*
     * CLC6_OUT as the Timer external reset source
     */
    TMR2_CLC6_OUT =  0x14,   
    /*
     * CLC7_OUT as the Timer external reset source
     */
    TMR2_CLC7_OUT =  0x15,   
    /*
     * CLC8_OUT as the Timer external reset source
     */
    TMR2_CLC8_OUT =  0x16,   
    /*
     * UART1_RX_EDGE as the Timer external reset source
     */
    TMR2_UART1_RX_EDGE =  0x17,   
    /*
     * UART1_TX_EDGE as the Timer external reset source
     */
    TMR2_UART1_TX_EDGE =  0x18,   
    /*
     * UART2_RX_EDGE as the Timer external reset source
     */
    TMR2_UART2_RX_EDGE =  0x19,   
    /*
     * UART2_TX_EDGE as the Timer external reset source
     */
    TMR2_UART2_TX_EDGE =  0x1a   
} TMR2_HLT_EXT_RESET_SOURCE;

/**
  Section: Macro Declarations
*/

/**
  Section: TMR2 APIs
*/

/**
 * @ingroup tmr2
 * @brief Initializes the TMR2 module. This routine must be called before any other timer routines.
 * @param None.
 * @return None.
 */
 void TMR2_Initialize(void);

/**
 * @ingroup tmr2
 * @brief Configures the Hardware Limit Timer (HLT) mode.
 * @pre The TMR2 should be initialized with TMR2_Initialize after calling this API.
 * @param mode - Value to write into T2HLTbits.MODE bits.
 * @return None.
 */
void TMR2_ModeSet(TMR2_HLT_MODE mode);

/**
 * @ingroup tmr2
 * @brief Configures the HLT external reset source.
 * @pre The TMR2 should be initialized with TMR2_Initialize after calling this API.
 * @param reset - Value to write into T2RSTbits.RSEL bits.
 * @return None.
 */
void TMR2_ExtResetSourceSet(TMR2_HLT_EXT_RESET_SOURCE reset);

/**
 * @ingroup tmr2
 * @brief Starts TMR2.
 * @pre The TMR2 should be initialized with TMR2_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR2_Start(void);

/**
 * @ingroup tmr2
 * @brief Stops TMR2.
 * @pre The TMR2 should be initialized with TMR2_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR2_Stop(void);

/**
 * @ingroup tmr2
 * @brief Reads the 8-bit from the TMR2 register.
 * @pre The TMR2 should be initialized with TMR2_Initialize() before calling this API.
 * @param None.
 * @return 8-bit data from the TMR2 register.
 */
uint8_t TMR2_Read(void);

/**
 * @ingroup tmr2
 * @brief Writes the 8-bit value to the TMR2 register.
 * @pre The TMR2 should be initialized with TMR2_Initialize() before calling this API.
 * @param timerVal - 8-bit value written to the TMR2 register.
 * @return None.
 */
void TMR2_Write(uint8_t timerVal);

/**
 * @ingroup tmr2
 * @brief Loads the 8-bit value to the PR2 register.
 * @pre The TMR2 should be initialized with TMR2_Initialize() before calling this API.
 * @param periodVal - 8-bit value written to the PR2 register.
 * @return None.
 */
void TMR2_PeriodCountSet(size_t periodVal);

/**
 * @ingroup tmr2
 * @brief Setter function for the TMR2 overflow callback.
 * @param CallbackHandler - Pointer to the custom callback.
 * @return None.
 */
void TMR2_OverflowCallbackRegister(void (* InterruptHandler)(void));

/**
 * @ingroup tmr2
 * @brief Performs the tasks to be executed on timer overflow event.
 * @param None.
 * @return None.
 */
void TMR2_Tasks(void);

#endif // TMR2_H
/**
 End of File
*/
