#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#define trig 5    // Trig   //NodeMCU D1 : GPIO5
#define echo 4    // Echo   //NodeMCU D2 : GPIO4
#define magnet 14    // magnet   //NodeMCU D5 : GPIO14

int tot_person = 0;
int is_door=0;

/*Put your SSID & Password*/
const char* ssid = "pallang_iptime";  // Enter SSID here
const char* password = "arduinoweb";  //Enter Password here

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode(trig, OUTPUT);    // trig 와 연결된 핀(D1)을 출력핀으로 사용
  pinMode(echo, INPUT);     // echo 와 연결된 핀(D2)을 입력핀으로 사용
  pinMode(magnet,INPUT);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.mode(WIFI_STA);// ------------------------
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());


  server.begin();
  Serial.println("HTTP server started");
}
void loop() {

  WiFiClient client = server.available();
 client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println("Refresh: 1");  // 자동으로 웹페이지 새로고침 (1초 설정)
  client.println();
  int distance, measure;
   // 트리거 핀으로 10us 동안 펄스 출력
   digitalWrite(trig, LOW);   // Trig 핀 강제 Low 상태 셋팅
   delayMicroseconds(2);      // 2us 동안 Low 상태 유지
   
   digitalWrite(trig, HIGH);  // High 상태로 셋팅
   delayMicroseconds(10);     // 10us 동안 High 상태 유지
   digitalWrite(trig, LOW);   // Low 상태로 셋팅

 
   measure = pulseIn(echo, HIGH);  // pulseIn은 지정된 포트에서 펄스를 읽음 (High / Low)
   distance = measure / 58;
   
   delay(1000);
   
   Serial.print("distance: ");
   Serial.print(distance);
   Serial.println("cm"); 

   int person_num = Function_Ultra(trig,echo);
  if(person_num == 1){
    tot_person ++;
    Serial.print("Total Person : ");
    Serial.println(tot_person);
  }
   
 while(client.available()) {
    client.read();
  }
  
  client.print("<!DOCTYPE HTML>");
  client.print("<html>");
  client.print("<head>"); 
     client.println("<style>");
   client.println("body {");
   client.println("background-color: #25979A;");
   client.println("}");
   client.println("p {");
   client.println("color:black;");
   client.println("font-size:250%;");
   client.println("}");
    client.println("</style>");  
  client.print("<meta&nbsp;charset=\"UTF-8\">");
  client.print("<title>Smart Room - Jigi</title>");
  client.print("</head>");
  client.print("<body>");
  client.print("<h2>Pallang Smart Room Webpage</h2>");
  client.print("<h2>Distance: </h2>");
  client.print("<div id='dis'>");
  client.print(distance);
  client.print("</div>");
  
  client.print("<h2>People Num: </h2>");
  client.print("<div id='per_n'>");
  client.print(tot_person);
  client.print("</div>");
  
  if(digitalRead(magnet)== LOW){
    Serial.println("DOOR CLOSE");
    is_door = 0;
    delay(1000);
  }else{
    Serial.println("DOOR OPEN");
    is_door = 1;
    delay(1000);
  }
  delay(500);

  client.print("<div id='is_door'>");
  if(is_door == 0){
    client.print("<h2>Door Close</h2>");

  }else{
    client.print("<h2>Door Open</h2>");
  }
  client.print("</div>");
  client.print("</body>");
  client.print("</html>");
 
  Serial.println("클라이언트 연결 해제");

}


int Function_Ultra(int tr,int ec){

  int person_num = 0;
  digitalWrite(tr,LOW);
  delayMicroseconds(2);
  
  digitalWrite(tr,HIGH);
  
  delayMicroseconds(10);
  digitalWrite(tr,LOW);
  long uncalculation = pulseIn(ec,HIGH);
  long result = (uncalculation/2)/29.1;

  delay(1000);

  if(result < 65){
     return 1;
//   delay(3000);
  } else return 0;
  //  Serial.print(result);
//  Serial.println( "cm");
//
//  bts.print(result);
//  bts.println(" cm");

//  delay(1000);
  }
