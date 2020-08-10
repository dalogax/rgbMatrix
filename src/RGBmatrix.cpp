

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN_POT        A0
#define PIN        D5
#define NUMPIXELS  20

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint32_t MAGENTA = pixels.Color(255, 0, 255);
uint32_t GREEN = pixels.Color(0, 255, 0);
uint32_t RED = pixels.Color(255, 0, 0);
uint32_t BLUE = pixels.Color(0, 0, 255);
uint32_t WHITE = pixels.Color(255, 255, 255);
uint32_t BLACK = pixels.Color(0, 0, 0);
uint32_t YELLOW = pixels.Color(255, 255, 0);
uint32_t TEAL = pixels.Color(0, 255, 255);
uint32_t ORANGE = pixels.Color(255, 100, 0);

uint32_t customPalette[NUMPIXELS] = {
  BLUE, BLUE, BLUE, BLUE,
  BLUE, WHITE, WHITE, BLUE,
  WHITE, GREEN, GREEN, WHITE,
  BLUE, WHITE, WHITE, BLUE,
  BLUE, BLUE, BLUE, BLUE
};

uint32_t candlePalette[NUMPIXELS] = {
  YELLOW, YELLOW, YELLOW, YELLOW,
  YELLOW, ORANGE, ORANGE, YELLOW,
  YELLOW, ORANGE, ORANGE, YELLOW,
  YELLOW, ORANGE, ORANGE, YELLOW,
  YELLOW, YELLOW, YELLOW, YELLOW
};

void setPalette(uint32_t palette[]){
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, palette[i]);
  }
   pixels.show();
}

void setup() {
  Serial.begin(115200);

  pixels.begin();
  pixels.clear();
}

void loop() {

  Serial.println(analogRead(A0));

  pixels.setBrightness(map(analogRead(A0),0,1023,0,255));

  setPalette(candlePalette); 
}