void setup() {
  Serial.begin(115200);

  servocontrol1_setup();
  servocontrol2_setup();
  servocontrol3_setup();
  
//  ms.attach(24);
//  ms.write(0);
  
}

void loop() {
  servocontrol1_loop();
  servocontrol2_loop();
  servocontrol3_loop();
  
  

}
