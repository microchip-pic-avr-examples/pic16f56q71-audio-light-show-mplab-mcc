#include "mcc_generated_files/system/system.h"
#include "ws2812.h"

void setLed(uint8_t pos, led_t color){
    ledData[pos*3] = color.g;
    ledData[pos*3+1] = color.r;
    ledData[pos*3+2] = color.b;
}

void setAllLeds(led_t color){
    for(uint8_t i = 0; i < NUM_LEDS; i++){ // set ledData[] array to an initial color
        setLed(i, color);
    }
}

// Converts DMX data to WS2812 data that the SPI will transmit
void dmxToLed(void) {
    switch (rxData[0]) {
        case STANDBY:
        case REACTIVE: // DMX sends G,R,B values that the entire led strip turns to
            reactive();
            break;
        case VISUALIZER: // DMX sends # of leds to turn on and the 2 threshold numbers for the colors
            visualizer();
            break;
    }
}

// Set entire strip to G,R,B value sent through DMX
void reactive(void){
    led_t color = {.g = rxData[1], .r = rxData[2], .b = rxData[3]};
    for(uint8_t i = 0; i < NUM_LEDS; i++){
        setLed(i, color);
    }
}

// DMX sends # of leds and 2 thresholds. This function converts that into G,R,B data
// Below thresh1, turn leds green, Between thresh1 & thresh2, leds turn yellow, above thresh2, leds turn red
void visualizer(void) {
    uint8_t leds = rxData[1];
    uint8_t thresh1 = rxData[2];
    uint8_t thresh2 = rxData[3];
    for (uint8_t i = 0; i < rxData[1]; i++) { // set color leds
        if (i < thresh1) {
            setLed(i, green);
        } else if (i < thresh2) {
            setLed(i, yellow);
        } else {
            setLed(i, red);
        }
    }
    for (uint8_t i = leds; i < NUM_LEDS; i++) { // turn off the rest of the leds
        setLed(i, off);
    }
}