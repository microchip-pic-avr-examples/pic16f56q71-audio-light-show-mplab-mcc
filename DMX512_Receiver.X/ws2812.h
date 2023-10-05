#define NUM_LEDS 34

typedef struct {
    uint8_t g;
    uint8_t r;
    uint8_t b;
} led_t;

typedef enum {
    INVALID = 0, STANDBY, REACTIVE, VISUALIZER
} MODES_T;

// Define some default colors
led_t red = {.r = 100, .g = 0, .b = 0};
led_t green = {.r = 0, .g = 100, .b = 0};
led_t yellow = {.r = 100, .g = 100, .b = 0};
led_t off = {.r = 0, .g = 0, .b = 0};

uint8_t rxData[4]; // Holds mode, then 3 bytes of data depending on the mode
uint8_t ledData[NUM_LEDS*3];

void reactive(void);
void visualizer(void);

void setLed(uint8_t pos, led_t color);
void setAllLeds(led_t color);
led_t getLed(uint8_t pos);
void dmxToLed(void);