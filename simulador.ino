
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#include <Bounce2.h>
const int buttonPin = 2; //sensor 1
Bounce pushbutton = Bounce(buttonPin, 1);  // 10 ms debounce

#define PIN 6 // pin salida
#define NUMPIXELS     100
//Designamos cuantos pixeles tenemos en nuestra cinta led RGB
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pixels.begin(); // Inicializa cinta led RGB
  Serial.begin(9600);
  Serial.println("Pushbutton Bounce library test:");
  
}

byte previousState = HIGH;         // what state was the button last time
unsigned int count = 0;            // how many times has it changed to low
unsigned long countAt = 0;         // when count changed
unsigned int countPrinted = 0;     // last count printed


void loop() {

  

  

   uint32_t rojo = pixels.Color(150,0,0);
   uint32_t verde = pixels.Color(0,150,0);
   uint32_t off = pixels.Color(0,0,0);

  int delayval = 0;// Pausa de cincuenta milisegundos led
  int posicion = 5; // posicion bici 1
  // La numeración de leds en la cinta RGB es la siguiente:  el primer pixel es 0, el segundo es 1 y asi sucesivamente hasta el número total de leds menos uno
  
  for(int i=0;i<NUMPIXELS;i++){ //for pinta bici 1

    if (pushbutton.update()) {
    if (pushbutton.fallingEdge()) {
      count = count + 1;
      countAt = millis();
    }
  } else {
    if (count != countPrinted) {
      unsigned long nowMillis = millis();
      if (nowMillis - countAt > 100) {
        Serial.print("count: ");
        Serial.println(count);
        countPrinted = count;
      }
    }
  }
    
    Serial.println(count);
    if ((i < count/2)) 
      {
         pixels.setPixelColor(i, rojo); // Brillo moderado en rojo
      
         pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
    }
      else {
         pixels.setPixelColor(i, off); // Brillo moderado en rojo

        pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB
      }
    
    delay(0); // Pausa por un periodo de tiempo (en milisegundos).

  }

   

  }
