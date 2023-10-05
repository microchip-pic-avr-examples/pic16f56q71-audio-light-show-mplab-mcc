/**
 * ADC Generated Driver File
 * 
 * @file adc.c
 * 
 * @ingroup adc
 * 
 * @brief This is the generated driver implementation file for the ADC driver.
 *
 * @version ADC Driver Version 1.0.1
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
#include "../adc.h"
#include "../../system/interrupt.h"


void ADC_Initialize(void)
{
    //GO_nDONE undefined; IC single ended mode; ADFM right justified; ADCS FOSC; CSEN disabled; ADCONT disabled; ADON disabled; 
    ADCON0 = 0x4;

    //ADACT disabled; 
    ADACT = 0x0;

    //ADCCS FOSC/64; 
    ADCLK = 0x1F;

    //CGA0 disabled; CGA1 enabled; CGA2 disabled; CGA3 disabled; CGA4 disabled; CGA5 disabled; CGA6 disabled; CGA7 disabled; 
    ADCGA = 0x2;

    //CGB0 disabled; CGB1 disabled; CGB2 disabled; CGB3 disabled; CGB4 disabled; CGB5 disabled; CGB6 disabled; CGB7 disabled; 
    ADCGB = 0x0;

    //CGC0 disabled; CGC1 disabled; CGC2 disabled; CGC3 disabled; CGC4 disabled; CGC5 disabled; CGC6 disabled; CGC7 disabled; 
    ADCGC = 0x0;

    //CGD0 disabled; CGD1 disabled; CGD2 disabled; CGD3 disabled; CGD4 disabled; CGD5 disabled; CGD6 disabled; CGD7 disabled; 
    ADCGD = 0x0;

    //CGE0 disabled; CGE1 disabled; CGE2 disabled; 
    ADCGE = 0x0;

    /****************************************
    *         Configure Context-1           *
    ****************************************/
    //CTX 0; CTXSW user content; 
    ADCTX = 0x0;

    //ADLTHL 0; 
    ADLTHL = 0x0;

    //ADLTHH 0; 
    ADLTHH = 0x0;

    //ADUTHL 26; 
    ADUTHL = 0x1A;

    //ADUTHH 13; 
    ADUTHH = 0xD;

    //ADSTPTL 0; 
    ADSTPTL = 0x0;

    //ADSTPTH 0; 
    ADSTPTH = 0x0;

    //ADACCL 0x0; 
    ADACCL = 0x0;

    //ADACCH 0x0; 
    ADACCH = 0x0;

    //ADACCU 0x0; 
    ADACCU = 0x0;

    //ADCNT 0x0; 
    ADCNT = 0x0;

    //ADRPT 0; 
    ADRPT = 0x0;

    //ADRESL 0x0; 
    ADRESL = 0x0;

    //ADRESH 0x0; 
    ADRESH = 0x0;

    //ADCHS ANA1; 
    ADPCH = 0x1;

    //ADCHS VSS; 
    ADNCH = 0x3B;

    //ADACQL 1; 
    ADACQL = 0x1;

    //ADACQH 0; 
    ADACQH = 0x0;

    //ADCAP Additional uC disabled; 
    ADCAP = 0x0;

    //ADPREL 0; 
    ADPREL = 0x0;

    //ADPREH 0; 
    ADPREH = 0x0;
    
    //Disable continuous operation
    ADCON0bits.ADCONT = 0;

    //ADDSEN disabled; PCSC sampling capacitor and external I/O pin; ADGPOL digital_low; ADIPEN disabled; ADPPOL Vss; 
    ADCON1 = 0x0;

    //ADMD Burst_average_mode; ADACLR enabled; ADCRS 4; ADPSIS RES; 
    ADCON2 = 0x4B;

    //ADTMD disabled; ADSOI ADGO not cleared; ADCALC First derivative of Single measurement; 
    ADCON3 = 0x0;

    //ADMATH registers not updated; 
    ADSTAT = 0x0;

    //ADNREF VSS; ADPREF VDD; 
    ADREF = 0x0;
    
    //SSI scan sequence continues; CHEN channel content is not included; 
    ADCSEL1 = 0x0;

    // Clear the ADC interrupt flag
    PIR1bits.ADIF = 0;

    //Clear ADC Context-1 Threshold Interrupt Flag
    PIR1bits.ADCH1IF = 0;

    //Clear ADC Context-2 Threshold Interrupt Flag
    PIR1bits.ADCH2IF = 0;

    //Clear ADC Context-3 Threshold Interrupt Flag
    PIR1bits.ADCH3IF = 0;

    //Clear ADC Context-4 Threshold Interrupt Flag
    PIR1bits.ADCH4IF = 0;

    //Enable ADC
    ADCON0bits.ADON = 1;
}

inline void ADC_SelectContext(adc_context_t context)
{
    ADCTX = context;
}

