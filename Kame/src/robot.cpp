#include <Servo.h>
#include <Arduino.h>
#include <robot.h>


Servo servo[10]={};

// moves to specific angle with a time in milis
void tsm(Servo servo, int angle, float time){
    for(int x = 0; x < angle; x++){
        servo.write(x);
        delay(time/angle);
    }
}

void servoInit() {
    servo[0].attach(5, 500, 2500);  //D1
    servo[1].attach(4, 500, 2500);  //D2
    servo[2].attach(0, 500, 2500);  //D3
    servo[3].attach(2, 500, 2500);  //D4
    servo[4].attach(14, 500, 2500); //D5
    servo[5].attach(12, 500, 2500); //D6
    servo[6].attach(13, 500, 2500); //D7
    servo[7].attach(15, 500, 2500); //D8  
    
    servo[0].write(30); // 0,1,4,5 are the center body servos
    servo[1].write(50); // 0 being the front left and 1 being the front right
    servo[4].write(50);// 4 being the back left and 5 being the back right
    servo[5].write(30);

    servo[2].write(90); // -> 180 is up
    servo[6].write(50); // -> 0 is up
    servo[3].write(40);// -> 0 is up
    servo[7].write(100); // -> 180 is up

}

void start(){

}

void forward(){
servo[2].write(120); // -> 180 is up
delay(100);
servo[0].write(90);
delay(100);
servo[2].write(90); // -> 180 is up

servo[3].write(10);// -> 0 is up
delay(100);
servo[1].write(0);
delay(100);
servo[1].write(50);



}

void forwardFast(int distance){
    
}


void backward(int distance){


}

void right(int angle){


}

void left(int angle){


}

void homeAll(int time){
    tsm(servo[0], 30, time); // 0,1,4,5 are the center body servos
    tsm(servo[1], 50, time); // 0 being the front left and 1 being the front right
    tsm(servo[4], 50, time);// 4 being the back left and 5 being the back right
    tsm(servo[5], 30, time);


    tsm(servo[2], 90, time); //Figure out direction.
    tsm(servo[3], 90, time); //FIgure out oreintation.
    tsm(servo[6], 90, time);
    tsm(servo[7], 90, time);
}

void setAllPos(float pos, int time){
    for(int i=0; i<8; i++)  {
        tsm(servo[i], pos, time);
    }
}


void jump(){


}


