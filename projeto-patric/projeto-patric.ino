#define ldrA D0
#define ldrB D1
#define ledA D2
#define ledB D3
#define buzz D4
#define button D5
#define ledC D6
#define ledD D7

#define tempoBuzzerGol 500
#define tempoBuzzerFinal 500
#define limiteA 700
#define limiteB 700

int vldrA=0;
int vldrB=0;
int fimDeJogo=0;



void setup() {
 
  pinMode(ldrA,INPUT);
  pinMode(ledA,OUTPUT);
  pinMode(ldrB,INPUT);
  pinMode(ledB,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(button,INPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD,OUTPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite (ledC,HIGH);
  digitalWrite(ledD,HIGH);
  vldrA=analogRead(ldrA);
  if(vldrA<limiteA){
    digitalWrite(ledA,HIGH);
    digitalWrite(buzz,HIGH);
    delay(tempoBuzzerGol);
    digitalWrite(buzz,LOW);
    
  }else{
    digitalWrite(ledA,LOW);
  }
  Serial.println("LDR A:");
  Serial.println(vldrA);

  vldrB=analogRead(ldrB);
  if(vldrB<limiteB) {
      digitalWrite(ledB,HIGH);
      digitalWrite(buzz,HIGH);
      delay(tempoBuzzerGol);
      digitalWrite(buzz,LOW);
  }
  else{
    digitalWrite(ledB,LOW);  
  }
  Serial.println("LDR B:");
  Serial.println(vldrB);
 
  fimDeJogo=analogRead(button);
  if(fimDeJogo>1000) {
      digitalWrite(ledA,HIGH);
      digitalWrite(ledB,HIGH);
      digitalWrite(buzz,HIGH);
      delay(tempoBuzzerGol);
      digitalWrite(buzz,LOW);
      delay (1000);
      digitalWrite(ledA,LOW);
      digitalWrite(ledB,LOW);
  
  }
  
  delay(100); 
 }
