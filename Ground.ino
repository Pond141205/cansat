    #include <SPI.h>
    #include <LoRa.h>
    #include <ESP8266WiFi.h>
    #include <ESP8266WebServer.h>
    #include <SD.h>
    #include "Html_CS.h"

    // LoRa configuration
    #define ss 15
    #define rst 5
    #define dio0 4
    #define BAND 920.0E6

    const int chipSelect = 8;
    const char* ssid = "komou*dezu";
    const char* password = "thepieorange@kuykuy";
    const String expectedPassword = "Stellar";

    String formattedDate, day, hour, timestamp;
    String rssi, loRaMessage, temperature, humidity, pressure, altitude, visible, IR, uvindex, acceleration, readingID, BME_Status, GY1145_Status, MPU6050_Status, Latitude, Longtitude, Corrdinate;

    ESP8266WebServer Server(80);

    String processor(const String& var) {
      if (var == "TEMPERATURE") return temperature;
      if (var == "HUMIDITY") return humidity;
      if (var == "PRESSURE") return pressure;
      if (var == "ALTITUDE") return altitude;
      if (var == "VISIBLE") return visible;
      if (var == "IR") return IR;
      if (var == "UVINDEX") return uvindex;
      if (var == "ACCELERATION") return acceleration;
      if (var == "RSSI") return rssi;
      return String();
    }

    void startLoRa() {
      int counter = 0;
      LoRa.setPins(ss, rst, dio0);
      while (!LoRa.begin(BAND) && counter < 10) {
        Serial.print(".");
        counter++;
        delay(500);
      }  
      if (counter == 10) {
        Serial.println("Starting LoRa failed!");
      } else {
        Serial.println("LoRa started successfully!");
      }
      LoRa.setSpreadingFactor(7);

      // Set signal bandwidth (125 kHz is a good balance)
      LoRa.setSignalBandwidth(125E3);

      // Set coding rate (4/5 is a standard setting)
      LoRa.setCodingRate4(5);

      // Set transmit power (20 dBm to start, increase if needed)
      LoRa.setTxPower(20);
    }

    void connectWIFI() {
      Serial.print("Connecting to ");
      Serial.println(ssid);
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println("");
      Serial.println("WiFi Connected.");
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
    }

    void getLoRaData() {
      Serial.print("LoRa packet received: ");
      while (LoRa.available()) {
        String LoRaData = LoRa.readString();
        Serial.println(LoRaData);

        int posPasswordStart = LoRaData.indexOf('<') + 1;
        int posPasswordEnd = LoRaData.indexOf('>');

        if (posPasswordStart > 0 && posPasswordEnd > posPasswordStart) {
          String receivedPassword = LoRaData.substring(posPasswordStart, posPasswordEnd);
          Serial.println("Received Password: " + receivedPassword);

          if (receivedPassword == expectedPassword) {
            int pos1 = posPasswordEnd + 1;
            int pos2 = LoRaData.indexOf('<', pos1);
            int pos3 = LoRaData.indexOf('&', pos2);
            int pos4 = LoRaData.indexOf('#', pos3);
            int pos5 = LoRaData.indexOf('+', pos4);
            int pos6 = LoRaData.indexOf('=', pos5);
            int pos7 = LoRaData.indexOf('$', pos6);
            int pos8 = LoRaData.indexOf('@', pos7);
            int pos9 = LoRaData.indexOf('*', pos8);
            int pos10 = LoRaData.indexOf('!', pos9);
            int pos11 = LoRaData.indexOf('^', pos10);
            int pos12 = LoRaData.indexOf('%', pos11);
            int pos13 = LoRaData.indexOf('/', pos12);
            int pos14 = LoRaData.indexOf('>', pos13);  

            readingID = LoRaData.substring(pos1, pos2);
            temperature = LoRaData.substring(pos2 + 1, pos3);
            humidity = LoRaData.substring(pos3 + 1, pos4);
            pressure = LoRaData.substring(pos4 + 1, pos5);
            altitude = LoRaData.substring(pos5 + 1, pos6);
            visible = LoRaData.substring(pos6 + 1, pos7);
            IR = LoRaData.substring(pos7 + 1, pos8);
            uvindex = LoRaData.substring(pos8 + 1, pos9);
            acceleration = LoRaData.substring(pos9 + 1, pos10);
            BME_Status = LoRaData.substring(pos10 + 1, pos11);
            GY1145_Status = LoRaData.substring(pos11 + 1, pos12);
            MPU6050_Status = LoRaData.substring(pos12 + 1, pos13);
            Latitude = LoRaData.substring(pos13 + 1, pos14);
            Longtitude = LoRaData.substring(pos14 + 1);
            Corrdinate = String(Latitude+", "+ Longtitude);

            rssi = String(LoRa.packetRssi());

            Serial.print(" with RSSI ");
            Serial.println(rssi);

            Serial.println("ReadingID: " + readingID);
          } else {
            Serial.println("Incorrect password. Discarding the packet.");
          }
        } else {
          Serial.println("Invalid data format received.");
        }
      }
    }

    void webpage() { Server.send(200, "text/html", Html_CS); }
    void Temperature() { Server.send(200, "text/plain", temperature); }
    void Pressure() { Server.send(200, "text/plain", pressure); }
    void Humidity() { Server.send(200, "text/plain", humidity); }
    void Visible() { Server.send(200, "text/plain", visible); }
    void IRval() { Server.send(200, "text/plain", IR); }
    void UVindex() { Server.send(200, "text/plain", uvindex); }
    void Altitude() { Server.send(200, "text/plain", altitude); }
    void Acceleration() { Server.send(200, "text/plain", acceleration); }
    void BME_StatusVal() { Server.send(200, "text/plain", BME_Status); }
    void GY1145_StatusVal() { Server.send(200, "text/plain", GY1145_Status); }
    void MPU6050_StatusVal() { Server.send(200, "text/plain", MPU6050_Status); }
    void CorrdinateVal(){Server.send(200, "text/plane", Corrdinate);}
    void Rssi() { Server.send(200, "text/plain", rssi); }
    void ReadingID() { Server.send(200, "text/plain", readingID); }

    void setup() {
      Serial.begin(115200);
      startLoRa();
      connectWIFI();  

      Server.on("/", webpage);
      Server.on("/readTempVal", Temperature);
      Server.on("/readPressVal", Pressure);
      Server.on("/readHumiVal", Humidity);
      Server.on("/readVisVal", Visible);
      Server.on("/readIRVal", IRval);
      Server.on("/readUVindexVal", UVindex);
      Server.on("/readALTVal", Altitude);
      Server.on("/readAcceVal", Acceleration);
      Server.on("/readBME_Status", BME_StatusVal);  
      Server.on("/readGY1145_Status", GY1145_StatusVal);
      Server.on("/readMPU6050_Status", MPU6050_StatusVal);
      Server.on("/readCorrdinateVal", CorrdinateVal);
      Server.on("/readRSSI", Rssi);
      Server.on("/readReadingIDVal", ReadingID);
      Server.begin();
    }

    void loop() {
      Server.handleClient();
      delay(1);
      int packetSize = LoRa.parsePacket();
      if (packetSize) {
        getLoRaData();
      }
    }