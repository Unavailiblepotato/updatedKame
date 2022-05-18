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

void timeServoMove(Servo servo, int angle, float time){ // moves to specific angle 
    for(int x = 0; x < angle; x++){
        servo.write(x);
        delay(time/angle);
    }
}

void servoInit() {
    S1.attach(5, 500, 2500);  //D1
    S2.attach(4, 500, 2500);  //D2
    S3.attach(0, 500, 2500);  //D3
    S4.attach(2, 500, 2500);  //D4
    S5.attach(14, 500, 2500); //D5
    S6.attach(12, 500, 2500); //D6
    S7.attach(13, 500, 2500); //D7
    S8.attach(15, 500, 2500); //D8  
    S1.write(30);
    S2.write(50);
    S3.write(90);
    S4.write(90);
    S5.write(50);
    S6.write(30);
    S7.write(90);
    S8.write(90);  

    timeServoMove(S5, 180, 500);
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
void setAllPos(int pos){
    S1.write(pos);
    S2.write(pos);
    S3.write(pos);
    S4.write(pos);
    S5.write(pos);
    S6.write(pos);
    S7.write(pos);
    S8.write(pos);
}
void jump(){


}


