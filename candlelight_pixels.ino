#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// The Gemma pin soldered to the LED data wire, without the 'D' prefix
#define PIN 1
// The number of pixels in the strip after trimming
#define NUM_PIXELS 29

int brightness = 255;

// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(brightness);
  strip.show();
}

void loop() {
   // Base RGB values
   int r = 150, g = 74, b = 12;

  //  Create candlelight effect
  for(int i=0; i<strip.numPixels(); i++) {
    // The higher the second param to random, the stronger the strobe/flicker effect.
    int color_delta = random(0,20);
    int r_flicker = r-color_delta;
    int g_flicker = g-color_delta;
    int b_flicker = b-color_delta;
    if(r_flicker<0) r_flicker=0;
    if(g_flicker<0) g_flicker=0;
    if(b_flicker<0) b_flicker=0;
    // If you get green flames, switch g_flicker and r_flicker.
    strip.setPixelColor(i, g_flicker, r_flicker, b_flicker);
  }
  strip.show();

  // Randomize time between color deltas for flicker effect. 
  // Smaller numbers yield a faster flicker. 
  delay(random(20,113));
}