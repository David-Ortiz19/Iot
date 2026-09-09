#include <WiFi.h>

#define SSID "Prueba_ESP"
#define PSWD "12345678"

void InitWiFi();	// Se declara la función que inicializa el Wi-Fi del ESP32.

void setup() {

  Serial.begin(9600);
  InitWiFi();		// Se llama la función del Wi-Fi

}

void loop() {
  // Está vacío ya que solo nos queremos conectar a una red Wi-Fi
}

void InitWiFi(){
  WiFi.mode(WIFI_STA);                      // Estación: cuando nos vamos a conectar a una red. Se configura por defecto.
  //WiFi.mode(WIFI_AP);                     // Punto de Acceso: cuando vamos a generar una red para que otros dispositivos se conecten.
  //WiFi.mode(WIFI_MODE_APSTA);             // Ambos.
  WiFi.begin(SSID, PSWD);                   // Inicializamos el WiFi con nuestras credenciales.
  Serial.print("Conectando a red ");
  Serial.print(SSID);

  while(WiFi.status() != WL_CONNECTED){     // Se queda en este bucle hasta que el estado del WiFi sea diferente a desconectado.
    Serial.print(".");
    delay(100);
  }
  delay(50);
  if(WiFi.status() == WL_CONNECTED){        // Si el estado del WiFi es conectado entra al If.
    Serial.println("");
    Serial.println("");
    Serial.println("Conexión WiFi exitosa!!!");
    Serial.println("");
    delay(50);
    Serial.print("Tu IP es: ");
    Serial.println(WiFi.localIP());
  }else{
    Serial.println("¡Fallo en conexión a internet!");
  }
}