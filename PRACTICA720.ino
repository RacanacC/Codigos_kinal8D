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

# include <Wire.h>
# include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define led_azul 5
#define led_verde 6
#define led_rojo 7
#define puerta 10
#define bomb1 9
#define bomb2 12
#define BUZZER 8
#define BOMBILLA1 14
#define BOMBILLA2 15
#define Cantidad_Leds 7
#define pin_Led 17
#define pin_servo 16
const int pinradar = 11;
int estado1 = 0;
int estado2 = 0;
int estado3 = 0;
int d = 294;
int f = 349;
int a = 440;
int c = 523;

enum colores
{
  rojo,
  verde
};

byte presencia[] = {
  B01110,
  B11111,
  B01110,
  B11111,
  B11111,
  B11111,
  B01010,
  B11111
};

byte presencia2[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};

byte luminaria[] = {
  B00000,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B01110,
  B00000
};

byte luminaria2[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B01110,
  B00000
};

byte door[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11101,
  B11111,
  B11111,
  B11111
};

byte door2[] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};

byte hot[] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B01110,
  B11111,
  B10001,
  B00000
};

byte normal[] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B11111,
  B01110,
  B00000
};

byte ice[] = {
  B00000,
  B01010,
  B01010,
  B01010,
  B00000,
  B01110,
  B01110,
  B00000
};

void salidas();
void entradas();
void interfaz();
void animaciones();
void sensor_temp();
void animacion_temp();
void mecanismo_puerta();
void mecanismo_bombilla1();
void mecanismo_bombilla2();
void mecanismo_radar();
void mecanismo_neopixel();
void setColor(int color);
void mecanismo_servo1();
void mecanismo_servo2();


OneWire ourWire(3);
DallasTemperature sensors(&ourWire);
LiquidCrystal_I2C lcd_racanac(direccion_lcd, columnas, filas);
Adafruit_NeoPixel rueda(Cantidad_Leds,pin_Led, NEO_GRB + NEO_KHZ800);
Servo Servo_racanac;

void setup() {
  Serial.begin(9600);
  lcd_racanac.init();
  lcd_racanac.backlight();
  rueda.begin(); 
  Servo_racanac.attach(pin_servo);
  digitalWrite(BOMBILLA2, HIGH);
  digitalWrite(BOMBILLA1, HIGH);
  salidas();
  entradas();
  animaciones();
  interfaz();
}

void loop() {
  sensor_temp();
  animacion_temp();
  mecanismo_puerta();
  mecanismo_bombilla1();
  mecanismo_bombilla2();
  mecanismo_radar();
}


void interfaz() {
  lcd_racanac.setCursor(0, 0);
  lcd_racanac.print("Temp:");
  lcd_racanac.setCursor(0, 1);
  lcd_racanac.print("presencia:");
  lcd_racanac.setCursor(7, 0);
  lcd_racanac.print("B1:");
  lcd_racanac.setCursor(12 , 0);
  lcd_racanac.print("B2:");
  lcd_racanac.setCursor(12, 1);
  lcd_racanac.print("D:");
}
void animaciones() {
  lcd_racanac.createChar(0, presencia);
  lcd_racanac.createChar(1, presencia2);
  lcd_racanac.createChar(3, luminaria);
  lcd_racanac.createChar(4, luminaria2);
  lcd_racanac.createChar(5, hot);
  lcd_racanac.createChar(6, normal);
  lcd_racanac.createChar(7, ice);
}
void sensor_temp() {
  
  sensors.requestTemperatures();   
  float tempC= sensors.getTempCByIndex(0); 
  
}
void animacion_temp() {
  sensors.requestTemperatures();
  int temp = sensors.getTempCByIndex(0);
  Serial.print(temp);
  Serial.println("°C");
  if (temp >= 15 && temp <= 21) {
    lcd_racanac.setCursor(5, 0);
    lcd_racanac.write(byte(7));
    digitalWrite(led_azul, HIGH);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_rojo, HIGH);
  }
  if (temp > 21 && temp <= 25) {
    lcd_racanac.setCursor(5, 0);
    lcd_racanac.write(byte(6));
    digitalWrite(led_azul, LOW);
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_rojo, LOW);
  }
  if (temp > 25 && temp <= 45) {
    lcd_racanac.setCursor(5, 0);
    lcd_racanac.write(byte(5));
    digitalWrite(led_azul, LOW);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_rojo, HIGH);
  }
}
void salidas() {
  pinMode(led_azul, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(BOMBILLA1, OUTPUT);
  pinMode(BOMBILLA2, OUTPUT);
}
void entradas() {
  pinMode(puerta, INPUT);
  pinMode(bomb1, INPUT);
  pinMode(bomb2, INPUT);
}
void mecanismo_puerta() {
  if (digitalRead(puerta) && estado2 == 0) {
    lcd_racanac.setCursor(14, 1);
    lcd_racanac.print("OP");
    delay(300);
    mecanismo_servo1();
    estado2 = 1;
  }
  if (digitalRead(puerta) && estado2 == 1) {
    lcd_racanac.setCursor(14, 1);
    lcd_racanac.print("CL");
    delay(300);
    mecanismo_servo2();
    estado2 = 0;
  }
}
void mecanismo_bombilla1() {
  if (digitalRead(bomb1) && estado3 == 0) {
    lcd_racanac.setCursor(10, 0);
    lcd_racanac.write(byte(3));
    digitalWrite(BOMBILLA1, LOW);
    delay(300);
    estado3 = 1;
  }
  if (digitalRead(bomb1) && estado3 == 1) {
    lcd_racanac.setCursor(10, 0);
    lcd_racanac.write(byte(4));
    digitalWrite(BOMBILLA1, HIGH);
    
    delay(300);
    estado3 = 0;
  }
}
void mecanismo_bombilla2() {
  if (digitalRead(bomb2) && estado1 == 0) {
    lcd_racanac.setCursor(15, 0);
    lcd_racanac.write(byte(3));
    digitalWrite(BOMBILLA2, LOW);
    delay(300);
    estado1 = 1;
  }
  if (digitalRead(bomb2) && estado1 == 1) {
    lcd_racanac.setCursor(15, 0);
    lcd_racanac.write(byte(4));
    digitalWrite(BOMBILLA2, HIGH);
    delay(300);
    estado1 = 0;
  }
}
void mecanismo_radar() {
  int radar = digitalRead(pinradar);
  if (radar == HIGH) {
    tone(BUZZER, d, 500);
    delay(300);
    tone(BUZZER, f, 500);
    delay(300);
    tone(BUZZER, a, 500);
    delay(300);
    tone(BUZZER, c, 500);
    delay(500);
    lcd_racanac.setCursor(10, 1);
    lcd_racanac.write(byte(0));
    for(int i =0; i<8; i++)
        {
          rueda.setPixelColor(i,rueda.Color(51,255,125));
          rueda.show();  
          delay(300);
          rueda.setPixelColor(i,rueda.Color(255,0,0));
          rueda.show(); 
          delay(300);
        } 
  } if (radar == LOW) {
    lcd_racanac.setCursor(10, 1);
    lcd_racanac.write(byte(1));

  }
}
void mecanismo_servo1(){
  for(unsigned char i = 0; i<181; i++){
    Servo_racanac.write(i);
    delay(10);
  }
}

void mecanismo_servo2(){
  for(unsigned char i = 180; i>0; i--){
    Servo_racanac.write(i);
    delay(10);
}
}
                                                                                                                   
