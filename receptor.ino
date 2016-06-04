//Hecho con Arduino 1.6.9
#include <VirtualWire.h>
byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message
String readString = String(30);

void setup()
{
    Serial.begin(9600);
    Serial.println("El dispositivo esta listo");
// Initialize the IO and ISR
    vw_setup(2000); // Bits per sec
    vw_rx_start(); // Start the receiver
}

void loop()
{
  if (vw_get_message(message, &messageLength)) // Non-blocking
  {
    Serial.print("Received: ");
    for (int i = 0; i < messageLength; i++)
    {
      Serial.write(message[i]);
      readString += (char)message[i];
    }
    Serial.println();
    //Serial.println(readString);
    int indice = 0;
    //Inicio
    String humedad = "";
    indice = readString.indexOf("hum=");
    if(indice>-1){
      humedad = readString.substring(indice+4);
      indice = humedad.indexOf("&");
      humedad = humedad.substring(0,indice);
      Serial.println(humedad);
    }
    //Fin
    //Inicio
    String temperatura = "";
    indice = readString.indexOf("tem=");
    if(indice>-1){
      temperatura = readString.substring(indice+4);
      indice = temperatura.indexOf("&");
      temperatura = temperatura.substring(0,indice);
      Serial.println(temperatura);
    }
    //Fin
    //Inicio
    String gps_x = "";
    indice = readString.indexOf("gps_x=");
    if(indice>-1){
      gps_x = readString.substring(indice+6);
      indice = gps_x.indexOf("&");
      gps_x = gps_x.substring(0,indice);
      Serial.println(gps_x);
    }
    //Fin
    //Inicio
    String gps_y = "";
    indice = readString.indexOf("gps_y=");
    if(indice>-1){
      gps_y = readString.substring(indice+6);
      //gps_y = gps_y.indexOf("&");
      gps_y = gps_y.substring(0,indice);
      Serial.println(gps_y);
    }
    //Fin
  }
  readString=""; 
}
