#pragma once
#include <servo.h>

void start();
void forward(int);
void backward(int);
void left(int);
void right(int);
void setPos(float);
void servoInit();

extern Servo S1;
extern Servo S2;
extern Servo S3;
extern Servo S4;
extern Servo S5;
extern Servo S6;
extern Servo S7;
extern Servo S8;

