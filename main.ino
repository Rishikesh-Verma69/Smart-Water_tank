#define BLYNK_TEMPLATE_ID "TMPL3a-abhpmc"
#define BLYNK_TEMPLATE_NAME "Smart Water Tank"
#define BLYNK_AUTH_TOKEN "NRhC_QnxjRKAyMmeTCB27cFEpWCMCDJe"

#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
int distance;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Shubrajit_22's Galaxy A14 5G";
char pasd[] = "kryrfh8yqviasxu";

BlynkTimer timer;

void ultra(){

  digitalWrite(D2, LOW);
  delay(2);
  digitalWrite(D2, HIGH);
  delay(10);
  digitalWrite(D2, LOW);

  int duration = pulseIn(D3, HIGH);
  int distance = (0.034 * duration) / 2;

  Serial.println(distance);
  Blynk.virtualWrite(V0, distance);
  if(distance>40){
    Blynk.logEvent("Alert","tank khali ho gaya bc");
  }
}

void setup(){
  
  pinMode(D2, OUTPUT);
  pinMode(D3, INPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pasd);
  timer.setInterval(100L,ultra);

if (distance<=5){
  Blynk.virtualWrite(V1,HIGH);
  Blynk.virtualWrite(V2,HIGH);
  Blynk.virtualWrite(V3,HIGH);
  digitalWrite(D5,HIGH);
  digitalWrite(D6,HIGH);
  digitalWrite(D7,HIGH);
}
else if (distance>5 && distance<40){
  Blynk.virtualWrite(V1,HIGH);
  Blynk.virtualWrite(V2,HIGH);
  Blynk.virtualWrite(V3,LOW);
  digitalWrite(D5,HIGH);
  digitalWrite(D6,HIGH);
  digitalWrite(D7,LOW);
}
else if (distance>40){
  Blynk.virtualWrite(V1,HIGH);
  Blynk.virtualWrite(V2,LOW);
  Blynk.virtualWrite(V3,LOW);
  digitalWrite(D5,HIGH);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
}
}
void loop(){
  Blynk.run();
  timer.run();
}
