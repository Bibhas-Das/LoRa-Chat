/*
Project Name    : LoRa Chatting
Programmer Name : Bibhas Das
Email Address   : bibhasdas1205@gmail.com
Github Page     : https://github.com/Bibhas1205

Starting Date   : 22-April-2024
Next modified   : 24-May-2024
Next modified   : 29-May-2024
Next modified   : 1-May-2024
Next modified   : 3-May-2024
Last modified   : 4-May-2024

Frequency Used  : 443 MHz
Power supply    : 3-5 v
Total cost      : 550 Indian Rupees(till date)
Project version : 0.2v
Deciption       : A Long distance Radio base text communication network (LDRTCN)

Components Used : Esp8266 wifi ardino board (2)
                  LoRa-02 SX1278 443MHz     (2)
                  Mono-pole Antena          (2)
                  Small copper wire peices  (22)

                  Solding machine
                  Solding wire
                  Ardino IDE
                  Code

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
*/


#include <ESP8266WiFi.h> //external libraries
#include <ESP8266WebServer.h> //external libraries
#include <LoRa.h> //external libraries

// LoRa pins
#define SS 15
#define RST 16
#define DIO0 2
#define LED_PIN D4 //inbuild esp board led


// LoRa keys
String MYID = "1205"; //It will constant ID initialy 4 digits, That will be diffrent while uploading diffrent device
String DESTINITIONID="0000";
const short int MAX_MESSAGE_DIGITS=3;

// LoRa frequency
const int FREQUENCY = 433000000;

// WiFi configuration
const char* ssid = "LoRa_1205";// It should be change while upload on diffrent device
const char* password = "12345678";

short int ReceiveStatus=0;//variable that indicate tranmited message is received by receiver or not. 0 means not received.

// Received messages buffer
const int MAX_MESSAGES = 16;
//String receivedMessages[MAX_MESSAGES];
int messageCount = 0;

typedef struct MESSAGE{
  String sou;
  String des;
  String msg;
  int seen =0;
}Message;

Message MSG[MAX_MESSAGES];

// HTML webpage
String html = "<!DOCTYPE html>\
                  <html>\
                  <head>\
                    <meta name='viewport' content='width=device-width, initial-scale=1.0'>\
                    <style>\
                        body {\
                            font-family: Arial, sans-serif;\
                            background-color: #f2f2f2;\
                            margin: 0;\
                            padding: 0;\
                            display: flex;\
                            justify-content: center;\
                            align-items: center;\
                            height: 100vh;\
                        }\
                        .chat-container {\
                            width: 90%;\
                            background-color: #fff;\
                            border-radius: 10px;\
                            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);\
                            overflow: hidden;\
                        }\
                        .chat-messages {\
                            padding: 20px;\
                            height: 400px;\
                            overflow-y: auto;\
                        }\
                        .message {\
                            background-color: #e0f2f1;\
                            border-radius: 5px;\
                            padding: 10px;\
                            margin-bottom: 10px;\
                        }\
                        .message .sender {\
                            font-weight: bold;\
                            color: #01579b;\
                        }\
                        .message .content {\
                            margin-top: 5px;\
                        }\
                        .chat-input {\
                            padding: 10px;\
                            border-top: 1px solid #ccc;\
                            display: flex;\
                            align-items: center;\
                        }\
                        .chat-input input[type='text'] {\
                            flex: 1;\
                            padding: 8px;\
                            font-size: 16px;\
                            border: none;\
                            border-radius: 5px;\
                            margin-right: 10px;\
                        }\
                        .chat-input input[type='submit'] {\
                            background-color: #4caf50;\
                            color: white;\
                            border: none;\
                            padding: 10px 10px;\
                            text-decoration: none;\
                            font-size: 16px;\
                            cursor: pointer;\
                            border-radius: 5px;\
                        }\
                        .chat-input input[type='submit']:hover {\
                            background-color: #45a049;\
                        }\
                        .chat-heading {\
                            background-color: #1976d2;\
                            color: white;\
                            padding: 10px;\
                            text-align: center;\
                            font-size: 24px;\
                            border-top-left-radius: 10px;\
                            border-top-right-radius: 10px;\
                        }\
                        .refresh-button {\
                            background-color: #1976d2;\
                            color: white;\
                            border: none;\
                            padding: 10px 20px;\
                            text-decoration: none;\
                            font-size: 16px;\
                            cursor: pointer;\
                            border-radius: 5px;\
                            margin-top: 10px;\
                            margin-left: 10px;\
                        }\
                        .refresh-button:hover {\
                            background-color: #1565c0;\
                        }\
                    </style>\
                  </head>\
                  <body>\
                      <div class='chat-container'>\
                          <div class='chat-heading'>LoRa Chat</div>\
                          <div class='chat-messages' id='receiver'></div>\
                          <form id='messageForm' class='chat-input'>\
                              <input type='text' name='message' placeholder='Type your message here'>\
                              <input type='submit' value='Send'>\
                          </form>\
                          <button class='refresh-button' onclick='refreshMessages()'>Refresh</button>\
                      </div>\
                      <script>\
                          function refreshMessages() {\
                              var xhttp = new XMLHttpRequest();\
                              xhttp.onreadystatechange = function() {\
                                  if (this.readyState == 4 && this.status == 200) {\
                                      document.getElementById('receiver').innerHTML = this.responseText;\
                                      var receiverDiv = document.getElementById('receiver');\
                                      receiverDiv.scrollTop = receiverDiv.scrollHeight;\
                                  }\
                              };\
                              xhttp.open('GET', '/receive', true);\
                              xhttp.send();\
                          }\
                          function sendMessage(event) {\
                              event.preventDefault();\
                              var form = document.getElementById('messageForm');\
                              var formData = new FormData(form);\
                              var xhttp = new XMLHttpRequest();\
                              xhttp.onreadystatechange = function() {\
                                  if (this.readyState == 4 && this.status == 200) {\
                                      refreshMessages();\
                                      form.reset();\
                                  }\
                              };\
                              xhttp.open('POST', '/send', true);\
                              xhttp.send(formData);\
                          }\
                          document.getElementById('messageForm').addEventListener('submit', sendMessage);\
                          refreshMessages();\
                      </script>\
                  </body>\
                  </html>";


