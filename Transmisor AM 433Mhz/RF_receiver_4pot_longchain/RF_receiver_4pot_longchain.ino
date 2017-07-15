#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(2000, 2, 9, 10);
String pot[3];
int potInt[3];
void setup() {

pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
  Serial.begin(9600);
  if (!driver.init())
        Serial.println("init failed");
}
void loop() {
  
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
       
    if (driver.recv(buf, &buflen)) 
    { 
    int i;
      for(int i = 0; i < 3; i++){
      pot[i] = ""; 
      for(int c = 0 + i*3 ; c < 3 + i*3; c++){ 
      pot[i] += (char)buf[c];
      }
      potInt[i] = pot[i].toInt();
      
Serial.println(pot[0]+pot[1]+pot[2]);
    analogWrite(3,potInt[0]);
    analogWrite(5,potInt[1]);
    analogWrite(6,potInt[2]);
    delay(100);
      }
    

  }
}

