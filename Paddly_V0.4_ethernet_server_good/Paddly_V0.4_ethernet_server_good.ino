#include <Ethernet.h>
#include <SPI.h>


byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192, 168, 0, 15 };
char server[] = "https://paddly.herokuapp.com";
EthernetClient client;

void setup()
{
  Ethernet.begin(mac, ip);
  Serial.begin(9600);

  delay(1000);

  Serial.println("connecting...");
  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.println("GET /?data=hello%20im%20paddly HTTP/1.0");
    client.println("Host: paddly.herokuapp.com/?data=hi_paddly");
    client.println();
    Serial.println("done");
  } else {
    Serial.println("connection failed");
  }
}

void loop()
{
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    for(;;)
      ;
  }
}

