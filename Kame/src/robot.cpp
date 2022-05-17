#include <Servo.h>
#include <Arduino.h>
#include <robot.h>

Servo S1;
Servo S2;
Servo S3;
Servo S4;
Servo S5;
Servo S6;
Servo S7;
Servo S8;

void servoInit() {
    S1.attach(5);  //D1
    S2.attach(4);  //D2
    S3.attach(0);  //D3
    S4.attach(2);  //D4
    S5.attach(14); //D5
    S6.attach(12); //D6
    S7.attach(13); //D7
    S8.attach(15); //D8    
}

void start(){
    S1.write(90);
    S2.write(90);
    S3.write(90);
    S4.write(90);
    S5.write(90);
    S6.write(90);
    S7.write(90);
    S8.write(90);
}

void forward(int distance){


}


void backward(int distance){


}

void right(int angle){


}

void left(int angle){


}
void setPos(int pos){
    S1.write(pos);
    S2.write(pos);
    S3.write(pos);
    S4.write(pos);
    S5.write(pos);
    S6.write(pos);
    S7.write(pos);
    S8.write(pos);
}