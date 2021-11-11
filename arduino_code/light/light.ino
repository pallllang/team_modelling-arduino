const int light = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(light, INPUT);
}

void loop()
{
  //밝으면 0에 가깝게, 어두우면 1000에 가깝게
  int lightV = analogRead(light);
  Serial.print("Light : ");
  Serial.println(lightV / 4);
  delay(500);
}
