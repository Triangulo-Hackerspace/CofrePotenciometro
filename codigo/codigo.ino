int sensorPin = A0;
const int btnPin = 12;
char segredo[4] = {2,7,4,7};
int posicao = 1;

void setup() {
  
  Serial.begin(9600);
  
 //inicializa os pinos do arduino
 for(int i=2; i <= 11; i++){
   pinMode(i, OUTPUT);
 }
  
  pinMode(btnPin, INPUT);

}

void loop() {
  
  int sensorValue = analogRead(sensorPin);    
  int numeroDigitado = ((sensorValue*9) / 1023);

 if(!digitalRead(btnPin)){
  for(int i=0; i<= 9; i++){
   if(i <= numeroDigitado){
     digitalWrite(i+2, HIGH);
   } else {
     digitalWrite(i+2, LOW);
   } 
  }
 }else {
   
   //DEBUG
   Serial.print("Posicao: ");
   Serial.print(posicao);
   Serial.print(" - Numero Digitado: ");
   Serial.println(numeroDigitado);
   
   //Se o botao foi digitado
   if(posicao == 1 && (int(segredo[0]) == numeroDigitado)){
     posicao = 2 ;
   } else if(posicao == 2 && (int(segredo[1]) == numeroDigitado)){
     posicao = 3 ;
   }else if(posicao == 3 && (int(segredo[2]) == numeroDigitado)){
     posicao = 4 ;
   }else if(posicao == 4 && (int(segredo[3]) == numeroDigitado)){
     posicao = 5;
   } else if( posicao == 5) {
     //Abre o cofre
     blinkAll(10);
   }
  
 }
}

void blinkAll(int x){
  for(int i=0; i < x; i++){
    for(int i=2; i<= 11; i++){
      digitalWrite(i, LOW);
    }
    delay(200);
    for(int i=2; i<= 11; i++){
      digitalWrite(i, HIGH);
    }
    delay(200);
    for(int i=2; i<= 11; i++){
      digitalWrite(i, LOW);
    }
  }
  

}
