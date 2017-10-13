#include <IRremote.h>
IRsend irsend;
//pin zero is for the transistor
const int temperaturePin = 0;

void setup() {
  Serial.begin(115200);
}
 
unsigned long integerValue=0;  // Max value is 65535 .. shouldnt it be larger
char incomingByte;
 
void loop() {
  if (Serial.available() > 0) {   // something came across serial
    integerValue = 0;         // throw away previous integerValue
    while(1) {            // force into a loop until 'n' is received
      incomingByte = Serial.read();
      if (incomingByte == '\n') break;   // exit the while(1), we're done receiving
      if (incomingByte == -1) continue;  // if no characters are in the buffer read() returns -1
      integerValue *= 10;  // shift left 1 decimal place
      // convert ASCII to integer, add, and shift left 1 decimal place
      integerValue = ((incomingByte - 48) + integerValue);
    }
    //Serial.println(integerValue);   // Do something with the value
    if(integerValue < 5000 && integerValue > 5){
    for (int i = 0; i < 3; i++) {
    irsend.sendRC5(integerValue, 12);  
    delay(40);
    }
    }
    else if (integerValue > 5000){
    for (int i = 0; i < 3; i++) {
    irsend.sendNEC(integerValue, 32);
    delay(40);
    }
  }else{
      float voltage, degreesC;
      voltage = analogRead(temperaturePin) * 0.004882814;
      degreesC = ((voltage - 0.5) * 100.0) - 3;
      Serial.println(degreesC);
    
    }


  
  }
  
}
