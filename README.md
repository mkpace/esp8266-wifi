# esp8266-wifi

This project is an experiment in turning Lights on/off using an ESP8266 WiFi microcontroller which is accessible from an IP address on my local WiFi network. 

This is a quick spike project to test the features of the ESP8266, an experiment using a 120v AC - 5v DC relay, and the genesis of an idea to fully wire all plug-in lamps around the house to be accessible from an internally hosted web page. A more extensive project will be to open a VPN connection to allow the lamps to be accessed from outside the house.

This project is very simple and inexpensive. The items on the BOM are available from Amazon (links).

The ESP8266 is a very cool microcontroller because it is programmable like an Arduino, but has built-in WiFi with a full TCP/IP stack, and is very inexpensive. 

I will post the fritzing diagram along with photos of the project fully assembled shortly, but for now it's just the code for the HTTP server and BOM. I actually disassembled the project to use the parts for another project before I had a chance to take photos of the finished solution ;)

### BOM

+ 1 - [ESP8266 NodeMCU](https://www.amazon.com/ESP8266-microcontroller-NodeMCU-WIFI-CP2102/dp/B071WRD25D/ref=sr_1_5?ie=UTF8&qid=1521067033&sr=8-5&keywords=nodemcu)
+ 1 - [5V 1 Channel relay](https://www.amazon.com/Indicator-Light-Channel-Module-Arduino/dp/B00P7QDJD2/ref=sr_1_5?ie=UTF8&qid=1521067126&sr=8-5&keywords=single+5v+relay)

#### ESP8266 NodeMCU
![ESP8266](/esp8266-nodemcu.png)

#### 120V - 5V Relay
![Relay](/120v-5v-relay.png)
