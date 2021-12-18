#include<Servo.h>
Servo ms2;

long pwm_s2 = 0;
long interval_s2 = 15;
int angle_s2 = 0,dir_s2 = 1; 

void servocontrol2_setup(){
  ms2.attach(24);
  ms2.write(0);
}
void servocontrol2_loop(){
  
  unsigned long crmil_s2 = millis();
  if((crmil_s2 - pwm_s2) >= interval_s2){
    pwm_s2 = crmil_s2;
    if(dir_s2 == 1 && angle_s2 <= 180) {ms2.write(angle_s2);angle_s2 ++;}
    else if(dir_s2 == 0 && angle_s2 >= 0){ms2.write(angle_s2);angle_s2 --;}
    else if (angle_s2 > 180 || angle_s2 <0)  dir_s2 = (dir_s2==1?0:1);
  }
}
