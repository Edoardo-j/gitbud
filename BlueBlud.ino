#include <SoftwareSerial.h>

// Configura i pin per la comunicazione con il modulo Bluetooth
// Pin 10 -> RX di Arduino (collegato al TX del modulo BT)
// Pin 11 -> TX di Arduino (collegato al RX del modulo BT)
SoftwareSerial bluetooth(10, 11);

void setup() {
  // Apre la comunicazione seriale con il PC (Terminale)
  Serial.begin(9600);
  Serial.println("--- Terminale Seriale Pronto ---");
  Serial.println("Scrivi un messaggio e premi invio...");

  // Apre la comunicazione con il modulo Bluetooth
  // Nota: La velocità di default dell'HC-05 in modalità normale è 9600 baud
  bluetooth.begin(9600);
}

void loop() {
  // 1. Legge dal Bluetooth e invia al Monitor Seriale del PC
  if (bluetooth.available()) {
    char dataReceived = bluetooth.read();
    Serial.print(dataReceived);
  }

  // 2. Legge dal Monitor Seriale del PC e invia al Bluetooth
  if (Serial.available()) {
    char dataToSend = Serial.read();
    bluetooth.print(dataToSend);
  }
}