#include <EEPROM.h>
#include <String.h>

String inputStr;
int idx1, idx2, addr, value;
String errMsg = "Incorrect format. Eg: read 3, write 3 10";

void setup() {
  int addr;
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
      inputStr = Serial.readString();   // Example input strings: read 3, write 3 10
      if (inputStr.substring(0,4) == "read") {
        idx1 = inputStr.indexOf(" ");
        if (idx1 == 4) {
          addr = inputStr.substring(5).toInt();
          Serial.print("Read from EEPROM: ");
          Serial.println(EEPROM.read(addr), DEC);
          
        } else {
                  Serial.println(errMsg);
        }
      } else if (inputStr.substring(0,5) == "write") {
              idx1 = inputStr.indexOf(" ");
              if (idx1 == 5) {
                idx2 = inputStr.indexOf(" ", idx1+1);
                addr = inputStr.substring(idx1+1, idx2).toInt();
                value = inputStr.substring(idx2+1).toInt();
                EEPROM.write(addr, value);
                Serial.println("Write to EEPROM address is completed");
              } else {
                  Serial.println(errMsg);
                }
              } else {
                  Serial.println(errMsg);
              }
  } 
}
