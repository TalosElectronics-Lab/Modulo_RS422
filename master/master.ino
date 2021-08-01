/*
   Comunicacion entre dos arduino
   Master
   Conexiones
   Y-A, Z-B, A-Y, B-Z.
*/
#include <SoftwareSerial.h>
SoftwareSerial rs422(2, 3); // RX, TX

#define btn_on 4
#define btn_off 5

//DEFINCION PROTOCOLO
#define ENCENDER "ENCENDER"
#define APAGAR   "APAGAR"

void setup() {
  rs422.begin(9600);
  pinMode(btn_on, INPUT_PULLUP);
  pinMode(btn_off, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(btn_on)) {
    while (!digitalRead(btn_on)) {
      delay(20);
    }
    //Enviar el protocolo
    rs422.print(ENCENDER);
  }
  else if (!digitalRead(btn_off)) {
    while (!digitalRead(btn_off)) {
      delay(20);
    }
    //Enviar el protocolo
    rs422.print(APAGAR);
  }
}