// Web server
ESP8266WebServer server(80);


String Encryption(String msg) 
{
    for (int i = 0; i < msg.length(); ++i)
        msg[i] = msg[i] ^ 125;
    return msg; // Return the modified string
}

String Decryption(String msg) 
{
    for (int i = 0; i < msg.length(); ++i)
        msg[i] = msg[i] ^ 125;
    return msg; // Return the modified string
}

void setFrequency() 
{
    if (!LoRa.begin(FREQUENCY)) 
    {
        Serial.println("Starting LoRa failed!");
        while (1); // Hang here on failure
    }
}

//Message Transmit via LoRa module on selected frequency
int transmitSignal(String sourceID, String destinationID, String message) 
{
    short int status=0;
    if(!destinationID.toInt())
    {
      Serial.println("Destinition ID is not set. Please type CONN:[DESTINITION_ID]");
      return status;
    }

    // Calculate length of encrypted message
    int len =message.length(); // 0 -> 999 --> [highest capacity of an integer];

    String length = String(len);//'0' -> '999' -> [string of highest value of a integer]
    
    if (length.length()>MAX_MESSAGE_DIGITS)
      {
        Serial.println("Message lenngth is out-of-limit");
        return status;
      }

    while (length.length() < MAX_MESSAGE_DIGITS) 
    {
        length = "0" + length; // Pad with zeros to make it three digits
    }

    // Construct full message template
    //Length 3 digits
    String fullMessage = Encryption(sourceID + destinationID + length + message);

    Serial.println("{SenderID : '"+sourceID+"', ReceiverID : '"+destinationID+"', Frequency : '"+String(FREQUENCY)+"Hz', Message : '"+message+"', MessageLength : '"+length+"', EncryptedMessage : '"+fullMessage+"'}");
    // Transmit message
    LoRa.beginPacket();
    LoRa.print(fullMessage);
    LoRa.endPacket();

    return 1;
}

