#include "mcc_generated_files/system/system.h"
#include "msgeq.h"


// Array for analog data 
uint16_t msgeq_data[7];

// Pulse MSGEQ7 so it outputs the next frquency
void strobe(void)
{
    MSGEQ_STROBE_SetHigh();
    __delay_us(40); // Min strobe high 18us - Strobe to strobe min 72us
    MSGEQ_STROBE_SetLow();
    __delay_us(40); // Min time to settle 36us - so do 40  
}

// Cycles MSGEQ7 chip through all audio frequencies and samples each frequency with the ADC
void getAudioLevels(void)
{  
    // Reset MSGEQ to first frequency band
    MSGEQ_RESET_SetHigh();
    strobe();
    __delay_us(10);
    MSGEQ_RESET_SetLow();
     
    // Read audio channel
    for(uint8_t i = 0; i < BANDS; i++)
    {
        strobe(); // Releases frequency to be shown
        ADC_SelectContext(0);
        ADC_SetRepeatCount(16); // CRS = 4, we take the average of 16 samples
        ADC_StartConversion();
        while(!ADC_IsConversionDone());
        msgeq_data[i] = ADC_GetFilterValue(); // store averaged value
    }
}


uint16_t getAudioData(uint8_t band)
{
    if(band < BANDS){
        return msgeq_data[band];
    }
    return 0;
}