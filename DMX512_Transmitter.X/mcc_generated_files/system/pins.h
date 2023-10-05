/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define IO_RA0_TRIS                 TRISAbits.TRISA0
#define IO_RA0_LAT                  LATAbits.LATA0
#define IO_RA0_PORT                 PORTAbits.RA0
#define IO_RA0_WPU                  WPUAbits.WPUA0
#define IO_RA0_OD                   ODCONAbits.ODCA0
#define IO_RA0_ANS                  ANSELAbits.ANSELA0
#define IO_RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define IO_RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define IO_RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define IO_RA0_GetValue()           PORTAbits.RA0
#define IO_RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define IO_RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define IO_RA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define IO_RA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define IO_RA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define IO_RA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define IO_RA0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define IO_RA0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA1 aliases
#define IO_RA1_TRIS                 TRISAbits.TRISA1
#define IO_RA1_LAT                  LATAbits.LATA1
#define IO_RA1_PORT                 PORTAbits.RA1
#define IO_RA1_WPU                  WPUAbits.WPUA1
#define IO_RA1_OD                   ODCONAbits.ODCA1
#define IO_RA1_ANS                  ANSELAbits.ANSELA1
#define IO_RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_RA1_GetValue()           PORTAbits.RA1
#define IO_RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_RA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define IO_RA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define IO_RA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define IO_RA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define IO_RA1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define IO_RA1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA2 aliases
#define IO_RA2_TRIS                 TRISAbits.TRISA2
#define IO_RA2_LAT                  LATAbits.LATA2
#define IO_RA2_PORT                 PORTAbits.RA2
#define IO_RA2_WPU                  WPUAbits.WPUA2
#define IO_RA2_OD                   ODCONAbits.ODCA2
#define IO_RA2_ANS                  ANSELAbits.ANSELA2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_RA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_RA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_RA2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA5 aliases
#define RA5_IN2_TRIS                 TRISAbits.TRISA5
#define RA5_IN2_LAT                  LATAbits.LATA5
#define RA5_IN2_PORT                 PORTAbits.RA5
#define RA5_IN2_WPU                  WPUAbits.WPUA5
#define RA5_IN2_OD                   ODCONAbits.ODCA5
#define RA5_IN2_ANS                  ANSELAbits.ANSELA5
#define RA5_IN2_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_IN2_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_IN2_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_IN2_GetValue()           PORTAbits.RA5
#define RA5_IN2_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_IN2_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_IN2_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_IN2_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_IN2_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define RA5_IN2_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define RA5_IN2_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define RA5_IN2_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RB2 aliases
#define MSGEQ_RESET_TRIS                 TRISBbits.TRISB2
#define MSGEQ_RESET_LAT                  LATBbits.LATB2
#define MSGEQ_RESET_PORT                 PORTBbits.RB2
#define MSGEQ_RESET_WPU                  WPUBbits.WPUB2
#define MSGEQ_RESET_OD                   ODCONBbits.ODCB2
#define MSGEQ_RESET_ANS                  ANSELBbits.ANSELB2
#define MSGEQ_RESET_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define MSGEQ_RESET_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define MSGEQ_RESET_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define MSGEQ_RESET_GetValue()           PORTBbits.RB2
#define MSGEQ_RESET_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define MSGEQ_RESET_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define MSGEQ_RESET_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define MSGEQ_RESET_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define MSGEQ_RESET_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define MSGEQ_RESET_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define MSGEQ_RESET_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define MSGEQ_RESET_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 aliases
#define MSGEQ_STROBE_TRIS                 TRISBbits.TRISB3
#define MSGEQ_STROBE_LAT                  LATBbits.LATB3
#define MSGEQ_STROBE_PORT                 PORTBbits.RB3
#define MSGEQ_STROBE_WPU                  WPUBbits.WPUB3
#define MSGEQ_STROBE_OD                   ODCONBbits.ODCB3
#define MSGEQ_STROBE_ANS                  ANSELBbits.ANSELB3
#define MSGEQ_STROBE_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define MSGEQ_STROBE_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define MSGEQ_STROBE_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define MSGEQ_STROBE_GetValue()           PORTBbits.RB3
#define MSGEQ_STROBE_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define MSGEQ_STROBE_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define MSGEQ_STROBE_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define MSGEQ_STROBE_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define MSGEQ_STROBE_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define MSGEQ_STROBE_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define MSGEQ_STROBE_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define MSGEQ_STROBE_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSELB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RE0 aliases
#define IO_RE0_TRIS                 TRISEbits.TRISE0
#define IO_RE0_LAT                  LATEbits.LATE0
#define IO_RE0_PORT                 PORTEbits.RE0
#define IO_RE0_WPU                  WPUEbits.WPUE0
#define IO_RE0_OD                   ODCONEbits.ODCE0
#define IO_RE0_ANS                  ANSELEbits.ANSELE0
#define IO_RE0_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define IO_RE0_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define IO_RE0_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define IO_RE0_GetValue()           PORTEbits.RE0
#define IO_RE0_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define IO_RE0_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define IO_RE0_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define IO_RE0_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define IO_RE0_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define IO_RE0_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define IO_RE0_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define IO_RE0_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/