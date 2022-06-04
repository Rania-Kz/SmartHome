#define BLYNK_TEMPLATE_ID "TMPL9jkMnF2U"
#define BLYNK_DEVICE_NAME "dhtBlynk"
#define BLYNK_AUTH_TOKEN "KMYI9y_Ukh3Il9yL3g8IHA5uWxNP4MS3"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
char auth[] = BLYNK_AUTH_TOKEN ;


#define DHTPIN 2  //Digital pin
#define DHTTYPE DHT11 //define card (or DHT11)
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;


void SendSensor (){

  float h = dht.readHumidity(); //read humidity
  float t = dht.readTemperature(); //read temperature Celsius
  Serial.println("temp= ");
    Serial.println(t);
    Serial.println("hum= ");
    Serial.println(h);
    if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
         }
   Blynk.virtualWrite(V8,h);
   Blynk.virtualWrite(V9,t);
         

 
}


//WiFi
const char *ssid = "DESKTOP-RANIA KZ"; //Wifi Name
const char *pass = "123456AZE"; //Wifi password



void setup() {
  //Set software serial baud to 115200
  Serial.begin(115200);
  Blynk.begin(auth,ssid,pass);
  dht.begin();
  timer.setInterval(1000l,SendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
