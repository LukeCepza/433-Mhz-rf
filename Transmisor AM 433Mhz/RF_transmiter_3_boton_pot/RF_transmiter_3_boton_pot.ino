#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(2000, 9, 2, 10); 
char code[0];
int i = 0;

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
  String pot =  String(analogRead(A0), DEC);
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
    str += pot;
    Serial.println(str);
    for( i = 0; i <= str.length(); i++){
    }
    //Serial.println(i);
  str.toCharArray(code, i);
    char *msg = code;

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(50);
  }

