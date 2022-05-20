#pragma once
#include <servo.h>

void start();
void forward(int);
void backward(int);
void left(int);
void right(int);
void setAllPos(float, int);
void servoInit();
void jump();
void homeAll(int);

void timeServoMove(Servo, int, float);


