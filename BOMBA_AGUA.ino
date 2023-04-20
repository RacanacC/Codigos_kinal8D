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

#define Transistor 3
#define Ledr 4
#define Leda 5
#define Bomba 6


void setup() {
  
  pinMode(Transistor, INPUT);
  pinMode(Ledr, OUTPUT);
  pinMode(Leda, OUTPUT);
  pinMode(Bomba, OUTPUT);

}

void loop() {
  int estado = digitalRead(Transistor);
  if(estado == LOW){
    digitalWrite(Ledr, HIGH);
    digitalWrite(Leda, LOW);
    digitalWrite(Bomba, LOW);
    
  }
  if(estado == HIGH){
    digitalWrite(Ledr, LOW);
    digitalWrite(Leda, HIGH);
    digitalWrite(Bomba, HIGH);
    
  }
}