//get message specific part by diffrent positions 
// 0:SourceKey
// 1:DestinitionKey
// 2:Length  => 3 digit [1-999]
// 3:DecrypedMessage
String getMessagePart(String message,int pos)
{
    int size=MYID.length();
    String MSG[size];

    for(int i=0;i<message.length();i++)
    {
        if(i<size)
          MSG[0]+=message[i];
        else if(i<size*2)
          MSG[1]+=message[i];
        else if(i<(size*2)+MAX_MESSAGE_DIGITS)
          MSG[2]+=message[i];
        else
          MSG[3]+=message[i];
    }

    return MSG[pos];
}


//Function to check if a string is present or not in a String list
//1 for not present, and 0 means present or not unique
int CheckUnique(String IDS[],String ID,int top)
{
    for(short int i=0;i<top;i++)
    {
        if(IDS[i].equals(ID))
        return 0;
    }
    return 1;
}

void handleReceive() 
{
    // Check for incoming LoRa messages
   int packetSize = LoRa.parsePacket();
    if (packetSize) 
    {
        while (LoRa.available()) 
        {
            String received = LoRa.readString();
            Serial.println("A message received : "+received);//encrypted
  
            if (received.length() > ((MYID.length())*2)+MAX_MESSAGE_DIGITS) //It ensure that no empty message is recived 
            {
                received=Decryption(received);//Decryption message
                Serial.println("After decrypt the message : "+received);
                Serial.println("A message is received. Now I am cheking this message is mine or not...");

                if(MYID.equals(getMessagePart(received,1)))//confirm that this message is for mine by myID and destinitionID
                {
                    Serial.println("Yes this message is for mine");
                    ////////////
                    if(getMessagePart(received,2).toInt()==getMessagePart(received,3).length()) //Checks for no chracter loss of actual data message
                    {
                        Serial.println("{Response : '" + received+"'}");

                        if(getMessagePart(received,3).equals("SEEN"))
                        {
                            String sendr=getMessagePart(received,0);
                           
                            for(short int i=0;i<messageCount;i++)
                            {
                               if(MSG[i].des.equals(sendr))
                               {
                                  MSG[i].seen=1;
                               }
                            }

                            continue;
                        }

                        // Add the received message to the buffer
                        if (messageCount < MAX_MESSAGES) 
                        {
                            MSG[messageCount].sou=getMessagePart(received,0);
                            MSG[messageCount].des=getMessagePart(received,1);
                            MSG[messageCount++].msg=getMessagePart(received,3);
                        }
                        else 
                        {
                            // Buffer is full, overwrite the oldest message
                            for (int i = 0; i < MAX_MESSAGES - 1; ++i) 
                                MSG[i]=MSG[i+1];

                            MSG[MAX_MESSAGES - 1].sou=getMessagePart(received,0);
                            MSG[MAX_MESSAGES - 1].des=getMessagePart(received,1);
                            MSG[MAX_MESSAGES - 1].msg=getMessagePart(received,3);
                        }

                        // Turn on LED to indicate message received
                        digitalWrite(LED_PIN, LOW);
                        Serial.println("Message received");
                        //delay(200);
                        //Acknowledgement Sending area...
                        if(transmitSignal(MYID,getMessagePart(received,0),"ACK"))//If any trouble occured during transmit the message
                          Serial.println("Acknowledgement is sent successfully");
                    }
                    else  //When your actual message will corroped
                    {
                        Serial.println("Your message is corroped please wait for receive again");
                    }
                }
            }
        }
      }
}

