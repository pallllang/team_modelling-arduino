#include<Servo.h>
Servo ms1;

long pwm_s1 = 0;
long interval_s1 = 15;
int angle_s1 = 0,dir_s1 = 1; 

void servocontrol1_setup(){
  ms1.attach(22);
  ms1.write(0);
}
void servocontrol1_loop(){
  
  unsigned long crmil_s1 = millis();
  if((crmil_s1 - pwm_s1) >= interval_s1){
    pwm_s1 = crmil_s1;
    if(dir_s1 == 1 && angle_s1 <= 180) {ms1.write(angle_s1);angle_s1 ++;}
    else if(dir_s1 == 0 && angle_s1 >= 0){ms1.write(angle_s1);angle_s1 --;}
    else if (angle_s1 > 180 || angle_s1 <0)  dir_s1 = (dir_s1==1?0:1);
  }
}
