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

#define selecG 2
#define selecB 3
int x=0;
int y;

struct Articulo{
  float PrecioU;
  int Stock;
  char Nombre [30];
  int Reserva;
  float PrecioLote;

};

Articulo Producto1 = {8.99, 10, "Te de limon", 12, 89.9};
Articulo Producto2 = {5.00, 10, "Agua pura cielo", 9, 50.00};
Articulo Producto3 = {1.00, 8, "Tortrix de limon", 5, 8.00};
Articulo Producto4 = {6.00, 8, "Jugo de naranja Del Valle", 8, 48.00};

void setup() {
  Serial.begin(9600);
  pinMode(selecG, INPUT);
  pinMode(selecB, INPUT);
  Serial.println("--------------BIENVENIDO-------------");
}

void loop() {

if(digitalRead(selecG)==HIGH){
  y = 1;
}

if(digitalRead(selecB)==HIGH){
  y = 1;
}

while(y==1){
  if(digitalRead(selecG)==HIGH){
  x = x + 1;
  delay(200);
}
if(x>4){
  x = 1;
}
if(digitalRead(selecB)==HIGH){
  x = x - 1;
  delay(200);
if(x<1){
  x = 4;
}
}

switch(x){
  case (1): Serial.println("-------------------------------------");
          Serial.println("PRIMER ARTICULO");
          Serial.print("Nombre del articulo: ");
          Serial.println(Producto1.Nombre);
          Serial.print("Precio del articulo: Q.");
          Serial.println(Producto1.PrecioU);
          Serial.print("Stock del articulo: ");
          Serial.println(Producto1.Stock);
          Serial.print("Reserva del artículo: ");
          Serial.println(Producto1.Reserva);
          Serial.print("Precio Lote del articulo: Q.");
          Serial.println(Producto1.PrecioLote);
          y = 2;
          break;
          
  case(2): Serial.println("-------------------------------------");
          Serial.println("SEGUNDO ARTICULO");
          Serial.print("Nombre del articulo: ");
          Serial.println(Producto2.Nombre);
          Serial.print("Precio del articulo: Q.");
          Serial.println(Producto2.PrecioU);
          Serial.print("Stock del articulo: ");
          Serial.println(Producto2.Stock);
          Serial.print("Reserva del artículo: ");
          Serial.println(Producto2.Reserva);
          Serial.print("Precio Lote del articulo: Q.");
          Serial.println(Producto2.PrecioLote); 
          y = 2;
          break;
 case (3): Serial.println("-------------------------------------");
         Serial.println("TERCER ARTICULO");
         Serial.print("Nombre del articulo: ");
         Serial.println(Producto3.Nombre);
         Serial.print("Precio del articulo: Q.");
         Serial.println(Producto3.PrecioU);
         Serial.print("Stock del articulo: ");
         Serial.println(Producto3.Stock);
         Serial.print("Reserva del artículo: ");
         Serial.println(Producto3.Reserva);
         Serial.print("Precio Lote del articulo: Q.");
         Serial.println(Producto3.PrecioLote);
         y= 2;
         break;
 case (4): Serial.println("-------------------------------------");
         Serial.println("CUARTO ARTICULO");
         Serial.print("Nombre del articulo: ");
         Serial.println(Producto4.Nombre);
         Serial.print("Precio del articulo: Q.");
         Serial.println(Producto4.PrecioU);
         Serial.print("Stock del articulo: ");
         Serial.println(Producto4.Stock);
         Serial.print("Reserva del artículo: ");
         Serial.println(Producto4.Reserva);
         Serial.print("Precio Lote del articulo: Q.");
         Serial.println(Producto4.PrecioLote);
         y = 2;
         break;
}

}
}