void ADC_EnableChannelScan(adc_context_t context)
{
    switch (context)
    {
    case context_1:
        ADCSEL1bits.CHEN = 1;
        break;
    default:
        break;
    }
}

void ADC_DisableChannelScan(adc_context_t context)
{
    switch (context)
    {
    case context_1:
        ADCSEL1bits.CHEN = 0;
        break;
    default:
        break;
    }
}

inline void ADC_EnableChannelSequencer(void)
{
    ADCON0bits.CSEN = 1;
}

inline void ADC_DisableChannelSequencer(void)
{
    ADCON0bits.CSEN  = 0;
}

inline void ADC_SetChannel(adc_channel_t channel)
{
    ADPCH = channel;
}

void ADC_StartConversionOnChannel(adc_channel_t channel)
{
    // select the A/D channel
    ADC_SetChannel(channel);  

    // Start the conversion
    ADC_StartConversion();
}

inline void ADC_DischargeSampleCapacitor(void)
{
    //Set ADC channel to AVss
    ADPCH = 0x3b;
}

inline void ADC_StartConversion(void)
{
    ADCON0bits.ADGO = 1;
}

inline void ADC_StopConversion(void)
{
    ADCON0bits.ADGO = 0;
}

inline bool ADC_IsConversionDone(void)
{
    return ((unsigned char)(!ADCON0bits.ADGO));
}

inline adc_result_t ADC_GetConversionResult(void)
{
    //Return result of A/D conversion
    return ((adc_result_t) ((ADRESH << 8) | ADRESL));
}

adc_result_t ADC_GetSingleConversion(adc_channel_t channel)
{
    adc_result_t result;

    // select the A/D channel
    ADC_SetChannel(channel);  

    // Disable the continuous mode.
    ADC_DisableContinuousConversion();

    // Start the conversion
    ADC_StartConversion();

    // Wait for the conversion to finish
    while (!ADC_IsConversionDone())
    {
    }
    
    // Conversion finished, return the result
    result = ADC_GetConversionResult();
    return result;
}

inline uint8_t ADC_GetConversionStageStatus(void)
{
    return ADSTATbits.ADSTAT;
}

inline void ADC_EnableContinuousConversion(void)
{
    ADCON0bits.ADCONT = 1;
}

inline void ADC_DisableContinuousConversion(void)
{
    ADCON0bits.ADCONT = 0;
}

inline void ADC_SetStopOnInterrupt(void)
{
    ADCON3bits.ADSOI = 1;
}

inline void ADC_EnableDoubleSampling(void)
{
    ADCON1bits.ADDSEN = 1;
}

void ADC_SetAcquisitionRegister(uint16_t acquisitionValue)
{
    ADACQH = (uint8_t)(acquisitionValue >> 8);
    ADACQL = (uint8_t)acquisitionValue;
}

void ADC_SetPrechargeRegister(uint16_t prechargeTime)
{
    ADPREH = (uint8_t)(prechargeTime >> 8);
    ADPREL = (uint8_t)prechargeTime;
}
void ADC_DefineSetPoint(uint16_t setPoint)
{
    ADSTPTH = (uint8_t)(setPoint >> 8);
    ADSTPTL = (uint8_t)setPoint;
}

void ADC_SetUpperThreshold(uint16_t upperThreshold)
{
    ADUTHH = (uint8_t)(upperThreshold >> 8);
    ADUTHL = (uint8_t)upperThreshold;
}

void ADC_SetLowerThreshold(uint16_t lowerThreshold)
{
    ADLTHH = (uint8_t)(lowerThreshold >> 8);
    ADLTHL = (uint8_t)lowerThreshold;
}
inline bool ADC_HasErrorCrossedUpperThreshold(void)
{
    return ADSTATbits.ADUTHR;
}

inline bool ADC_HasErrorCrossedLowerThreshold(void)
{
    return ADSTATbits.ADLTHR;
}

inline void ADC_SetRepeatCount(uint8_t repeatCount)
{
    ADRPT = repeatCount;
}

inline uint8_t ADC_GetCurrentCountofConversions(void)
{
    return ADCNT;
}

inline uint24_t ADC_GetAccumulatorValue(void)
{    
    return (((uint24_t)ADACCU << 16) | ((uint24_t)ADACCH << 8) | ADACCL);
}

inline void ADC_ClearAccumulator(void)
{
    ADCON2bits.ADACLR = 1;
}

inline bool ADC_HasAccumulatorOverflowed(void)
{
    return ADSTATbits.ADAOV;
}

inline int16_t ADC_GetErrorCalculation(void)
{
    return ((int16_t) ((ADERRH << 8) | ADERRL));
}

inline uint16_t ADC_GetPreviousResult(void)
{
    return ((uint16_t) ((ADPREVH << 8) | ADPREVL));
}

inline uint16_t ADC_GetFilterValue(void)
{
    return ((uint16_t) ((ADFLTRH << 8) | ADFLTRL));
}