void setup() 
{
    // Setup LED pin
    pinMode(LED_PIN, OUTPUT);

    Serial.begin(9600);

    // Initialize LoRa
    LoRa.setPins(SS, RST, DIO0);
    setFrequency();

    // Setup WiFi access point
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);

    // Setup routes
    server.on("/", HTTP_GET, []() {
      server.send(200, "text/html", html);
      digitalWrite(LED_PIN, HIGH);
    });

    server.on("/send", HTTP_POST, []() {

      String message = server.arg("message");

      //commmand to set destinition ID : CONN:1234 [SEND]
      if(message.length()==5+(MYID.length()) && message[0]=='C'  && message[1]=='O' && message[2]=='N' && message[3]=='N' && message[4]==':')
      {
          for(short int i=5;i<5+(MYID.length());i++)
              DESTINITIONID[i-5]=message[i];

          server.send(200, "text/plain", "Destiontion ID set successfully");
          Serial.println("Destionition ID ("+DESTINITIONID+") set successfull");
      }
      else
      {
          ReceiveStatus=0;

          if(!transmitSignal(MYID, DESTINITIONID, message))//If any trouble occured during transmit the message
            return;


          Serial.println("Waiting for 100 miliseconds for ACK of sending message");
          //Waiting for acknowledgement
          unsigned long startTime = millis(); // Get the current time

          //delay(200)

          // Loop until 100 milliseconds have passed
          while (millis() - startTime < 400)
          {
              ///code to run 100 ms
              // Check for incoming LoRa messages
              int packetSize = LoRa.parsePacket();
              if (packetSize) 
              {
                  while (LoRa.available())
                  {
                      String received = LoRa.readString();
                      Serial.println("An unknown ACK is received : "+received);//encrypted
  
                      if (received.length() > ((MYID.length())*2)+MAX_MESSAGE_DIGITS) //It ensure that no empty message is recived 
                      {
                          received=Decryption(received);//Decryption message
                          Serial.println("A message is received. Now I am cheking this message is my ACK or not...");

                          if(MYID.equals(getMessagePart(received,1)))//confirm that this message is for mine by myID and destinitionID
                          {
                              Serial.println("Yes this ACK is for mine");
                              
                              if(getMessagePart(received,2).toInt()==getMessagePart(received,3).length()) //Checks for no chracter loss of actual data message
                              {
                                  received=getMessagePart(received,3);//ACK message
                                  if(received.equals("ACK"))
                                  {
                                      Serial.println("ACK is received");
                                      ReceiveStatus=1;
                                  }
                              }
                            else
                            {
                               Serial.println("One message is received but It is not sure that it is a ACK");
                            }
                          }
                      }
                  }
              }  
          }

          if(!ReceiveStatus) //If ACK is not received Re transmit again
          {
              Serial.println("ACK is not received");
              return;
          }

          server.send(200, "text/plain", "Message sent successfully");
          Serial.println("Trying to store sended message to buffer");

          // Add the received message to the buffer
          if (messageCount < MAX_MESSAGES) 
          {
              MSG[messageCount].sou=MYID;
              MSG[messageCount].des=DESTINITIONID;
              MSG[messageCount++].msg=message;
          }
          else 
          {
              // Buffer is full, overwrite the oldest message
              for (int i = 0; i < MAX_MESSAGES - 1; ++i) 
                  MSG[i]=MSG[i+1];

              MSG[MAX_MESSAGES - 1].sou=MYID;
              MSG[MAX_MESSAGES - 1].des=DESTINITIONID;
              MSG[MAX_MESSAGES - 1].msg=message;
          }
        
          Serial.println("Sended message is also stored into buffer");
      }
    });

    server.on("/receive", HTTP_GET, []() {
      String response = "";

      String IDS[MAX_MESSAGES];
      short int j=0;

      for (short int i = 0; i < messageCount; ++i) 
      {
          if(MSG[i].sou.equals(MYID))
          {  
             if(MSG[i].seen==0)
                response+="You -> " + MSG[i].sou +" : "+ MSG[i].msg + "<br>";
             else
                response+="You -> " + MSG[i].sou +" : "+ MSG[i].msg + "<span style='float:right;color:lightblue;'>Seen</span> <br>";
          }
          else if(MSG[i].des.equals(MYID))
          {
              response+=MSG[i].sou + " -> You : " + MSG[i].msg + "<br>";
              ////Unique cheking function
              if(CheckUnique(IDS,MSG[i].sou,j))//It chesks if sources is presnt or not in the IDS String list. if source is Unique it returns 1
              {
                IDS[j]=MSG[i].sou;
                j++;
                if(transmitSignal(MYID,MSG[i].sou,"SEEN"))//If any trouble occured during transmit the message
                    Serial.println("Acknowledgement of Seen is send successfully");
              }
          }
      }

      server.send(200, "text/plain", response);
      digitalWrite(LED_PIN, HIGH);
    });

    server.begin();
}

void loop() 
{
  server.handleClient();
  handleReceive();
}
