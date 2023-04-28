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


#include<LiquidCrystal.h>
#define TRIG 16
#define ECHO 14
#define RS 3
#define ENB 4
#define D4 5
#define D5 6
#define D6 7
#define D7 8
#define BUZZER 15
int DURACION;
int DISTANCIA;
int i = 0;
void entradas();
void salidas();
void interfaz();
void limite();
void contador_distancia();
void contador();


byte a1[] = {
  B00000,
  B00011,
  B00100,
  B01110,
  B11001,
  B11101,
  B11111,
  B01110
};

byte a2[] = {
  B00000,
  B00011,
  B00100,
  B01110,
  B11001,
  B11101,
  B11111,
  B01110
};

byte a3[] = {
  B00000,
  B00011,
  B00100,
  B01110,
  B11001,
  B11101,
  B11111,
  B01110
};

byte a4[] = {
  B00000,
  B00011,
  B00100,
  B01110,
  B11001,
  B11101,
  B11111,
  B01110
};

byte a5[] = {
  B00000,
  B00011,
  B00100,
  B01110,
  B11001,
  B11101,
  B11111,
  B01110
};

byte a6[] = {
  B00000,
  B00011,
  B00100,
  B01110,
  B11001,
  B11101,
  B11111,
  B01110
};

byte a7[] = {
  B00000,
  B00011,
  B00100,
  B01110,
  B11001,
  B11101,
  B11111,
  B01110
};

byte c1[] = {
  B00100,
  B10101,
  B01110,
  B11111,
  B11111,
  B01110,
  B10101,
  B00100
};

byte c2[] = {
  B00100,
  B10101,
  B01110,
  B11111,
  B11111,
  B01110,
  B10101,
  B00100
};

byte c3[] = {
  B00100,
  B10101,
  B01110,
  B11111,
  B11111,
  B01110,
  B10101,
  B00100
};

byte c4[] = {
  B00100,
  B10101,
  B01110,
  B11111,
  B11111,
  B01110,
  B10101,
  B00100
};

byte c5[] = {
  B00100,
  B10101,
  B01110,
  B11111,
  B11111,
  B01110,
  B10101,
  B00100
};

byte c6[] = {
  B00100,
  B10101,
  B01110,
  B11111,
  B11111,
  B01110,
  B10101,
  B00100
};

byte c7[] = {
  B00100,
  B10101,
  B01110,
  B11111,
  B11111,
  B01110,
  B10101,
  B00100
};
LiquidCrystal LCD_Racanac(RS, ENB, D4, D5, D6, D7);

void setup() {
  Serial.begin(9600);
  entradas();
  salidas();
}

void loop() {
  interfaz();
  limite();
  contador_distancia();
  contador();
 } 


 

void entradas(){
  pinMode(ECHO, INPUT);
}
void salidas(){
  pinMode(TRIG, OUTPUT);
}
void interfaz(){
  LCD_Racanac.begin(16,2);
  LCD_Racanac.print("-Personas: ");
  LCD_Racanac.setCursor(11,0);
  LCD_Racanac.print(i);
}
void limite(){
  if(i>=17){
    LCD_Racanac.clear();
    tone(BUZZER, 440,000);
    LCD_Racanac.setCursor(5,0);
    LCD_Racanac.print("AFORO");
    LCD_Racanac.setCursor(5,1);
    LCD_Racanac.print("LLENO");
    LCD_Racanac.createChar(1, a1);
    LCD_Racanac.home();
    LCD_Racanac.write(1);
    LCD_Racanac.createChar(2, a2);
    LCD_Racanac.home();
    LCD_Racanac.setCursor(2,1);
    LCD_Racanac.write(2);
    LCD_Racanac.createChar(3, a3);
    LCD_Racanac.home();
    LCD_Racanac.setCursor(3,0);
    LCD_Racanac.write(3);
    LCD_Racanac.createChar(4, a4);
    LCD_Racanac.home();
    LCD_Racanac.setCursor(11,0);
    LCD_Racanac.write(4);
    LCD_Racanac.createChar(5, a3);
    LCD_Racanac.home();
    LCD_Racanac.setCursor(13,0);
    LCD_Racanac.write(5);
    LCD_Racanac.createChar(6, a3);
    LCD_Racanac.home();
    LCD_Racanac.setCursor(15,0);
    LCD_Racanac.write(6);
    LCD_Racanac.createChar(7, a3);
    LCD_Racanac.home();
    LCD_Racanac.setCursor(12,1);
    LCD_Racanac.write(7);
    delay(700);
    LCD_Racanac.createChar(8, c1);
    LCD_Racanac.home();
    LCD_Racanac.setCursor(0,0);
    LCD_Racanac.write(8);
    delay(700);
    LCD_Racanac.createChar(9, c2);
    LCD_Racanac.home();
    LCD_Racanac.setCursor(2,1);
    LCD_Racanac.write(9);
    delay(700);
    LCD_Racanac.createChar(10, c3);
    LCD_Racanac.home();
    LCD_Racanac.setCursor(3,0);
    LCD_Racanac.write(10);
    delay(700);
    LCD_Racanac.createChar(11, c4);
    LCD_Racanac.home();
    LCD_Racanac.setCursor(11,0);
    LCD_Racanac.write(11);
    delay(700);
    LCD_Racanac.createChar(12, c5);
    LCD_Racanac.home();
    LCD_Racanac.setCursor(12,1);
    LCD_Racanac.write(12);
    delay(700);
    LCD_Racanac.createChar(13, c6);
    LCD_Racanac.home();
    LCD_Racanac.setCursor(13,0);
    LCD_Racanac.write(13);
    delay(700);
    LCD_Racanac.createChar(14, c7);
    LCD_Racanac.home();
    LCD_Racanac.setCursor(15,0);
    LCD_Racanac.write(14);
    
  }
}
void contador_distancia(){
   digitalWrite(TRIG, HIGH);
   delay(1);
   digitalWrite(TRIG, LOW);
   DURACION = pulseIn(ECHO, HIGH);
   DISTANCIA = DURACION / 58.2;
   Serial.println(DISTANCIA);
   delay(500);
}
void contador(){
   if(DISTANCIA>=6 && DISTANCIA<=10){
    i = i + 1;
   }
}
