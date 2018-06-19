#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <IPAddress.h>
#include <WiFiUDP.h>
#include <Servo.h>

Servo servo;



/*---------------*/
// wifi config
/*----------------*/
char* ssid = "r2";
char* password = "qt2016c++";

/*---------------*/
// UDP packet handler
/*----------------*/
IPAddress ipBroadCast;
unsigned int udpRemotePort=45454; // port output data
unsigned int udplocalPort=45455;  // port input data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
WiFiUDP udp;






/*---------------*/
// global variable
/*----------------*/
long randNumber;
unsigned int i = 0 ;
uint8_t pin_led = 16;
const int AnalogIn  = A0;
int readingIn = 0;

void setup()
{


//pinMode(pin_led, OUTPUT);

    //start connecting to wifi....
    WiFi.begin(ssid,password);

    //start serial interface for debuging...
    Serial.begin(115200);

    // wait untill esp8266 connected to wifi...
    while(WiFi.status()!=WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    // debuging ...
    Serial.println("");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP()); // todo: config ip broadcast

    ipBroadCast = WiFi.localIP() ;
    ipBroadCast[3] = 255;
    // set udp port for listen...
    udp.begin(udplocalPort);
    Serial.print("Local port: ");
    Serial.println(udp.localPort());

    servo.attach(D7); //D4

}

void myUdpSend(String msg)
{
    // convert string to char array
    int UDP_PACKET_SIZE = msg.length();
    char udpBuffer[UDP_PACKET_SIZE] ;
    msg.toCharArray(udpBuffer, UDP_PACKET_SIZE) ;

    // send msg broadcast to port destinie
    udp.beginPacket(ipBroadCast, udpRemotePort);
    udp.write(udpBuffer, sizeof(udpBuffer));
    udp.endPacket();
}
void checkRecieved()
{
    int packetSize = udp.parsePacket();

    if(packetSize)
    {
        Serial.println("");
        Serial.print("Received packet of size ");
        Serial.println(packetSize);
        Serial.print("From ");
        IPAddress remote = udp.remoteIP();
        for (int i =0; i < 4; i++)
        {
            Serial.print(remote[i], DEC);
            if (i < 3)
            {
                Serial.print(".");
            }
        }
        Serial.print(", port ");
        Serial.println(udp.remotePort());

        // read the packet into packetBufffer
        udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);

        Serial.println("Contents:");
        for (int i =0; i < packetSize; i++)
            Serial.print(packetBuffer[i]);

        //traitment of packet
        String myString = String(packetBuffer);
        if(myString.indexOf("<servo>") >= 0)
        {
            myString.replace("<servo>","");
            int valueI = myString.toInt();
            Serial.println("valueI "+String(valueI));
            if(valueI >= 0 && valueI <= 360 )
             servo.write(valueI);   // turn the LED on (HIGH is the voltage level)
            else
              myUdpSend("<ERREUR>valueI "+String(valueI));

            myUdpSend("</servo>"+myString);
        }
        for (int i =0; i < packetSize; i++)
            packetBuffer[i]= 0;
        myString = "";

    }
}

int tmp ;
void loop()
{
  //digitalWrite(pin_led,HIGH);
  //delay(1000);
  //digitalWrite(pin_led,LOW);
  //delay(1000);

  // tmp = 0 ; servo.write(tmp); delay(1000); Serial.println(tmp);
  // tmp = 90 ; servo.write(tmp); delay(1000); Serial.println(tmp);
  // tmp = 120 ; servo.write(tmp); delay(1000); Serial.println(tmp);
  // tmp = -90 ; servo.write(tmp); delay(1000); Serial.println(tmp);


  checkRecieved();


}
