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
#define TRIG 15
#define ECHO 16
int DURACION;
int DISTANCIA;
void entrada();
void salida();
void medicion_distancia();
void condiciones_funcionamiento();

byte c1[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};


LiquidCrystal_I2C lcd_racanac(direccion_lcd, columnas, filas);

void setup() {
  
  Serial.begin(9600);
  lcd_racanac.init();
  lcd_racanac.backlight();
  entrada();
  salida();
  
}

void loop() {

   mecidion_distancia();
   condiciones_funcionamiento();

}




void entrada(){
  pinMode(ECHO, INPUT);
}
void salida(){
  pinMode(TRIG, OUTPUT);
}
void medicion_distancia(){
   digitalWrite(TRIG, HIGH);
   delay(1);
   digitalWrite(TRIG, LOW);
   DURACION = pulseIn(ECHO, HIGH);
   DISTANCIA = DURACION / 58.2;
   Serial.println(DISTANCIA);
   delay(200);
}
void condiciones_funcionamiento(){
   if(DISTANCIA==50){
    lcd_racanac.clear();
    lcd_racanac.setCursor(7,0);
    lcd_racanac.print("50");
    lcd_racanac.createChar(0, c1);
    lcd_racanac.home();
    lcd_racanac.setCursor(6,0);
    lcd_racanac.write(0);
    lcd_racanac.createChar(0, c1);
    lcd_racanac.home();
    lcd_racanac.setCursor(5,0);
    lcd_racanac.write(0);
    lcd_racanac.createChar(0, c1);
    lcd_racanac.home();
    lcd_racanac.setCursor(4,0);
    lcd_racanac.write(0);
    lcd_racanac.createChar(0, c1);
    lcd_racanac.home();
    lcd_racanac.setCursor(9,0);
    lcd_racanac.write(0);
    lcd_racanac.createChar(0, c1);
    lcd_racanac.home();
    lcd_racanac.setCursor(10,0);
    lcd_racanac.write(0);
    lcd_racanac.createChar(0, c1);
    lcd_racanac.home();
    lcd_racanac.setCursor(11,0);
    lcd_racanac.write(0);
    lcd_racanac.setCursor(5,1);
    lcd_racanac.print("libre");
   }else{
    if(DISTANCIA==30){
      lcd_racanac.clear();
      lcd_racanac.setCursor(7,0);
      lcd_racanac.print("30");
      lcd_racanac.createChar(0, c1);
      lcd_racanac.home();
      lcd_racanac.setCursor(6,0);
      lcd_racanac.write(0);
      lcd_racanac.createChar(0, c1);
      lcd_racanac.home();
      lcd_racanac.setCursor(5,0);
      lcd_racanac.write(0);
      lcd_racanac.createChar(0, c1);
      lcd_racanac.home();
      lcd_racanac.setCursor(4,0);
      lcd_racanac.write(0);
      lcd_racanac.createChar(0, c1);
      lcd_racanac.home();
      lcd_racanac.setCursor(3,0);
      lcd_racanac.write(0);
      lcd_racanac.createChar(0, c1);
      lcd_racanac.home();
      lcd_racanac.setCursor(2,0);
      lcd_racanac.write(0);
      lcd_racanac.setCursor(9,0);
      lcd_racanac.write(0);
      lcd_racanac.createChar(0, c1);
      lcd_racanac.home();
      lcd_racanac.setCursor(10,0);
      lcd_racanac.write(0);
      lcd_racanac.createChar(0, c1);
      lcd_racanac.home();
      lcd_racanac.setCursor(11,0);
      lcd_racanac.write(0);
      lcd_racanac.createChar(0, c1);
      lcd_racanac.home();
      lcd_racanac.setCursor(12,0);
      lcd_racanac.write(0);
      lcd_racanac.createChar(0, c1);
      lcd_racanac.home();
      lcd_racanac.setCursor(13,0);
      lcd_racanac.write(0);
      lcd_racanac.setCursor(4,1);
      lcd_racanac.print("Cuidado");
    }else{
      if(DISTANCIA==10){
        lcd_racanac.clear();
        lcd_racanac.setCursor(7,0);
        lcd_racanac.print("10");
        lcd_racanac.createChar(0, c1);
        lcd_racanac.home();
        lcd_racanac.setCursor(6,0);
        lcd_racanac.write(0);
        lcd_racanac.createChar(0, c1);
        lcd_racanac.home();
        lcd_racanac.setCursor(5,0);
        lcd_racanac.write(0);
        lcd_racanac.createChar(0, c1);
        lcd_racanac.home();
        lcd_racanac.setCursor(4,0);
        lcd_racanac.write(0);
        lcd_racanac.createChar(0, c1);
        lcd_racanac.home();
        lcd_racanac.setCursor(3,0);
        lcd_racanac.write(0);
        lcd_racanac.createChar(0, c1);
        lcd_racanac.home();
        lcd_racanac.setCursor(2,0);
        lcd_racanac.write(0);
        lcd_racanac.createChar(0, c1);
        lcd_racanac.home();
        lcd_racanac.setCursor(1,0);
        lcd_racanac.write(0);
        lcd_racanac.createChar(0, c1);
        lcd_racanac.home();
        lcd_racanac.setCursor(0,0);
        lcd_racanac.write(0);
        lcd_racanac.setCursor(9,0);
        lcd_racanac.write(0);
        lcd_racanac.createChar(0, c1);
        lcd_racanac.home();
        lcd_racanac.setCursor(10,0);
        lcd_racanac.write(0);
        lcd_racanac.createChar(0, c1);
        lcd_racanac.home();
        lcd_racanac.setCursor(11,0);
        lcd_racanac.write(0);
        lcd_racanac.createChar(0, c1);
        lcd_racanac.home();
        lcd_racanac.setCursor(12,0);
        lcd_racanac.write(0);
        lcd_racanac.createChar(0, c1);
        lcd_racanac.home();
        lcd_racanac.setCursor(13,0);
        lcd_racanac.write(0);
        lcd_racanac.createChar(0, c1);
        lcd_racanac.home();
        lcd_racanac.setCursor(14,0);
        lcd_racanac.write(0);
        lcd_racanac.createChar(0, c1);
        lcd_racanac.home();
        lcd_racanac.setCursor(15,0);
        lcd_racanac.write(0);
        lcd_racanac.setCursor(6,1);
        lcd_racanac.print("Alto");
   }if(DISTANCIA>51){
    lcd_racanac.clear();
   }
  }
 }
}
