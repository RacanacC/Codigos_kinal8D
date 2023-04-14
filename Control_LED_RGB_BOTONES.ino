
#define Button1 3
#define Button2 4
#define R 5
#define G 6
#define B 7
int RB;
int RB2;


void setup() {
  Serial.begin(9600);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

}

void loop() {
  
  RB = digitalRead(Button1);
  RB2 = digitalRead(Button2);
  if(RB==HIGH && RB2==LOW){
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
  }
  
  if(RB2==HIGH && RB==LOW){
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
  }
  if(RB==HIGH && RB2==HIGH){    
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
  }
  if(RB == LOW && RB2 == LOW){
    digitalWrite(R, HIGH);
    delay(500);
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    delay(500);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
    delay(500);
    digitalWrite(B, LOW);
  }
}
