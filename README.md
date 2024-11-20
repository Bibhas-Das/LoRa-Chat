<!DOCTYPE html>
<html lang="en">
<body>

<h1>LoRa-Chat</h1>

<p>Wireless communication using a low-power LoRa module operating on a radio frequency band, with a range of up to 15 km.</p>

<h2>Specifications:</h2>
<p>
    <strong>Frequency Used:</strong> 443 MHz<br>
    <strong>Power Supply:</strong> 3-5 V<br>
    <strong>Total Cost:</strong> 550 Indian Rupees (as of today)<br>
    <strong>Project Version:</strong> 0.2v
</p>

<h2>Components Used:</h2>
<ul>
    <li>Esp8266 WiFi Arduino board (2)</li>
    <li>LoRa-02 SX1278 443MHz (2)</li>
    <li>Monopole Antenna (2)</li>
    <li>Small copper wire pieces (22)</li>
    <li>Soldering machine</li>
    <li>Soldering wire</li>
    <li>Arduino IDE</li>
    <li>Code</li>
</ul>

<h2>Memory Used:</h2>
<p>
    Sketch uses 261,284 bytes (25%) of program storage space. Maximum is 1,044,464 bytes.<br>
    Global variables use 45,966 bytes (56%) of dynamic memory, leaving 35,954 bytes for local variables. Maximum is 81,920 bytes.
</p>

<h2>Board Sector:</h2>
<table border="1">
    <tr>
        <th>Parameter</th>
        <th>Value</th>
    </tr>
    <tr>
        <td>First Sector Index</td>
        <td>0</td>
    </tr>
    <tr>
        <td>Total Sector Count</td>
        <td>65</td>
    </tr>
    <tr>
        <td>Head Sector Count</td>
        <td>16</td>
    </tr>
    <tr>
        <td>Adjusted Sector Count</td>
        <td>49</td>
    </tr>
    <tr>
        <td>Adjusted Size</td>
        <td>031000</td>
    </tr>
</table>

<h2>Advantages:</h2>
<ul>
    <li>One-time low investment</li>
    <li>Can build its own network</li>
    <li>Long-distance coverage</li>
    <li>Low cost</li>
    <li>Portable</li>
    <li>User-friendly</li>
    <li>Open source</li>
    <li>Easy to build or set up</li>
    <li>Independent from towers in rural places</li>
</ul>

<h2>Disadvantages:</h2>
<ul>
    <li>Cheap design</li>
    <li>Connectivity issues</li>
    <li>Packet loss in the absence of a receiver</li>
    <li>Low storage (fixed buffer size)</li>
    <li>Cannot handle multiple messages simultaneously</li>
    <li>Damage risk</li>
    <li>Slower than ordinary shell phones (not confirmed)</li>
    <li>Reserved keywords: <code>ACK</code>, <code>SEEN</code>. These cannot be used as they act as commands.</li>
</ul>

<h2>Wire Connections:</h2>
<table border="1">
    <tr>
        <th>ESP8266</th>
        <th>LoRa-02 SX1278</th>
        <th>Battery</th>
    </tr>
    <tr>
        <td>3V</td>
        <td>3.3V</td>
        <td>-</td>
    </tr>
    <tr>
        <td>G</td>
        <td>GND</td>
        <td>-Ve</td>
    </tr>
    <tr>
        <td>D0</td>
        <td>RST</td>
        <td>-</td>
    </tr>
    <tr>
        <td>D1</td>
        <td>DI00</td>
        <td>-</td>
    </tr>
    <tr>
        <td>D2</td>
        <td>DI01</td>
        <td>-</td>
    </tr>
    <tr>
        <td>D5</td>
        <td>SCK</td>
        <td>-</td>
    </tr>
    <tr>
        <td>D6</td>
        <td>MISO</td>
        <td>-</td>
    </tr>
    <tr>
        <td>D7</td>
        <td>MOSI</td>
        <td>-</td>
    </tr>
    <tr>
        <td>D8</td>
        <td>NSS</td>
        <td>-</td>
    </tr>
    <tr>
        <td>VIN</td>
        <td>-</td>
        <td>+Ve</td>
    </tr>
</table>

<h2>How to Use:</h2>
<ol>
    <li>Each module set contains three main components: ESP8266 WiFi module, LoRa module, and a mobile phone or computer with a web browser.</li>
    <li>Power on the ESP8266 module connected to the LoRa module.</li>
    <li>A WiFi SSID will appear, such as <code>LoRa_1234</code>. Here, <code>1234</code> is the module's ID.</li>
    <li>Connect to the WiFi using the provided password.</li>
    <li>Open any web browser and enter <code>192.168.4.1</code> in the URL bar.</li>
    <li>Once the page loads, view messages by clicking the "Refresh" button.</li>
    <li>To send a message, type <code>CONN:[Destination_ID]</code> and click send. Example: <code>CONN:1235</code>.</li>
    <li>Send messages up to 999 characters (configurable). To message another user, enter a new ID using the <code>CONN</code> command.</li>
    <li>Buffer size is limited, so avoid heavy messaging.</li>
    <li>Buffer is cleared when the ESP8266 module is switched off.</li>
</ol>

<h2>Images:</h2>

Esp8266 board
![completemodule](https://github.com/user-attachments/assets/91eae124-e02d-4f30-8faf-24b821504304)

Add espboard's json link in IDE's Preference
![Screenshot from 2024-05-05 00-08-39](https://github.com/user-attachments/assets/9ce0174a-98d9-4a4b-9fd3-c3c9a8a38f6e)

Search Lora Package and install
![Screenshot from 2024-05-05 00-09-32](https://github.com/user-attachments/assets/e798f410-11fa-480c-8027-38a0691e9022)

Then opne IDE and paste the code and connect the borads and upload

After complete uploading

connect 2 devices with 2 esp borad's wifi AP with password(Provided on code)
wifi name(AP name) is your devices ID
then open browser and search on url place "192.168.4.1" to open a chat box page
then to connect write command "CONN:[ID]"  ex: CONN:1205, CONN:1206 to send message this device with this ID like phone call.

![WhatsApp Image 2024-05-05 at 08 32 59_66408723](https://github.com/user-attachments/assets/4dc2a7ef-2182-4028-a4db-a526e92c3e21)

![WhatsApp Image 2024-05-05 at 08 32 59_a8caf248](https://github.com/user-attachments/assets/6c30b995-1df5-4dea-b344-9872e9bb2cba)




<p>Thank you!</p>

<h2>Hashes:</h2>
<ul>
    <li><strong>MD5:</strong> bc0f0587d534f39fa138c0255f33b4c9 <em>LoRaChat.ino</em></li>
    <li><strong>SHA1:</strong> c9cf6797827e5e06791052cac00a4e8e57beb35a <em>LoRaChat.ino</em></li>
    <li><strong>SHA256:</strong> da598e00e511eac93a5b5fea7b1bad909248c9a47ca043fd3e8d23b248b0b8e4 <em>LoRaChat.ino</em></li>
</ul>

</body>
</html>
