# LoRa-Chat
Wireless communication using a low-power LoRa module operating on a radio frequency band, with a range of up to 15 km.

Frequency Used  : 443 MHz<br>
Power supply    : 3-5 v<br>
Total cost      : 550 Indian Rupees(till date)<br>
Project version : 0.2v<br>
<br>
<br>
Components Used : Esp8266 wifi ardino board (2)<br>
                  LoRa-02 SX1278 443MHz     (2)<br>
                  Mono-pole Antena          (2)<br>
                  Small copper wire peices  (22)<br>
                  Solding machine<br>
                  Solding wire<br>
                  Ardino IDE<br>
                  Code<br>
<br>
Memory Used     : Sketch uses 261284 bytes (25%) of program storage space. Maximum is 1044464 bytes.
                  Global variables use 45966 bytes (56%) of dynamic memory, leaving 35954 bytes for local variables. Maximum is 81920 bytes.

Board sector    : first_sector_index: 0
	                total_sector_count: 65
	                head_sector_count: 16
	                adjusted_sector_count: 49
	                adjusted_size: 031000

Advantage       : One time low investment
                  Can build its own nwtwork
                  Long distance covarage
                  Low cost
                  Portable
                  User frendly
                  Open source
                  Easy to build or setup
                  Independent from tower or rular places

Disadvantage    : Cheep Design
                  Connectivity issue
                  Packet loss in absent of receiver
                  Low storage(low fixed biffer size)
                  Can't handel multiple messages simulteniously
                  Damge Risk
                  Slow than orinary shell phones(not sure)
                  Reserve keywords : ACK,SEEN. You can't use those words in single it seems be a command.

Wire connection : Esp8266 | LoRa-02 SX1278 | Battary
                  ----------------------------------
                     3V   |        3.3v         -
                     G    |        GND         -Ve
                     D0   |        RST          -
                     D1   |        DI00         -
                     D2   |        DI01         -
                     D5   |        SCK          -
                     D6   |        MISO         -
                     D7   |        MISI         -
                     D8   |        NSS          -
                     VIN  |         -          +Ve

How to use      : Every set of module has 3 main parts (Esp8266 wifi module, LoRa module,and a mobile phone or computer with web-browser)
                  First power on the Esp8266 module that must be connected with LoRa module.
                  Then One wifi SSID will visible like LoRa_1234, here last 1234 is the ID of this set of module.
                  Connect to the wifi with your mobile or computer using password that is provided already.
                  Open any web-browser and type 192.168.4.1 on URL area and hit enter.
                  Your Page is opend. Now you can see the messages by cliking Refresh button.
                  To send message to other type CONN:[Destinition_ID] and sent. Example CONN:1235
                  Now you are ready to send message to the user whose module's ID is 1235.
                  No you can sent messages upto 999 chracters(Changeble). If you sent message other user enter new ID using CONN command.
                  Buffer size is limited so dont try to heavy messaging.
                  After switch off your Esp8266 module all buffer will vanish.
                  Thank you.
                  




# HASHs
md5    : bc0f0587d534f39fa138c0255f33b4c9				                           LoRaChat.ino
sha1   : c9cf6797827e5e06791052cac00a4e8e57beb35a                          LoRaChat.ino
sha256 : da598e00e511eac93a5b5fea7b1bad909248c9a47ca043fd3e8d23b248b0b8e4  LoRaChat.ino
