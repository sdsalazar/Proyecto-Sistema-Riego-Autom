// include the library code:
#include <LiquidCrystal.h>
const int sensorPin= A0;
const int sensorventi = 10;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(sensorventi, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  // Print a message to the LCD.
 // lcd.print("lagrimon");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
 // lcd.print(millis() / 1000);
 int value = analogRead(sensorPin);
  float millivolts = (value / 1023.0) * 5000;
  float celsius = millivolts / 10; 
  lcd.print(celsius);
   lcd.print(" C");
   lcd.begin(16, 2);
   int humedad = analogRead(sensorPin);
    lcd.print(humedad);
    
   if(humedad <= 500)
   {
        digitalWrite(sensorventi, HIGH);
       lcd.print("Apagado");  
      //hacer las acciones necesarias
   }
   if(humedad > 500 and humedad <= 700)
   {
      digitalWrite(sensorventi, HIGH);
       lcd.print("Apagado");  
      //hacer las acciones necesarias
    }
    if(humedad > 700)
    {
      digitalWrite(sensorventi, LOW);
       lcd.print("Encendido");  
      //hacer las acciones necesarias
    }
   
   
  delay(1000);
}

