#include <FastLED.h>
#define NUM_LEDS 300 //300
#define DATA_PIN 2 //How boring and obvious!
#define COLOR_ORDER GRB //Green (G), Red (R), Blue (B)
#define CHIPSET WS2812
#define BRIGHTNESS 80
#define VOLTS 5
#define MAX_AMPS 500 //value in milliamps
#define ANIM 10
#define FLASH_COLOR CRGB::White //Couleur des animations 5 et 6
#define DELAY_FLASH 1


CRGB leds[NUM_LEDS];

CRGBPalette16 myAnotherPalette = CRGBPalette16(
  CRGB::Red,
  CRGB::Red,
  CRGB::Red,
  CRGB::Red,
  
  CRGB::Yellow,
  CRGB::Yellow,
  CRGB::Yellow,
  CRGB::Yellow,

  CRGB::Green,
  CRGB::Green,
  CRGB::Green,
  CRGB::Green,

  CRGB::Blue,
  CRGB::Blue,
  CRGB::Blue,
  CRGB::Blue
);

void setup() {
  // put your setup code here, to run once:
  //serial setup:
  Serial.begin(9600);
  //LED setup
  pinMode(13, OUTPUT);  
  FastLED.addLeds<CHIPSET,DATA_PIN,COLOR_ORDER>(leds,NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS,MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
}


void loop() {

  String input = "";
  while (Serial.available()) {
    char char_input = Serial.read();
    input += char_input;
    delay(5);
  }

  // Couleur de la bande definie par des coordonées RGB
  if (input != "" && input.toInt() < 333333333) {
    Serial.println(input);
    Serial.println(input.substring(0,3).toInt());
    Serial.println(input.substring(3,6).toInt());
    Serial.println(input.substring(6,9).toInt());
    for(int i=0; i < NUM_LEDS; i++){
          leds[i].r = input.substring(0,3).toInt(); 
          leds[i].g = input.substring(3,6).toInt();
          leds[i].b = input.substring(6,9).toInt();
        }
        FastLED.show(); 
  

  }
  // Vague depuis le millieu (3)
  if (input.toInt() > 333333332 && input.toInt() < 333333334) {
    FastLED.clear();
    Serial.println("$");
    Serial.println(input);

    while(Serial.available() == 0) {
      FastLED.clear();
      int middleIndex={NUM_LEDS/2 -1};
          for(int i=0; i <= (middleIndex + 1); i++) {
              int forwardIndex={middleIndex+i};
              int backwardIndex={middleIndex-i};
              leds[forwardIndex-6] = CRGB::Black;
              leds[backwardIndex+6] = CRGB::Black;
              leds[forwardIndex] = FLASH_COLOR;
              leds[backwardIndex] = FLASH_COLOR;
              FastLED.show();
              delay(DELAY_FLASH);
          }
              

    }
  } 
  // Animation couleur au hasard pour chaque led (4)
  if (input.toInt() > 444444443 && input.toInt() < 444444445) {
    FastLED.clear();
    Serial.println("*");
    Serial.println(input);

    while(Serial.available() == 0) {
      leds[random(NUM_LEDS)] = ColorFromPalette(myAnotherPalette, random8(), 255, LINEARBLEND);
      leds[random(NUM_LEDS)] = CRGB::Black;
      FastLED.show();
    }
  }  
  // Animation Rouge, Vert, Bleu (5)
  if (input.toInt() > 555555554 && input.toInt() < 555555556) {
    FastLED.clear();
    Serial.println("!");
    Serial.println(input);
    while(Serial.available() == 0) {
    for(int i=0; i < NUM_LEDS; i++){
          leds[i] = CRGB::Red;
        }
    FastLED.show();
    delay(200);

    for(int i=0; i < NUM_LEDS; i++){
          leds[i] = CRGB::Green;
        }
    FastLED.show();
    delay(200);

    for(int i=0; i < NUM_LEDS; i++){
          leds[i] = CRGB::Blue;
        }
    FastLED.show();
    delay(200);

    for(int i=0; i < NUM_LEDS; i++){
          leds[i] = CRGB::Black;
        }
    FastLED.show();
  }
  }
  // Animation directionel (6) 
  if (input.toInt() > 666666665 && input.toInt() < 666666667) {
    FastLED.clear();
    Serial.println("%");
    Serial.println(input);
    while(Serial.available() == 0) {
        for(int i=0; i < NUM_LEDS; i++) {
            if(i > 14){
              leds[i-15] = CRGB::Black;
            }
            leds[i] = FLASH_COLOR;
            FastLED.show();
        }
        FastLED.clear();
    }
  }

}
      


