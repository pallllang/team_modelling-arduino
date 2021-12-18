#include<Servo.h>
Servo ms3;

long pwm_s3 = 0;
long interval_s3 = 15;
int angle_s3 = 0,dir_s3 = 1; 

void servocontrol3_setup(){
  ms3.attach(26);
  ms3.write(0);
}
void servocontrol3_loop(){
  
  unsigned long crmil_s3 = millis();
  if((crmil_s3 - pwm_s3) >= interval_s3){
    pwm_s3 = crmil_s3;
    if(dir_s3 == 1 && angle_s3 <= 180) {ms3.write(angle_s3);angle_s3 ++;}
    else if(dir_s3 == 0 && angle_s3 >= 0){ms3.write(angle_s3);angle_s3 --;}
    else if (angle_s3 > 180 || angle_s3 <0)  dir_s3 = (dir_s3==1?0:1);
  }
}
