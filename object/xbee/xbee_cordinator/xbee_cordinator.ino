#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial xbee(2, 3); 
Servo sv_crd;

//Receive
//const int tr = 8;//초음파
//const int ec = 9;
int dir_crd = 1;
int angle_crd = 0;

//서보
long pwm_sv_crd = 0;//회전 초기값
long interval_crd = 15;//회전 시간 간격
//초음파
long pwm_uw_crd = 0;//회전 초기값
long interval_uw = 2;//회전 시간 간격
 
void setup() {
  
  Serial.begin(9600);
  xbee.begin(9600); 

  
  sv_crd.attach(4);
  sv_crd.write(0);
}
void loop() {
//if(xbee.available()){
//  char data = xbee.read();
//  if(data == 'A') 
//    Serial.println("Zigbee1 test OK!"); 
//   if(data == 'B') 
//    Serial.println("Zigbee2 test OK!"); 
//  }
  unsigned long millis_cnt_angle = millis();
  if((millis_cnt_angle - pwm_sv_crd) >= interval_crd){
  pwm_sv_crd = millis_cnt_angle;
  if(dir_crd == 1 && angle_crd <= 180) {sv_crd.write(angle_crd);angle_crd ++;}
  else if(dir_crd == 0 && angle_crd >= 0){sv_crd.write(angle_crd);angle_crd --;}
  else if (angle_crd > 180 || angle_crd <0)  dir_crd = (dir_crd==1?0:1);
  
  }

  unsigned long millis_cnt_uw = millis();
  digitalWrite(trig, HIGH);
//   delay(2);
  digitalWrite(trig, LOW);

  float duration = pulseIn(echo, HIGH);
  float distance = duration * 0.034 / 2;

  Serial.println(distance);
  if(millis_cnt_uw - pwm_uw_crd >= interval_uw){

      pwm_uw_crd = millis_cnt_uw;
  }
  
  
  
}


//Z출처: https://creamp.tistory.com/16 [CreAmp]r