/**
  @file    ads7843_eg.ino
  @author  www.elechouse.com
  @brief   example of ELECHOUSE ads7843 library
  
  @section  HISTORY
  
  V1.0 initial version
  
    Copyright (c) 2013 www.elechouse.com  All right reserved.
*/
#include "ads7843.h"
 #include <SPI.h>


//#define DCLK     6
#define CS       8  
//#define DIN      4 
//#define DOUT     3
#define IRQ      10 
#define RST      9

ADS7843 touch(CS, IRQ);
Point p;

void setup(void)
{
  Serial.begin(115200);
  delay (5000);
  touch.begin();
  Serial.println("Starting");
  pinMode(IRQ, INPUT);
  pinMode(RST, OUTPUT);
  digitalWrite (RST,LOW);
  digitalWrite (RST,HIGH);
}

void loop(void)
{
  uint8_t flag;
  int _irq;
  /** getpos */
  delay (500);
  _irq = digitalRead (IRQ);
  Serial.print ("IRQ: ");
  Serial.println (_irq, DEC);
//  if (_irq == 0) {
  p=touch.getpos(&flag) ;
  if(flag){
    /** get position successfully */
    
    /** print the coordinate */
    Serial.print(p.x, DEC);
    Serial.print("   ");
    Serial.print(p.y, DEC);
    Serial.println();
//  }
  }
}
