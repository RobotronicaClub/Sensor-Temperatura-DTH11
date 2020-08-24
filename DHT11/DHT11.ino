/*
  
                                               ROBOTRONICA CLUB
                                                  PROYECTO 1
                                   CONTROL DE TEMPERATURA USANDO SENSOR DHT11

                          Suscribete a nuestro canal y dale Like al video "ROBOTRONICA CLUB"

                              

*/


#include <DHT11.h>                  //Incluimos la librería del sensor DHT11
#include <LiquidCrystal_I2C.h>      //Incluimos la librería del modulo I2C
#include <Wire.h>                   //Librería que usará SDA Y SCL para comunicarse
LiquidCrystal_I2C lcd(0x27,20,4);   //Declaramos el tamaño de la pantalla LCD
int pin=3;                          // pin variable entero y le damos valor de 3     
DHT11 dht11(pin);                   // declaramos el pin 3 digital como entrada

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                                                                                                        //
int ref=31;                         // Ref es la variable entera que define el limite, si la temp sube mas que la referencia se activa el LED,BUZZER y ventilador       //
                                                                                                                                                                        //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
 Serial.begin(9600);                
 pinMode(8,OUTPUT);                 // Pin 8 digital como salida
 lcd.init();                        // Iniciamos el LCD
 lcd.init();
 lcd.backlight();                   // Activamos la luz de fondo del LCD
 lcd.setCursor(1,0);                // Posicion del cursor (1,0)
 lcd.print("*ROBOTRONICA*");        // Escribimos
 lcd.setCursor(6,1);                // Posicion del cursor (6,1)
 lcd.print("*CLUB*");               // Escribimos 
 delay(3000);                       // Declaramos un tiempo de 3 segundos para que se muestre el texto
 lcd.clear();                       // Limpiamos toda la pantalla
}

void loop() {
 int error;                        // Declaramos la variable error como entero
 float temperatura,humedad;        // Declaramos temperatura y humedad como variables enteras con decimales
 delay(100);                       // Delay para controlar la velocidad de cambio de lecturas, Puedes modificarlo a 1 segundo (1000) o el que desees 
 if((error=dht11.read(humedad,temperatura))==0)   // Si y solo si el error en la lectura de humedad y temperatura es igual 0 
 {
 
  lcd.setCursor(0,0);                                   //Poscición del cursor (0,0)
  lcd.print("TEMP:");                                   // Escribimos
  lcd.setCursor(11,0);                                  // Posición del cursor (11,0)
  lcd.print(temperatura,0);                             // Escribimos en la pantalla el valor de temperatura con 0 decimales
  lcd.setCursor(13,0);                                  // Posición del cursor (13,0)
  lcd.print((char)223);                                 // Escribimos el caracter de "º" en la pantalla
  lcd.setCursor(14,0);                                  // Posición del cursor (14,0)
  lcd.print("C");                                       // Escribimos la C de centigrados  
  lcd.setCursor(0,1);                                   // Posición del cursor (0,1)
  lcd.print("HUMEDAD:");                                // Escribimos
  lcd.setCursor(11,1);                                  // Posición del cursor (11,1)
  lcd.print(humedad,0);                                 // Escribimos en la pantalla el valor de humedad con 0 decimales
  lcd.setCursor(13,1);                                  // Posición del cursor (13,1)
  lcd.print("%");                                       // Escribimos

  
  if(temperatura>ref)              // Si y solo si temperatura es mayor que "ref"
  {
    digitalWrite(8,HIGH);                               // Pone en alto "uno" el pin digital 8 del arduino y activa LED,BUZZER y ventilador
    }
    else                                                // Si no excede el valor de "ref"
    {
      digitalWrite(8, LOW);                             // Pone en bajo "cero" el pin digital 8 del arduino y desactiva LED,BUZZER y ventilador
      }  
  }
delay(DHT11_RETRY_DELAY);                               // Es necesario poner este delay para darle tiempo al sensor DHT11 de leer
}
 
 
