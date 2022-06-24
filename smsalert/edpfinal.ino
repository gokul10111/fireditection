#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(9, 5); //RX, TX
int smokeS = A0; // smoke / gas  sensor connected with analog pin A1 of the arduino / mega. 
int data = 0; 
String textForSMS;

void setup()
{
   randomSeed(analogRead(0));
   gsmSerial.begin(9600); // Setting the baud rate of GSM Module
   Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
   delay(1000);
   pinMode(smokeS, INPUT); 
   Serial.println("Preparing to send SMS");
   SendMessage();
}

void loop() {

  data = analogRead(smokeS); 
  
  Serial.print("Smoke: "); 
  Serial.println(data); 

  
     if ( data > 50) // 
  {
       textForSMS =  "\nGas Or Smoke Detected";  
        SendMessage();
        Serial.println(textForSMS);
        Serial.println("message sent.");
        delay(5000);
        while(1)
{
  
}
  }
}

void SendMessage()
{
   Serial.println("Setting the GSM in text mode");
   gsmSerial.println("AT+CMGF=1\r");
   delay(2000);
   Serial.println("Sending SMS to the desired phone number!");
   gsmSerial.println("AT+CMGS=\"+917339090935\"\r");
   // Replace x with mobile number
   delay(2000);

   gsmSerial.println("fire detected !!!!");    // SMS Text
   delay(200);
   gsmSerial.println((char)26);               // ASCII code of CTRL+Z
   delay(2000);
}
