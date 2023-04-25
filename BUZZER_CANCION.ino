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
#define TRIG 3
#define ECHO 4
#define BUZZER 5                          
int DURACION;
int DISTANCIA;

void pines_salida();
void pines_entrada();
void conteo_funcion();

void setup() {
  Serial.begin(9600);
  pines_salida();
  pines_entrada();
}

void loop() {
 conteo_funcion();
}
void pines_salida(){
  pinMode(TRIG, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}
void pines_entrada(){
  pinMode(ECHO, INPUT);
}
void conteo_funcion(){
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECHO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);
  if(DISTANCIA==4){
    tone(BUZZER, 261,626);
    delay(500);
  }else{
    if(DISTANCIA==8){
     tone(BUZZER, 293,665);
     delay(500);
    }else{
      if(DISTANCIA==12){
        tone(BUZZER, 329,628);
        delay(500);
      }else{
        if(DISTANCIA==16){
           tone(BUZZER, 349,228);
           delay(500);
      }else{
        if(DISTANCIA==20){
          tone(BUZZER, 391,995);
          delay(500);
        }else{
          if(DISTANCIA==24){
             tone(BUZZER, 440,000);
             delay(500);
        }else{
          if(DISTANCIA==28){
            tone(BUZZER, 466,164);
            delay(500);
          }else{
            if(DISTANCIA==30){
            tone(BUZZER, 523,251);
            delay(500);
        }
       }
      }
     }
    }
   }
  }
 }
}
