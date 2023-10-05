#define BANDS 7
#define NUM_LEDS 34
#define OFF_THRESH_PERC 13  // percentage of ADC that is considered the off threshold
#define ADC_RES 4096

#define MIN_HOLD 10
#define HOLD_SLOPE 5
#define MAX_HOLD 30

#define PEAK_HOLD 30
#define HOLD_COUNT 5



void getAudioLevels(void);    // Run the sampling of the data - reads all channels then returns
uint16_t getAudioData (uint8_t band);   // Return 16 bit data
