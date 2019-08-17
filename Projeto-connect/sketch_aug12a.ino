#include <myled.h>


const String LED01 ="\"LED01\":";
const String LED02 ="\"LED02\":";

MyLed verde(D2);
MyLed vermelho(D3);
 
#define ldrA D0
#define ldrB D1
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

String JSON_LED1(){
  return "{" +
              LED01 + String(verde.status()) + "," +
              "}";             
 }
 
 String JSON_LED2(){
  return "{" +
              LED02 + String(vermelho.status()) + "," +
              "}";             
 }

void setup() {
 
  pinMode(ldrA,INPUT);
  pinMode(verde.getPino(),OUTPUT);
  pinMode(ldrB,INPUT);
  pinMode(vermelho.getPino(),OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(button,INPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD,OUTPUT);
  Serial.begin(115200);
}

void loop() {

    digitalWrite (ledC,HIGH);
    digitalWrite(ledD,HIGH);
   vldrA=analogRead(ldrA);
     if(vldrA<limiteA){
      digitalWrite(verde.getPino(),HIGH);
      digitalWrite(buzz,HIGH);
      delay(tempoBuzzerGol);
      digitalWrite(buzz,LOW);   
  } 
    else{
      digitalWrite(verde.getPino(),LOW);
   }
   if(verde.status())
    Serial.println(JSON_LED1());
    
   if(vermelho.status())
    Serial.println(JSON_LED2());
  
  Serial.println("LDR A:");
  Serial.println(vldrA);

    vldrB=analogRead(ldrB);
    if(vldrB<limiteB) {
      digitalWrite(vermelho.getPino(),HIGH);
      digitalWrite(buzz,HIGH);
      delay(tempoBuzzerGol);
      digitalWrite(buzz,LOW);
  }
  else{
    digitalWrite(vermelho.getPino(),LOW);  
  }
  Serial.println("LDR B:");
  Serial.println(vldrB);
 
  fimDeJogo=analogRead(button);
  if(fimDeJogo>1000) {
      digitalWrite(verde.getPino(),HIGH);
      digitalWrite(vermelho.getPino(),HIGH);
      digitalWrite(buzz,HIGH);
      delay(tempoBuzzerGol);
      digitalWrite(buzz,LOW);
      delay (1000);
      digitalWrite(verde.getPino(),LOW);
      digitalWrite(vermelho.getPino(),LOW);
  
  }
  
  delay(500); 
 }
 
