#include <IRremote.h>
const int RECV_PIN = 11;
int LED = 13;
bool ON = false;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    irrecv.resume();
    Serial.println(results.value);
    int value = results.value;
    if (results.value == 16753245) {
      if (ON) {
        Serial.println("LOW");
        digitalWrite(LED, LOW);
        ON = false;
      }
      else {
        digitalWrite(LED, HIGH);
        Serial.println("HIGH");
        ON = true;
      }
    }
  }
}

  /*
    if (results.value == 0x34895725) { //VolumeHigh
    digitalWrite(switch1, HIGH);
    delay(200);
    digitalWrite(switch1, LOW);
    results.value = 0x00000000;
    }
  */

