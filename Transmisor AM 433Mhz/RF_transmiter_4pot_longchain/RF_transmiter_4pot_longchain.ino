#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(2000, 9, 2, 10);
char code[15];
int i;
String pot[4];

void setup() {
 // put your setup code here, to run once:
  Serial.begin(9600);
  if(!driver.init())
    Serial.println("init failed");
}

void loop() {
  // put your main code here, to run repeatedly:
String str = "";
  pot[0] = String(analogRead(A0),DEC);
  pot[1] = String(analogRead(A1),DEC);
  pot[2] = String(analogRead(A2),DEC);
  pot[3] = String(analogRead(A3),DEC);
  
  for(i = 0; i < 4; i++){
    if (pot[i].length() == 4){
      str += pot[i];
    }
    else{
      while(pot[i].length() < 4){
      pot[i] = "0" + pot[i];
      }
      str += pot[i];
    }
  }
  Serial.println(str);
  str.toCharArray(code, 16);
  char *msg = code;

  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(5);
}
