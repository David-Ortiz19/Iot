#include <BluetoothSerial.h>

int valor;

BluetoothSerial SerialBT;

// LED integrado del ESP32
#define LED 2

void setup() {

  Serial.begin(9600);
  SerialBT.begin("ESP32");

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {

  // Revisamos si llegaron datos por Bluetooth
  while (SerialBT.available()) {

    valor = SerialBT.read();

    // Mostrar el dato recibido en el Monitor Serial
    Serial.write(valor);

    // Si recibe el carácter '1', enciende el LED
    if (valor == '1') {
      digitalWrite(LED, HIGH);
    }
    // Cualquier otro valor numérico apaga el LED
    else if (valor >= '0' && valor <= '9') {
      digitalWrite(LED, LOW);
    }
  }


  // Revisamos si llegaron datos por el puerto serial
  while (Serial.available()) {

    valor = Serial.read();

    // Enviamos el valor al Bluetooth
    SerialBT.write(valor);
  }
}