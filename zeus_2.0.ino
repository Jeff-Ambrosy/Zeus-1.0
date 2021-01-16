#include <SPI.h>
#include <LoRa.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(1, 0); //RX,TX
String Data; //initialise a string to hold my message
String lora_incoming="";
void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Zeus 1.0 is Operational");
  if (!LoRa.begin(433E6)) 
  {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() 
{
  int j;
 if (mySerial.available())
{
   Data= (Serial.read());
   // send packet
   LoRa.beginPacket();
   LoRa.print(Data);
   LoRa.endPacket();
}
else
{
  int packetSize = LoRa.parsePacket();
  if (packetSize)
  { int a=LoRa.available();
    // read packet
    while (a>=0) 
          {
           lora_incoming = LoRa.read();
           Serial.print(lora_incoming);
           a--;
          }}}}
      
      
