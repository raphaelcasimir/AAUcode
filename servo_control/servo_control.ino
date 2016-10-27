// Simple servo_control test tool by Raphaël Casimir
// Control the servo by inputing an angle value inside the go() function as shown in the loop

// Position constants (angles in degree)
#define MID 80 // Neutral position / middle
#define MIN 40 // Min position
#define MAX 120 // Max position

// Time constants
#define PER 1 // (in us) Time between position commands to servo while going from one position to another (servo speed)
#define STOP_TIME 1000 // Sleep time between two movements in ms
#define TIME_BETWEEN_LOOPS 2000 // Time before doing the sequence again in ms

#include <Servo.h>

Servo s1;
int pos=MID;
int i=HIGH;

void setup() {
    pinMode(13, OUTPUT);
    s1.attach(12);
    s1.write(pos);
    digitalWrite(13, LOW);
    delay(1000);

}

void go(int goal) {
    // Another possibility is putting a single while and the "if" in it, to save some lines, but less clear when explaining
    digitalWrite(13, i);
    i=!i;
    if(pos<goal) {
        while(pos<goal) {
            pos++;
            s1.write(pos);
            delayMicroseconds(PER);
        }
    }
    if(pos>goal) {        
        while(pos>goal) {
            pos--;
            s1.write(pos);
            delayMicroseconds(PER);
        }
    }
    if(0==goal) {
                while(pos>80) {
            pos--;
            s1.write(pos);
            delayMicroseconds(PER);
        }
    }
    delay(STOP_TIME);
    digitalWrite(13, i);
}

void loop() {
    go(MIN);
    delay(STOP_TIME);
    
    go(MID);
    delay(STOP_TIME);
    
    go(MAX);
    delay(TIME_BETWEEN_LOOPS);

}
