const int light = A0;
const int tmp = A1;

void setup() {
  Serial.begin(9600);
  pinMode(light,INPUT);
  pinMode(tmp,INPUT);
}

void loop() {
  //밝으면 0에 가깝게, 어두우면 1000에 가깝게
  int lightV = analogRead(light);
  int readValue = analogRead(tmp);
  float voltage =(readValue*5.0)/1024.0;
  float temperature = (voltage-0.5)*100;

  Serial.print("Light : ");
  Serial.println(lightV/4);
  delay(500);
  Serial.print("Temperature : ");
  Serial.println(temperature);
  delay(500);
}
