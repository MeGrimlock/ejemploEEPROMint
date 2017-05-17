#include <EEPROM.h>

void setup(){
  Serial.begin(57600);
  Serial.println("EEPROM SAMPLE");
  delay(1000);
}

void loop(){
  int valueMem = 1024;
  if(writeSailCenter(valueMem)==1)
    Serial.println("Write OK : "+String(valueMem));
  
  Serial.println("Reading from EEPROM: "+String(readSailCenter()));

  while(true);
}

int readSailCenter(){
  unsigned char low = EEPROM.read(0);  
  unsigned char high= EEPROM.read(1);      
  
  Serial.println("Reading:");
  Serial.println(high);
  Serial.println(low);
  
  return ((high & 0x7f) << 7) | low;
}

int writeSailCenter(int a){  
  unsigned char high =  ((a >> 7) & 0x7f) | 0x80;
  unsigned char low  = (a & 0x7f);
  
  Serial.println("Storing:");
  Serial.println(high);
  Serial.println(low);
  
  EEPROM.write(0,low);
  EEPROM.write(1,high);
  
  return 1;
}

