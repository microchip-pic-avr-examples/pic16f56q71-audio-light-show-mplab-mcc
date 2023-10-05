/**
 * CLC1 Generated Driver File.
 * 
 * @file clc1.c
 * 
 * @ingroup  clc1
 * 
 * @brief This file contains the API implementations for the CLC1 driver.
 *
 * @version CLC1 Driver Version 1.0.1
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


#include <xc.h>
#include "../clc1.h"


void CLC1_Initialize(void)
{
    
    // SLCT 0x0; 
    CLCSELECT = 0x0;
    // LCG1POL inverted; LCG2POL inverted; LCG3POL not_inverted; LCG4POL not_inverted; LCPOL not_inverted; 
    CLCnPOL = 0x3;
    // LCD1S CLCIN0 (CLCIN0PPS); 
    CLCnSEL0 = 0x0;
    // LCD2S SPI1 SCK OUT; 
    CLCnSEL1 = 0x30;
    // LCD3S SPI1 SDO OUT; 
    CLCnSEL2 = 0x2F;
    // LCD4S CCP1; 
    CLCnSEL3 = 0x17;
    // LCG1D1N disabled; LCG1D1T disabled; LCG1D2N enabled; LCG1D2T disabled; LCG1D3N disabled; LCG1D3T enabled; LCG1D4N enabled; LCG1D4T disabled; 
    CLCnGLS0 = 0x64;
    // LCG2D1N disabled; LCG2D1T disabled; LCG2D2N disabled; LCG2D2T disabled; LCG2D3N disabled; LCG2D3T disabled; LCG2D4N disabled; LCG2D4T disabled; 
    CLCnGLS1 = 0x0;
    // LCG3D1N disabled; LCG3D1T disabled; LCG3D2N disabled; LCG3D2T enabled; LCG3D3N disabled; LCG3D3T disabled; LCG3D4N disabled; LCG3D4T disabled; 
    CLCnGLS2 = 0x8;
    // LCG4D1N disabled; LCG4D1T disabled; LCG4D2N disabled; LCG4D2T disabled; LCG4D3N disabled; LCG4D3T enabled; LCG4D4N disabled; LCG4D4T disabled; 
    CLCnGLS3 = 0x20;
    // LCOUT 0x00; 
    CLCDATA = 0x0;
    // LCMODE AND-OR; LCINTN disabled; LCINTP disabled; LCEN enabled; 
    CLCnCON = 0x80;

}


bool CLC1_OutputStatusGet(void)
{
    return(CLCDATAbits.CLC1OUT);
}
/**
 End of File
*/
