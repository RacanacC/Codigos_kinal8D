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
#define RS 3
#define ENB 4
#define D4 5
#define D5 6
#define D6 7
#define D7 8

LiquidCrystal LCD_Racanac(RS, ENB, D4, D5, D6, D7);

void setup() {
  LCD_Racanac.begin(16,2);
  LCD_Racanac.setCursor(3,0);
  LCD_Racanac.print("Alexander");
  LCD_Racanac.setCursor(4, 1);
  LCD_Racanac.print("2022083");
 

}

void loop() {
  // put your main code here, to run repeatedly:

}
