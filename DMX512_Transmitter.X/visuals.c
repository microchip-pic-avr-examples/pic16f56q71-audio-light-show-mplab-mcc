#include "visuals.h"
#include "mcc_generated_files/system/system.h"
#include "msgeq.h"
#include "dmx.h"

#define SMALL_THRESH 40
#define LARGE_THRESH 80

uint16_t off_thresh = (ADC_RES/100) * OFF_THRESH_PERC; // determine what bottom-end ADC values should be ignored
uint16_t large_thresh = (uint8_t)(ADC_RES * (LARGE_THRESH/100.0)); // ADC threshold to determine the reactive threshold level
uint16_t small_thresh = (uint8_t)(ADC_RES * (SMALL_THRESH/100.0)); // ADC threshold to determine the reactive threshold level

uint16_t led_inc = (ADC_RES-((ADC_RES/100) * OFF_THRESH_PERC))/NUM_LEDS; // how much increase in ADC values equals 1 more LED on
uint8_t led_thresh1 = (uint8_t)(NUM_LEDS * 0.33); // # of LEDs to determine first threshold level
uint8_t led_thresh2 = (uint8_t)(NUM_LEDS * 0.66); // # of LEDs to determine second threshold level

// readed I/O pins to figure out if in standby, reactive, or visualizer
MODES_T getMode(void){
    
    if(!IO_RA0_GetValue()){
        return VISUALIZER;
    }
    
    return STANDBY;
}

typedef struct {
    led_t color;
    uint8_t stage;
} standby_t;


#define MAX_SB_VAL 50
led_t updateStandbyVals(led_t currentVals){
    uint8_t r = currentVals.r;
    uint8_t g = currentVals.g;
    uint8_t b = currentVals.b;
    static uint8_t init_index = 0;
    if(r == MAX_SB_VAL && g < MAX_SB_VAL && b == 0){ // increase green phase
        currentVals.g++;
    } else if(g == MAX_SB_VAL && r > 0 && b == 0){ // decrease red phase
        currentVals.r--;
    } else if(g == MAX_SB_VAL && b < MAX_SB_VAL && r == 0){ // increase blue phase
        currentVals.b++;
    } else if(b == MAX_SB_VAL && g > 0 && r == 0){ // decrease green phase
        currentVals.g--;
    } else if(b == MAX_SB_VAL && r < MAX_SB_VAL && g == 0){ // increase red phase
        currentVals.r++;
    } else if(r == MAX_SB_VAL && b > 0 && g == 0){ // decrease blue phase
        currentVals.b--;
    } else{ // reset to a known value
        currentVals.r = 0;
        currentVals.g = 0;
        currentVals.b = MAX_SB_VAL;
    }
    return currentVals;
}
/*
 * Standby doesn't respond to music, it cycles a color wave through the tubes
 */

// RGB loop wave for 7 nodes
#define STANDBY_DELAY 3
led_t standbyLed = {.r = MAX_SB_VAL, .g = 0, .b = 0};
void standby(void){
    uint8_t index = 0;
    static uint8_t standby_delay_counter = 0;
    static led_t standbyVals[NODES] = {
        {.r = MAX_SB_VAL,       .g = 0,             .b =0},
        {.r = MAX_SB_VAL,       .g = (uint8_t)(MAX_SB_VAL*.85),.b = 0},
        {.r = (uint8_t)(MAX_SB_VAL*.275),  .g = MAX_SB_VAL,    .b = 0},
        {.r = 0,                .g = (uint8_t)MAX_SB_VAL,    .b = (uint8_t)(MAX_SB_VAL*.57)},
        {.r = 0,                .g = (uint8_t)(MAX_SB_VAL*.57),.b = MAX_SB_VAL},
        {.r = (uint8_t)(MAX_SB_VAL*.275),  .g = 0,             .b = MAX_SB_VAL},
        {.r = MAX_SB_VAL,       .g = 0,             .b = (uint8_t)(MAX_SB_VAL*.85)},
    };
    dmxData[index++] = STANDBY;
    if(standby_delay_counter < STANDBY_DELAY){
        standby_delay_counter++;
    } else{
        for(uint8_t i = 0; i < NODES; i++){
            standbyVals[i]  = updateStandbyVals(standbyVals[i]);
            dmxData[index++] = standbyVals[i].g;
            dmxData[index++] = standbyVals[i].r;
            dmxData[index++] = standbyVals[i].b;        
        }
        standby_delay_counter = 0;
    }
}

