
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

#include <Keypad.h>
#define columnas_teclado 4
#define filas_teclado 4
#define f1_teclado 2
#define f2_teclado 3
#define f3_teclado 4
#define f4_teclado 5 
#define c1_teclado 6
#define c2_teclado 7
#define c3_teclado 8
#define c4_teclado 9
#define a 10
#define b 11
#define c 12
#define d 13
#define e 14
#define f 15
#define g 16

char keys [filas_teclado][columnas_teclado] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte pines_filas[filas_teclado] = {f1_teclado,f2_teclado,f3_teclado,f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado,c2_teclado,c3_teclado,c4_teclado};

Keypad teclado_profe = Keypad( makeKeymap(keys), pines_filas, pines_columnas, filas_teclado,columnas_teclado);

void setup() {
  Serial.begin(9600);    
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

}

void loop() {
   
   char tecla = teclado_profe.getKey();
   if(tecla==LOW){
     digitalWrite(a, HIGH);
     digitalWrite(b, HIGH);
     digitalWrite(c, HIGH);
     digitalWrite(d, HIGH);
     digitalWrite(e, HIGH);
     digitalWrite(f, HIGH);
     digitalWrite(g, LOW);
   }
   
   if(tecla=='0'){
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, LOW);
   delay(1700);
   
}else{
  
  if(tecla=='1'){
   digitalWrite(a, LOW);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, LOW);
   digitalWrite(g, LOW);
   delay(1700);

}else{
 if(tecla=='2'){
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, LOW);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, LOW);
   digitalWrite(g, HIGH);
   delay(1700);

}else{
 if(tecla=='3'){
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, LOW);
   digitalWrite(f, LOW);
   digitalWrite(g, HIGH);
   delay(1700);

}else{
 if(tecla=='4'){
   digitalWrite(a, LOW);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   delay(1700);

}else{
 if(tecla=='5'){
   digitalWrite(a, HIGH);
   digitalWrite(b, LOW);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, LOW);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   delay(1700);

}else{
 if(tecla=='6'){
   digitalWrite(a, HIGH);
   digitalWrite(b, LOW);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   delay(1700);

}else{
 if(tecla=='7'){
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, LOW);
   digitalWrite(g, LOW);
   delay(1700);

}else{
 if(tecla=='8'){
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   delay(1700);

}else{
 if(tecla=='9'){
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, LOW);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   delay(1700);

}else{
 if(tecla=='*'){
   digitalWrite(a, HIGH);
   digitalWrite(b, LOW);
   digitalWrite(c, LOW);
   digitalWrite(d, LOW);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   delay(1700);

}else{
 if(tecla=='#'){
   digitalWrite(a, HIGH);
   digitalWrite(b, LOW);
   digitalWrite(c, LOW);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   delay(1700);

}else{
 if(tecla=='A'){
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, LOW);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   delay(1700);

}else{
 if(tecla=='B'){
   digitalWrite(a, LOW);
   digitalWrite(b, LOW);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   delay(1700);

}else{
 if(tecla=='C'){
   digitalWrite(a, LOW);
   digitalWrite(b, LOW);
   digitalWrite(c, LOW);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, LOW);
   digitalWrite(g, HIGH);
   delay(1700);

}else{
 if(tecla=='D'){
   digitalWrite(a, LOW);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, LOW);
   digitalWrite(g, HIGH);
   delay(1700);

}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
