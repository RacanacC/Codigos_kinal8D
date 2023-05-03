/*
 Fundación Kinal
 Centro Educativo Técnico Laboral Kinal
 Electrónica
 Grado: Quinto
 Sección: A
 Curso: Taller de Electrónica Digital y Reparación de Computadoras I
 Nombre: Luis Alexander Racanac Canahui
 Carné: 2022083
 
*/

#include <OneWire.h>                
#include <DallasTemperature.h>
# include<Wire.h>     
# include<LiquidCrystal_I2C.h>
#define direccion_lcd 0x27
#define filas 2
#define columnas 16   
#define led_Azul 7
#define led_Rojo 5
#define led_Amarillo 3

byte grados[] = {
  B00000,
  B00110,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte ter[] = {
  B00000,
  B00000,
  B00111,
  B01000,
  B10010,
  B01010,
  B00111,
  B00000
};

byte ter2[] = {
  B00000,
  B00000,
  B11111,
  B00000,
  B01010,
  B01010,
  B11111,
  B00000
};

byte ter3[] = {
  B00000,
  B01110,
  B11001,
  B00001,
  B10001,
  B10001,
  B11001,
  B01110
};

byte Ghost[] = {
  B00000,
  B01110,
  B11111,
  B10101,
  B11111,
  B11111,
  B10101,
  B00000
};

byte feli[] = {
  B00000,
  B11011,
  B11011,
  B00000,
  B10001,
  B11111,
  B01110,
  B00000
};

byte troste[] = {
  B00000,
  B11011,
  B11011,
  B00000,
  B01110,
  B11111,
  B10001,
  B00000
};

OneWire ourWire(4);               
DallasTemperature sensors(&ourWire);
LiquidCrystal_I2C lcd_racanac(direccion_lcd, columnas, filas);

int celsius, fahrenheit;

int tempcelsius();
int tempfahrenheit();
void pantalla();

void setup() {
  Serial.begin(9600);   
  sensors.begin();
  lcd_racanac.init();
  lcd_racanac.backlight();
  pinMode(led_Azul, OUTPUT);
  pinMode(led_Rojo, OUTPUT);
  pinMode(led_Amarillo, OUTPUT);
  lcd_racanac.createChar(0, grados);
  lcd_racanac.createChar(1, ter);
  lcd_racanac.createChar(2, ter2);
  lcd_racanac.createChar(3, ter3);
  lcd_racanac.createChar(4, Ghost);
  lcd_racanac.createChar(5, feli);
  lcd_racanac.createChar(6, troste);
  lcd_racanac.home();
  
  lcd_racanac.setCursor(0,0);
  lcd_racanac.print(" Termometro");
  
  lcd_racanac.setCursor(12,0);
  lcd_racanac.write(byte(1));
  
  lcd_racanac.setCursor(13,0);
  lcd_racanac.write(byte(2));
  
  lcd_racanac.setCursor(14,0);
  lcd_racanac.write(byte(3)); 
}

void loop() {  
  pantalla();
}

int tempcelsius(){
  sensors.requestTemperatures();   
  int temp = sensors.getTempCByIndex(0);   
  return temp;
}

int tempfahrenheit(){
  sensors.requestTemperatures();   
  int temp1 = sensors.getTempFByIndex(0); 
  return temp1;
}

void pantalla(){
  celsius = tempcelsius();
  fahrenheit = tempfahrenheit();

  lcd_racanac.setCursor(2,1);
  lcd_racanac.print(celsius);
  lcd_racanac.setCursor(4,1);
  lcd_racanac.setCursor(4,1);
  lcd_racanac.write(byte(0));
  lcd_racanac.setCursor(5,1);
  lcd_racanac.print("C");
  lcd_racanac.setCursor(9,1);
  lcd_racanac.print(fahrenheit);
  lcd_racanac.setCursor(11,1);
  lcd_racanac.write(byte(0));
  lcd_racanac.setCursor(12,1);
  lcd_racanac.print("F");

  if(celsius>=15 && celsius<=30){
    digitalWrite(led_Azul, LOW);
    digitalWrite(led_Amarillo, HIGH);
    digitalWrite(led_Rojo, LOW);
    lcd_racanac.setCursor(15,1);
    lcd_racanac.print(" ");
    lcd_racanac.setCursor(14,1);
    lcd_racanac.write(byte(5));
    delay(400);
    lcd_racanac.setCursor(14,1);
    lcd_racanac.print(" ");
    lcd_racanac.setCursor(15,1);
    lcd_racanac.write(byte(5));
    delay(400);
  }
  
  if(celsius<15){
      digitalWrite(led_Azul, HIGH);
      digitalWrite(led_Amarillo, LOW);
      digitalWrite(led_Rojo, LOW);
       lcd_racanac.setCursor(15,1);
       lcd_racanac.print(" ");
       lcd_racanac.setCursor(14,1);
       lcd_racanac.write(byte(4));
       delay(400);
       lcd_racanac.setCursor(14,1);
       lcd_racanac.print(" ");
       
       lcd_racanac.setCursor(15,1);
       lcd_racanac.write(byte(4));
       delay(400);
    }
    
    if(celsius>30){
        digitalWrite(led_Azul, LOW);
        digitalWrite(led_Amarillo, LOW);
        digitalWrite(led_Rojo, HIGH);
        lcd_racanac.setCursor(15,1);
        lcd_racanac.print(" ");
        lcd_racanac.setCursor(14,1);
        lcd_racanac.write(byte(6));
        delay(400);
        lcd_racanac.setCursor(14,1);
        lcd_racanac.print(" ");
        lcd_racanac.setCursor(15,1);
        lcd_racanac.write(byte(6));
        delay(400);
      }
    
  
}