#define ONVAL 50
#define MAX_VAL 150
led_t cycleColor(led_t value){
    if(value.r){ // red is set
        if(value.g){ // green is set
            value.r = 0; // turn off red
        } else { // green not set
            value.g = ONVAL; // turn on green
        }
    } else if(value.g){ // green is set
        if(value.b){ // blue is set
            value.g = 0; // turn off green
        } else { // blue is not set
            value.b = ONVAL; // turn on blue
        }
    } else if(value.b){ // blue is set
        if(value.r){ // red is set
            value.b = 0; // turn off blue
        } else { // red is not set
            value.r = ONVAL; // turn on red
        }
    } else { // value array is 0
        value.r = ONVAL; // turn on red
    }
    return value;
}

led_t pulseColor(led_t value){
    value.r = (value.r != 0) ? MAX_VAL : 0;
    value.g = (value.g != 0) ? MAX_VAL : 0;
    value.b = (value.b != 0) ? MAX_VAL : 0;
    return value;
}

/*
 * Responds to music, changing the LED brightness when the frequency amplitude changes a certain amount
 * Then changes the tube color if the frequency amplitude is even higher.
 */
// Reactive colors
#define COLOR_INC 1

void reactive(void){
    uint8_t index = 0;
    static led_t values[NODES];
    static bool transitioning[NODES];
    static led_t newValues[NODES];
    dmxData[index++] = REACTIVE; // set start code as reactive
    // populate DMX data for each node
    for(uint8_t i = 0; i < NODES; i++){
        uint16_t channel_data = getAudioData(i); // get channel frequency amplitude
        if(channel_data > large_thresh && transitioning[i] == false){ // change color
            newValues[i] = cycleColor(values[i]); // cycle leds to next color
            transitioning[i] = true;
            //printf("T: %d, %d\n", i, channel_data);
        }
//        else if(channel_data > small_thresh && transitioning[i] == false){ // change intensity
//            // set target to return to standby colors
//            newValues[i] = values[i];
//            // pulse current color to MAX_VAL 
//            values[i] = pulseColor(values[i]);
//            dmxData[index++] = values[i].g;
//            dmxData[index++] = values[i].r;
//            dmxData[index++] = values[i].b;
//        }
        else if(transitioning[i] == true){ // gradually return to standby color
            values[i].r = (values[i].r < newValues[i].r) ? values[i].r+COLOR_INC : (values[i].r > newValues[i].r) ? values[i].r-COLOR_INC : values[i].r;
            values[i].g = (values[i].g < newValues[i].g) ? values[i].g+COLOR_INC : (values[i].g > newValues[i].g) ? values[i].g-COLOR_INC : values[i].g;
            values[i].b = (values[i].b < newValues[i].b) ? values[i].b+COLOR_INC : (values[i].b > newValues[i].b) ? values[i].b-COLOR_INC : values[i].b;
            if(values[i].r == newValues[i].r && values[i].g == newValues[i].g && values[i].b == newValues[i].b){ // has transitioned to new color
                transitioning[i] = false;
            }
        }
        dmxData[index++] = values[i].g;
        dmxData[index++] = values[i].r;
        dmxData[index++] = values[i].b;
//        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t",);
    }
}

/*
 * Maps the amplitude of the incoming frequency signal to the height of the tube
 * The greater the amplitude, the more LEDs are on. The tube is split up into green,
 * yellow, and red colors, with a threshold number determining where in the tube the
 * LEDs transition from green, yellow, and red
 */
void visualizer(void){
    uint8_t index = 0;
    static uint8_t current_hold[NODES];
    static bool new_peak[NODES];
    dmxData[index++] = VISUALIZER; // set start code
    // populate DMX data for each node
    for(uint8_t i = 0; i < NODES; i++){
        uint16_t channel_data = getAudioData(i);
        // set Number of LEDs to be on
        uint8_t leds = (channel_data > off_thresh) ? (channel_data - off_thresh)/led_inc : 1; // prevent overflow, always have 1 led on
        // this IF statements gives the linear decreasing instead of the bar immediately disappearing
        if(leds < dmxData[index]){ // if new value is lower than old, slowly lower bar
            uint8_t hold_time = (new_peak[i]) ? PEAK_HOLD : HOLD_COUNT;
            if(current_hold[i] < hold_time){ // hold at current position until it is time to drop 1 LED
                current_hold[i]++;
            } else { // drop 1 LED
                current_hold[i] = 0; //reset hold count
                dmxData[index] = dmxData[index]-1; // if fewer leds are to be shown, reduce bar by only 1 LED at a time
                new_peak[i] = false;
            }
        } else { // otherwise jump up right to new value
            dmxData[index] = leds;
            new_peak[i] = true;
        }
        index++;
        dmxData[index++] = led_thresh1; // color threshold 1
        dmxData[index++] = led_thresh2; // color threshold 2
    }
}