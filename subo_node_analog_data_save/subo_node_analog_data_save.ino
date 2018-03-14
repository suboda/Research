#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_ADS1015.h>

 Adafruit_ADS1115 ads;
 
const char* ssid     = "BELL4G-8AA7";
const char* password = "02707238FDQ";

const char* host = "192.168.8.101";


#include <SPI.h>
#include <MFRC522.h>



void setup() {
   Wire.begin(D2,D1);
  Serial.begin(115200);
 
  delay(10);

    ads.begin();
    
 SPI.begin();     

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void loop() {

   int16_t adc0, adc1, adc2;

  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  
  Serial.print("Tempreture: "); Serial.println(adc0);
  Serial.print("Light: "); Serial.println(adc1);
  Serial.print("Moisture: "); Serial.println(adc2);
  //Serial.print("water sensor: "); Serial.println(adc3);
  
  Serial.println(" ");

    
// ---------------------------------------
//subo = analogRead(AnalogIn);
//Serial.println(subo);
//------------------------------------------

  
  
  
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/IOT/save.php?";
  url += "Tempreture=";
  url += adc0;
  url += "&Light=";
  url += adc1;
  url += "&Moisture=";
  url += adc2;

  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");

               
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
  delay(10000);
}

