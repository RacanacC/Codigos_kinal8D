
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

#define TRIG 5
#define ECHO 6
#define RELE 3
int DURACION;
int DISTANCIA;
#define a 10
#define b 11
#define c 12
#define d 13
#define e 14
#define f 15
#define g 16

int i = 0;

void configuracion_pines_entrada();
void configuracion_pines_salida();
void medicion_distancia();
void conteo_activacion();

void setup() {
  Serial.begin(9600);
  configuracion_pines_entrada();
  configuracion_pines_salida();
  cero();
}

void loop() {
  medicion_distancia();
  conteo_activacion();
}
void configuracion_pines_entrada(){
   pinMode(ECHO, INPUT);
}
void configuracion_pines_salida(){
  pinMode(TRIG, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(RELE, OUTPUT);
  
}

void medicion_distancia(){
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECHO, HIGH);
  DISTANCIA = DURACION / 58.2;
}
void conteo_activacion(){
  if(DISTANCIA>=6 && DISTANCIA<=10){
    i = i + 1;
    Serial.println(i);
    delay(500);
    if(i==0){
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(RELE, HIGH);
    }else{
      if(i==1){
        digitalWrite(a, LOW);
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(d, LOW);
        digitalWrite(e, LOW);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
        digitalWrite(RELE, HIGH);
      }else{
        if(i==2){
          digitalWrite(a, HIGH);
          digitalWrite(b, HIGH);
          digitalWrite(c, LOW);
          digitalWrite(d, HIGH);
          digitalWrite(e, HIGH);
          digitalWrite(f, LOW);
          digitalWrite(g, HIGH);
          digitalWrite(RELE, HIGH);
        }else{
          if(i==3){
            digitalWrite(a, HIGH);
            digitalWrite(b, HIGH);
            digitalWrite(c, HIGH);
            digitalWrite(d, HIGH);
            digitalWrite(e, LOW);
            digitalWrite(f, LOW);
            digitalWrite(g, HIGH);
            digitalWrite(RELE, HIGH);
          }else{
            if(i==4){
              digitalWrite(a, LOW);
              digitalWrite(b, HIGH);
              digitalWrite(c, HIGH);
              digitalWrite(d, LOW);
              digitalWrite(e, LOW);
              digitalWrite(f, HIGH);
              digitalWrite(g, HIGH);
              digitalWrite(RELE, HIGH);
            }else{
              if(i==5){
                   digitalWrite(a, HIGH);
                   digitalWrite(b, LOW);
                   digitalWrite(c, HIGH);
                   digitalWrite(d, HIGH);
                   digitalWrite(e, LOW);
                   digitalWrite(f, HIGH);
                   digitalWrite(g, HIGH);
                   digitalWrite(RELE, HIGH);
              }else{
                if(i==6){
                     digitalWrite(a, HIGH);
                     digitalWrite(b, LOW);
                     digitalWrite(c, HIGH);
                     digitalWrite(d, HIGH);
                     digitalWrite(e, HIGH);
                     digitalWrite(f, HIGH);
                     digitalWrite(g, HIGH);
                     digitalWrite(RELE, HIGH);
                }else{
                  if(i==7){
                      digitalWrite(a, HIGH);
                      digitalWrite(b, HIGH);
                      digitalWrite(c, HIGH);
                      digitalWrite(d, LOW);
                      digitalWrite(e, LOW);
                      digitalWrite(f, LOW);
                      digitalWrite(g, LOW);
                      digitalWrite(RELE, HIGH);
                  }else{
                    if(i==8){
                         digitalWrite(a, HIGH);
                         digitalWrite(b, HIGH);
                         digitalWrite(c, HIGH);
                         digitalWrite(d, HIGH);
                         digitalWrite(e, HIGH);
                         digitalWrite(f, HIGH);
                         digitalWrite(g, HIGH);
                         digitalWrite(RELE, HIGH);
                    }else{
                      if(i==9){
                         digitalWrite(a, HIGH);
                         digitalWrite(b, HIGH);
                         digitalWrite(c, HIGH);
                         digitalWrite(d, LOW);
                         digitalWrite(e, LOW);
                         digitalWrite(f, HIGH);
                         digitalWrite(g, HIGH);
                         digitalWrite(RELE, LOW);
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
void cero(){
   digitalWrite(a, HIGH);
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, LOW);
}
