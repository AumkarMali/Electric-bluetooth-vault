#include "Arduino.h"
#include "Servo.h"

// Pin Definitions
#define SERVO9G_PIN_SIG  2

const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;


// Global variables and defines
const int Rest   = 90;  //Starting position
const int Target = -50; //Position when event is detected
int count = 0;
// object initialization
Servo servo9g;


long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start, 9-lock, 2-open");
    
    servo9g.attach(SERVO9G_PIN_SIG);
    servo9g.write(Rest);
    delay(100);
    servo9g.detach();
    
}


char rx_byte = 0;

void loop() 
{
  rx_byte = '\0';
  while(!Serial.available());
  while(Serial.available() > 0) {
    rx_byte = Serial.read();  
  }
  
if(rx_byte == 'a') {
    servo9g.attach(SERVO9G_PIN_SIG);
    servo9g.write(Target);  
    delay(500); 
    servo9g.detach(); 
   
    }
if(rx_byte == 'b') {
    servo9g.attach(SERVO9G_PIN_SIG);
    servo9g.write(Rest);
    delay(500);  
    servo9g.detach();
     
    }
}
