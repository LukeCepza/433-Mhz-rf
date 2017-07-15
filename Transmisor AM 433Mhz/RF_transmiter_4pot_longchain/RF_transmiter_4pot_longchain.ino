#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(2000, 9, 2, 10);
char code[11];
int i;
String pot[3];

void setup() {
 // put your setup code here, to run once:
  Serial.begin(9600);
  if(!driver.init())
    Serial.println("init failed");
}

void loop() {
  // put your main code here, to run repeatedly:
String str = "";
  pot[0] = String(map(analogRead(A0),0,1023,0,155),DEC);
  pot[1] = String(map(analogRead(A1),0,1023,0,155),DEC);
  pot[2] = String(map(analogRead(A2),0,1023,0,155),DEC);
  
  for(i = 0; i < 3; i++){
    if (pot[i].length() == 3){
      str += pot[i];
    }
    else{
      while(pot[i].length() < 3){
      pot[i] = "0" + pot[i];
      }
      str += pot[i];
    }
  }
  Serial.println(str);
  str.toCharArray(code, 11);
  char *msg = code;

  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(50);
}
