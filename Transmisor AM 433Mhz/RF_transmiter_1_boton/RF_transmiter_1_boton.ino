// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver(2000, 9, 2, 10); // ESP8266: do not use pin 11
bool boton = 0;

void setup()
{
  pinMode(3, INPUT);
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
  boton = digitalRead(3);
  if(boton == HIGH){
    char *msg = "Encendido";

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1);
  }
  else{
    char *msg = "Apagado";

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1);
  }
}
