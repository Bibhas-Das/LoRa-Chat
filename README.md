<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LoRa-Chat</title>
    
</head>
<body>

<h1>LoRa-Chat</h1>

<div class="section">
    <p>Wireless communication using a low-power LoRa module operating on a radio frequency band, with a range of up to 15 km.</p>
</div>

<div class="section">
    <div class="section-title">Specifications:</div>
    <p><strong>Frequency Used:</strong> 443 MHz<br>
       <strong>Power Supply:</strong> 3-5 V<br>
       <strong>Total Cost:</strong> 550 Indian Rupees (as of today)<br>
       <strong>Project Version:</strong> 0.2v</p>
</div>

<div class="section">
    <div class="section-title">Components Used:</div>
    <ul class="list">
        <li>Esp8266 WiFi Arduino board (2)</li>
        <li>LoRa-02 SX1278 443MHz (2)</li>
        <li>Monopole Antenna (2)</li>
        <li>Small copper wire pieces (22)</li>
        <li>Soldering machine</li>
        <li>Soldering wire</li>
        <li>Arduino IDE</li>
        <li>Code</li>
    </ul>
</div>

<div class="section">
    <div class="section-title">Memory Used:</div>
    <p>Sketch uses 261,284 bytes (25%) of program storage space. Maximum is 1,044,464 bytes.<br>
       Global variables use 45,966 bytes (56%) of dynamic memory, leaving 35,954 bytes for local variables. Maximum is 81,920 bytes.</p>
</div>

<div class="section">
    <div class="section-title">Board Sector:</div>
    <table class="table">
        <tr><th>Parameter</th><th>Value</th></tr>
        <tr><td>First Sector Index</td><td>0</td></tr>
        <tr><td>Total Sector Count</td><td>65</td></tr>
        <tr><td>Head Sector Count</td><td>16</td></tr>
        <tr><td>Adjusted Sector Count</td><td>49</td></tr>
        <tr><td>Adjusted Size</td><td>031000</td></tr>
    </table>
</div>

<div class="section">
    <div class="section-title">Advantages:</div>
    <ul class="list">
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
</div>

<div class="section">
    <div class="section-title">Disadvantages:</div>
    <ul class="list">
        <li>Cheap design</li>
        <li>Connectivity issues</li>
        <li>Packet loss in the absence of a receiver</li>
        <li>Low storage (fixed buffer size)</li>
        <li>Cannot handle multiple messages simultaneously</li>
        <li>Damage risk</li>
        <li>Slower than ordinary shell phones (not confirmed)</li>
        <li>Reserved keywords: <code>ACK</code>, <code>SEEN</code>. These cannot be used as they act as commands.</li>
    </ul>
</div>

<div class="section">
    <div class="section-title">Wire Connections:</div>
    <table class="table">
        <tr><th>ESP8266</th><th>LoRa-02 SX1278</th><th>Battery</th></tr>
        <tr><td>3V</td><td>3.3V</td><td>-</td></tr>
        <tr><td>G</td><td>GND</td><td>-Ve</td></tr>
        <tr><td>D0</td><td>RST</td><td>-</td></tr>
        <tr><td>D1</td><td>DI00</td><td>-</td></tr>
        <tr><td>D2</td><td>DI01</td><td>-</td></tr>
        <tr><td>D5</td><td>SCK</td><td>-</td></tr>
        <tr><td>D6</td><td>MISO</td><td>-</td></tr>
        <tr><td>D7</td><td>MOSI</td><td>-</td></tr>
        <tr><td>D8</td><td>NSS</td><td>-</td></tr>
        <tr><td>VIN</td><td>-</td><td>+Ve</td></tr>
    </table>
</div>

<div class="section">
    <div class="section-title">How to Use:</div>
    <ol class="list">
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
    <p>Thank you!</p>
</div>

<div class="section">
    <div class="section-title">Hashes:</div>
    <ul class="list">
        <li><strong>MD5:</strong> bc0f0587d534f39fa138c0255f33b4c9 <em>LoRaChat.ino</em></li>
        <li><strong>SHA1:</strong> c9cf6797827e5e06791052cac00a4e8e57beb35a <em>LoRaChat.ino</em></li>
        <li><strong>SHA256:</strong> da598e00e511eac93a5b5fea7b1bad909248c9a47ca043fd3e8d23b248b0b8e4 <em>LoRaChat.ino</em></li>
    </ul>
</div>

</body>
</html>
