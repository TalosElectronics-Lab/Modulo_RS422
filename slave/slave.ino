/*
   Comunicacion entre dos arduino
   slave
   Conexiones
   Y-A, Z-B, A-Y, B-Z.
*/
#include <SoftwareSerial.h>
#include <string.h>
SoftwareSerial rs422(2, 3); // RX, TX

#define led 13

//DEFINCION PROTOCOLO
#define ENCENDER "ENCENDER"
#define APAGAR   "APAGAR"

String protocolo = "";

void setup() {
  rs422.begin(9600);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (rs422.available()) {
    protocolo += char(rs422.read());
    if (protocolo == ENCENDER) {
      digitalWrite(led, HIGH);
      //limpiar protocolo
      protocolo = "";
    }
    if (protocolo == APAGAR) {
      digitalWrite(led, LOW);
      //limpiar protocolo
      protocolo = "";
    }
  }
}
