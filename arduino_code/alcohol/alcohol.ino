int mq3 = A2;
int red = 7;

void setup(){

    Serial.begin(9600);
    pinMode(red,OUTPUT);
}

void loop(){
    int val = analogRead(mq3);
    if(val >=  100) digitalWrite(read,HIGH);
}