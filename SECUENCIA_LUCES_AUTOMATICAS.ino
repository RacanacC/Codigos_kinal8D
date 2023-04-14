#define LED1 3
#define LED2 4
#define LED3 5
#define LED4 6
#define LED5 7
#define LED6 8
#define LED7 9
#define LED8 10
#define LED9 11
#define LED10 12

int led = 3;
int ledSig = 4;
int ledb = 12;
int ledb2 = 1;

void setup() {
  Serial.print(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);

}

void loop() {
if(led>12){
  for(int i = 12; i >= 3; i = i - 1){
   digitalWrite(ledSig, HIGH);
   digitalWrite(led, LOW);
   led = ledSig;
   ledSig = ledSig -1;
   delay(150);
   }
}
  
digitalWrite(led, HIGH);
digitalWrite(ledSig, LOW);

ledSig = led;

led = led +1;
delay(150);
}
