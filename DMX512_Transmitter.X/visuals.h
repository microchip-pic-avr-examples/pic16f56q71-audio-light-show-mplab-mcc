#define NODES 7

#include "mcc_generated_files/system/system.h"

typedef struct {
    uint8_t g;
    uint8_t r;
    uint8_t b;
    
} led_t;

led_t red = {0, 100, 0};
led_t yellow = {100, 100, 0};
led_t green = {100, 0, 0};

typedef enum {INVALID, STANDBY, REACTIVE, VISUALIZER} MODES_T;

void set_dmx_data(uint8_t row, uint16_t leds);
void run (void);

uint8_t dmxData[NODES*3+1];

MODES_T getMode(void);
led_t updateStandbyVals(led_t currentVals);
void standby(void);
void reactive(void);
void visualizer(void);