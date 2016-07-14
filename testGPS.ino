#include <string.h>

void setup() {
  // initialize both serial ports:
  Serial.begin(115200);
  Serial1.begin(38400);
}

String inString="";

void loop() {  
  char inChar='-';
  if (Serial1.available() ) {
    inChar = Serial1.read();
    if (inChar=='\n'){
      char bufferString [100] ;
      char *tmp;
      inString.toCharArray(bufferString, inString.length());
      //First stoken
      tmp = strtok(bufferString, ",");
      Serial.println(tmp);
      stringCompare(String(tmp));
      //Second and up tokens
      while (tmp) {
         tmp = strtok(NULL, ",");
         //Serial.println(tmp);
      }
      inString="";
      delay(10);
    }else{
      inString += inChar;  
    }
  }
  
}

