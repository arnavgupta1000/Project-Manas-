int ledpin[]={3,4,5,6,};
int i;
int delaytime=1000;
volatile bool m=false;
//volatile bool currentbutton=false;
void setup(){
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, INPUT);
  pinMode(A1, INPUT);
  attachInterrupt(0,buttonloop,RISING);
  }
void buttonloop(){
  m=!m;
}

void loop(){
  while(m){
  for(i=0;i<4;i++){
    delaytime=analogRead(A1);
    digitalWrite(ledpin[i], HIGH);
    delay(delaytime);
    digitalWrite(ledpin[i], LOW);
  }
  for(i=3;i>=0;i--){
    delaytime=analogRead(A1);
    digitalWrite(ledpin[i], HIGH);
    delay(delaytime);
    digitalWrite(ledpin[i], LOW);
  }
}
}
