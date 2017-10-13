/*
 * IRremote: IRrecvDump - dump details of IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 * JVC and Panasonic protocol added by Kristian Lauszus (Thanks to zenwheel and other people at the original blog post)
 * LG added by Darryl Smith (based on the JVC protocol)
 */
IRsend irsend;
#include <IRremote.h>

/* 
*  Default is Arduino pin D11. 
*  You can change this to another available Arduino Pin.
*  Your IR receiver should be connected to the pin defined here
*/
int RECV_PIN = 11; 

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(115200);
  irrecv.enableIRIn(); // Start the receiver
}
void dump(decode_results *results) {
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown ");
  }
  else if (results->decode_type == NEC) {
    Serial.print("NEC ");

  }
  else if (results->decode_type == SONY) {
    Serial.print("SONY ");
  }
  else if (results->decode_type == RC5) {
    Serial.print("RC5 ");
  }
  else if (results->decode_type == RC6) {
    Serial.print("RC6 ");
  }
  else if (results->decode_type == PANASONIC) {
    Serial.print("Decoded PANASONIC - Address: ");
    Serial.print(results->address, HEX);
    Serial.print(" Value: ");
  }
  else if (results->decode_type == LG) {
    Serial.print("LG ");
  }
  else if (results->decode_type == JVC) {
    Serial.print("JVC ");
  }
  else if (results->decode_type == AIWA_RC_T501) {
    Serial.print("AIWA_RC_T501 ");
  }
  else if (results->decode_type == WHYNTER) {
    Serial.print("Whynter ");
  }
  Serial.print(results->value, DEC);
  Serial.print(" ");
  Serial.print(results->bits, DEC);
  delay(3000);
  Serial.flush();
}

void loop() {
  if (irrecv.decode(&results)) {
    dump(&results);
    irrecv.resume(); // Receive the next value
  }



  
}
