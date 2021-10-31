int echo = 3;
int trig = 2;

void setup()
{
  Serial.begin(9600);

  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delay(2);
  digitalWrite(trig, LOW);

  float duration = pulseIn(echo, HIGH);
  float distance = duration * 0.034 / 2;

  Serial.println(distance);
}