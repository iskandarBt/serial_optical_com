#ifndef LASER_RX_H
#define LASER_RX_H
#include <Arduino.h>

int readStartByte();
void readData(int byteNumber);
void flushBuffer();

#endif

//***********DEFINE**************
#define SPEED 30  // time to send 1 bit (in ms)
