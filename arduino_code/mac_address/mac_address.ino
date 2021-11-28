// NodeMCU MAC 알아보기 위한 소스코드/////////////////////////////////////////
// www.make123.co.kr
// 버미소리

#include <ESP8266WiFi.h>
 
uint8_t MAC_array[6];
char MAC_char[18];
 
void setup() {
    Serial.begin(9600);
    Serial.println();
 
    WiFi.macAddress(MAC_array);
    for (int i = 0; i < sizeof(MAC_array); ++i){
      sprintf(MAC_char,"%s%02x:",MAC_char,MAC_array[i]);
    }
  
    Serial.println(MAC_char);
}
 
void loop() {
  
}
