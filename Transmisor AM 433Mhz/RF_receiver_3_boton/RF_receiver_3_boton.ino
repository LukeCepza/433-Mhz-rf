
#include <RH_ASK.h>
#include <SPI.h> 

RH_ASK driver(2000, 2, 9, 10); 

void setup()
{
  pinMode(8,OUTPUT);
    Serial.begin(9600); 
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
  String str = "";
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) 
    { 
  if((char)buf[0] == 'A'){
    digitalWrite(8,HIGH);
  }
  else{
    digitalWrite(8,LOW);
  }
  }
   if((char)buf[1] == 'A'){
    digitalWrite(9,HIGH);
   }
   else{
    digitalWrite(9,LOW);
   }
   if((char)buf[2] == 'A'){
    digitalWrite(10,HIGH);
  }
  else{
    digitalWrite(10,LOW);
}
}
