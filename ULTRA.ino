#include <Ultrasonic.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define TRIGGER_PIN D2
#define ECHO_PIN D1
char auth[] = "auth pin ";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "wifi ssid";
char pass[] = "wifi password";


BlynkTimer timer;
Ultrasonic ultrasonic(D1, D2);

WidgetLED green(V0);
WidgetLED orange(V1);
WidgetLED red(V2);
WidgetLCD lcd(V3);
WidgetMap myMap(V4);

void setup() {
  Serial.begin (9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  int index = 0;
  float lat = 19.042716;
  float lon = 73.023027;
  myMap.location(index, lat, lon, "value");
  }

void loop() {
  float duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;
  float filled_dist = 42-distance;
  float perc = (filled_dist / 42)*100;
  //Serial.print(filled_dist);
  //Serial.println(" cm");
  Serial.println(perc);
  lcd.clear();
  green.off();
  orange.off();
  red.off();
  Blynk.run();
  


  if(perc >=0 and perc <= 33){
    green.on();
    lcd.print(0,0,"Level of garbage is very Low!");
    delay(500);
    orange.off();
    red.off();
    }
  else if(perc >= 33 and perc <= 66){
    green.off();
    orange.on();
    lcd.print(0,0,"Level of garbage is half-full!");
    delay(500);
    red.off();
  }
  else if(perc >=66 and perc <=100){
    green.off();
    orange.off();
    red.on();
    Blynk.notify("Please clear the garbage");
    
  }
  else{
    green.off();
    orange.off();
    red.off();
  delay(1000);
}
lcd.clear();
green.off();
orange.off();
red.off();
}
