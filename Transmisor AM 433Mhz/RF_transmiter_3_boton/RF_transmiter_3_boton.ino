#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(2000, 9, 2, 10); 
char code[4];

void setup()
{
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
    Serial.begin(9600); 
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
  bool Bblanco = digitalRead(3);
  bool Brojo = digitalRead(4);
  bool Bazul = digitalRead(5);
//  int pot = analogRead(A0);
  String str = "";
  if(Bblanco == HIGH){
    str += 'A';
    }
  else{
    str += 'B';
    }
  if(Brojo == HIGH){
    str += 'A';
    }
  else{ 
    str += 'B';
    }
  if(Bazul == HIGH){
    str += 'A';
    }
  else{
    str += 'B';
    }
String(
    Serial.println(str);
//    Serial.println(pot);
  str.toCharArray(code, 4);
    char *msg = code;

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1);
  }

