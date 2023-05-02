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


# include<Wire.h>     
# include<LiquidCrystal_I2C.h>
#define direccion_lcd 0x27
#define filas 2
#define columnas 16   
#define led1 3
#define led2 4
#define led3 5
#define led4 6
#define led5 7
#define led6 8
#define led7 9 
#define led8 10
#define led9 11
#define led10 12
#define BUZZER 14
#define TRIG 15
#define ECHO 16
int DURACION;
int DISTANCIA;
int a = 1760;
int a2 = 880;
int a3 = 440;
int a4 = 220;
void entradas();
void salidas();
void medida_distancia();
void condiciones();

LiquidCrystal_I2C lcd_racanac(direccion_lcd, columnas, filas);

void setup() {
  Serial.begin(9600);
  lcd_racanac.init();
  lcd_racanac.backlight();
  entradas();
  salidas();
}

void loop() {
  medida_distancia();
  condiciones();
}




void entradas(){
  pinMode(ECHO, INPUT);
}
void salidas(){
  pinMode(TRIG, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
}
void medida_distancia(){
   digitalWrite(TRIG, HIGH);
   delay(1);
   digitalWrite(TRIG, LOW);
   DURACION = pulseIn(ECHO, HIGH);
   DISTANCIA = DURACION / 58.2;
   Serial.println(DISTANCIA);
   delay(500);
}
void condiciones(){
   if(DISTANCIA>5 && DISTANCIA<15){
    lcd_racanac.clear();
    lcd_racanac.setCursor(0,0);
    lcd_racanac.print("   Invadiendo");
    lcd_racanac.setCursor(0,1);
    lcd_racanac.print("Espacio Privado");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
    digitalWrite(led10, HIGH);
    tone(BUZZER, a, 10000);
    delay(10000+50);
    noTone(BUZZER);
   }else{
    if(DISTANCIA>15 && DISTANCIA<30){
    lcd_racanac.clear();
    lcd_racanac.setCursor(0,0);
    lcd_racanac.print("    Cuidado");
    lcd_racanac.setCursor(0,1);
    lcd_racanac.print("Espacio Privado");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    digitalWrite(led10, LOW);
    tone(BUZZER, a2, 5000);
    delay(5000+50);
    noTone(BUZZER);
   }else{
    if(DISTANCIA>30 && DISTANCIA<45){
    lcd_racanac.clear();
    lcd_racanac.setCursor(0,0);
    lcd_racanac.print("    Persona");
    lcd_racanac.setCursor(0,1);
    lcd_racanac.print("  Acercandose");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    digitalWrite(led10, LOW);
   }else{
    if(DISTANCIA>45){
    lcd_racanac.clear();
    lcd_racanac.setCursor(0,0);
    lcd_racanac.print("    Fuera de");
    lcd_racanac.setCursor(0,1);
    lcd_racanac.print("    Alcance");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    digitalWrite(led10, LOW);
   }
  }
 }
}
}
