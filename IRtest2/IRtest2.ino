#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>


int RECV_PIN = 11; // the pin where you connect the output pin of TSOP4838
int led1 = 3;
int itsONled = 0;
/* the initial state of LEDs is OFF (zero)
  the first zero must remain zero but you can
  change the others to 1's if you want a certain
  led to light when the board is powered */
#define code1  63495 // code received from button A
#define code2  30855 // code received from button B
#define code3  22695 // code received from button C

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);   // you can comment this line
  irrecv.enableIRIn();  // Start the receiver
  pinMode(led1, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    Serial.println(value);
    if (itsONled == 1) {       // if first led is on then
      digitalWrite(led1, LOW);   // turn it off when button is pressed
      itsONled = 0;           // and set its state as off
    } else {                      // else if first led is off
      digitalWrite(led1, HIGH); // turn it on when the button is pressed
      itsONled = 1;          // and set its state as on
    }
  }
  irrecv.resume(); // Receive the next value
}

