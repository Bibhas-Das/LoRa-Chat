# **LoRa-Chat**

Wireless communication using a low-power LoRa module operating on a radio frequency band, with a range of up to 15 km.

---

## **Specifications**

* **Frequency Used:** 443 MHz
* **Power Supply:** 3–5 V
* **Total Cost:** ₹550 (as of today)
* **Project Version:** 0.2v

---

## **Components Used**

* Esp8266 WiFi Arduino board (2)
* LoRa-02 SX1278 443MHz (2)
* Monopole Antenna (2)
* Small copper wire pieces (22)
* Soldering machine
* Soldering wire
* Arduino IDE
* Code

---

## **Memory Used**

* Sketch uses 261,284 bytes (25%) of program storage space (Max: 1,044,464 bytes)
* Global variables use 45,966 bytes (56%) of dynamic memory (Remaining: 35,954 bytes of 81,920 bytes)

---

## **Board Sector**

| Parameter             | Value  |
| --------------------- | ------ |
| First Sector Index    | 0      |
| Total Sector Count    | 65     |
| Head Sector Count     | 16     |
| Adjusted Sector Count | 49     |
| Adjusted Size         | 031000 |

---

## **Advantages**

* One-time low investment
* Can build its own network
* Long-distance coverage
* Low cost
* Portable
* User-friendly
* Open source
* Easy to build or set up
* Works without towers (ideal for rural areas)

---

## **Disadvantages**

* Cheap design
* Connectivity issues
* Packet loss without a receiver
* Low storage (fixed buffer size)
* Cannot handle multiple messages at once
* Damage risk
* Slower than regular cell phones (not confirmed)
* Reserved commands: `ACK`, `SEEN` (cannot be used as message content)

---

## **Wire Connections**

| ESP8266 | LoRa-02 SX1278 | Battery |
| ------- | -------------- | ------- |
| 3V      | 3.3V           | -       |
| G       | GND            | -Ve     |
| D0      | RST            | -       |
| D1      | DI00           | -       |
| D2      | DI01           | -       |
| D5      | SCK            | -       |
| D6      | MISO           | -       |
| D7      | MOSI           | -       |
| D8      | NSS            | -       |
| VIN     | -              | +Ve     |

---

## **How to Use**

1. Each module includes: ESP8266, LoRa module, and a phone or computer with a web browser.
2. Power on the ESP8266 with the LoRa module connected.
3. A WiFi SSID will appear (e.g., `LoRa_1234`, where `1234` is the device ID).
4. Connect to this WiFi using the password provided in the code.
5. Open a browser and go to `192.168.4.1`.
6. Click "Refresh" to view incoming messages.
7. To connect and send messages, use the command `CONN:[Destination_ID]`, e.g., `CONN:1235`.
8. You can send messages up to 999 characters (configurable).
9. To message another device, use a new `CONN` command.
10. Buffer size is limited; avoid flooding.
11. Buffer clears when ESP8266 is powered off.

---

## **Images**

**ESP8266 board**  
<p align="center">
  <img src="https://github.com/user-attachments/assets/91eae124-e02d-4f30-8faf-24b821504304" alt="completemodule">
</p>

**Add board JSON URL in Arduino IDE Preferences**  
<p align="center">
  <img src="https://github.com/user-attachments/assets/9ce0174a-98d9-4a4b-9fd3-c3c9a8a38f6e" alt="IDE Preferences">
</p>

**Install LoRa Library**  
<p align="center">
  <img src="https://github.com/user-attachments/assets/e798f410-11fa-480c-8027-38a0691e9022" alt="LoRa install">
</p>

**Upload the code using Arduino IDE**

* Connect two devices to ESP8266 WiFi APs
* SSID is the device ID
* Open browser → enter `192.168.4.1`
* To message, use `CONN:ID` format (e.g., `CONN:1205`)

**Sample Images**  
<p align="center">
  <img src="https://github.com/user-attachments/assets/4dc2a7ef-2182-4028-a4db-a526e92c3e21" alt="WhatsApp Image 1">
</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/6c30b995-1df5-4dea-b344-9872e9bb2cba" alt="WhatsApp Image 2">
</p>

---

## **Hashes (LoRaChat.ino)**

* **MD5:** bc0f0587d534f39fa138c0255f33b4c9
* **SHA1:** c9cf6797827e5e06791052cac00a4e8e57beb35a
* **SHA256:** da598e00e511eac93a5b5fea7b1bad909248c9a47ca043fd3e8d23b248b0b8e4

---

**Thank you!**
