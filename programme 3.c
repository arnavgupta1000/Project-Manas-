#include<Servo.h>
int delaytime=1000;
int val=1000;
int pot=1000;
bool m=false;
bool n=false;
int i,j;
int pos=0;
Servo myservo;
void setup(){
  myservo.attach(11);
  pinMode(5,OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(A1, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  attachInterrupt(0,changemotor,RISING);
  attachInterrupt(1,changedir,RISING);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
}
void changemotor(){
  m=!m;
}
void changedir(){
  n=!n;
}
void servo(){
  for(pos=0;pos<=180;pos++){
      delaytime=analogRead(A1);
      val=map(delaytime,0,1023,10,100);
      myservo.write(pos);
      delay(val);
    }
    for(pos=180;pos>=0;pos--){
      delaytime=analogRead(A1);
      val=map(delaytime,0,1023,10,100);
      myservo.write(pos);
      delay(val);
    }
}
void dcant(){

  delaytime=analogRead(A1);
  pot=map(delaytime,0,1023,0,255);
  analogWrite(6,pot);
  digitalWrite(7, HIGH);
}
void cloc(){
  delaytime=analogRead(A1);
  pot=map(delaytime,0,1023,0,255);
  analogWrite(6,pot);
  digitalWrite(7, LOW);
}

void loop(){
  if(m){
    dcant();
    if(n){
      cloc();
    }
  }
  else{
    servo();
  }
}
  
