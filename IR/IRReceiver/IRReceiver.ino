#include <IRremote.h>
const int RECV_PIN = 11;
//const int switch1 = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }

  /*
   if (results.value == 0x34895725) { //VolumeHigh
    digitalWrite(switch1, HIGH);
    delay(200);
    digitalWrite(switch1, LOW);
    results.value = 0x00000000;
  }
  */
}
