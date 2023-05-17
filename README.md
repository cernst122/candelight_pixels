# candlelight_pixels
Create a candlelight effect for NeoPixel/WS2811 strips.

This code is a modified version of ‘Neopixel Flames’ (https://codebender.cc/sketch:271084). 

Using the Arduino IDE, open the file and select ‘Adafruit Gemma 8MHz’ as the board and ‘USBtinyISP’ as the programmer. Gemma does not use a port. 
Connect the Gemma board with the USB cable, then upload the code to the board. 

*Note: Not all USB v3 ports recognize the Gemma bootloader. Use a USB hub or USB v2 port if the Gemma will not enter bootloader mode.* 

If you see the error `A programmer is required to upload`, navigate to `Sketch > Upload Using Programmer`.

This code is formatted for GRB pixels instead of RGB pixels. If you end up with green flames, switch the `g` and `r` variables in the code.  Play with the following variables to affect the code in the following ways:
  *  `brightness (0-255)`: a higher value will be more visible, but will drain the battery faster. 
  *  `r, g, b (0-255)`: these are the base color values that your flame will flicker away from. 
  *  `color_delta`: the degree to which a flickering flame strays from its base color. A bigger delta will have a more pronounced effect, but could stray into non-fire-toned colors. 

Judge your candle flickering effect on the whole LED strip, not just one. What looks good on one LED looks chaotic across an entire strip.

