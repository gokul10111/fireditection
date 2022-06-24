#include <ESP8266WiFi.h> 
const char* ssid = "vivo 1904"; //replace with your own wifi ssid 
const char* password = "computer"; //replace with your own //wifi ssid password 
const char* host = "54.197.152.96";

int smokeS = A0; // smoke / gas  sensor connected with analog pin A1 of the arduino / mega. 
int data = 0; 


void setup() { 
  Serial.begin(9600);
  
 randomSeed(analogRead(0));
//
 pinMode(smokeS, INPUT); 
  Serial.println("Preparing to send SMS");
  
   
  delay(10); // We start by connecting to a WiFi network Serial.println();
  Serial.println(); 
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
  delay(500);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected"); 
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP()); 
} 
int value = 0; 

void loop() { 

  data = analogRead(smokeS); 
  
  Serial.print("Smoke: "); 
  Serial.println(data); 

  if ( data > 20) // 
    {
    SendMessage();   
    Serial.println("message sent.");
    delay(5000);      
    }
  else {
    SendMessage1();   
    Serial.println("message sent.");
    delay(5000); 
   }
}

void SendMessage()
{
  delay(5000); 
  ++value; 
  Serial.print("connecting to ");
  Serial.println(host); // Use WiFiClient class to create TCP connections
  const int httpPort = 80;
  WiFiClient client;
  
  if (!client.connect(host, httpPort)) 
  {
  Serial.println("connection failed");
  return;
  }
  
  String url = "/message/1";
  
  Serial.print("Requesting URL: ");
  Serial.println(url); // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
}

void SendMessage1()
{
  delay(5000); 
  ++value; 
  Serial.print("connecting to ");
  Serial.println(host); // Use WiFiClient class to create TCP connections
  const int httpPort = 80;
  WiFiClient client;
  
  if (!client.connect(host, httpPort)) 
  {
  Serial.println("connection failed");
  return;
  }
  
  String url = "/message/2";
  
  Serial.print("Requesting URL: ");
  Serial.println(url); // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
}
