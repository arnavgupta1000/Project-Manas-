int led1  = 12;
int led2  =11;
int led3  =10;
int led4   = 9;
int led5  =8;
int led6  =7;
int trig =4;
int echo =2;
long distance;
long duration;



void setup()
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  digitalWrite(trig , LOW);
  Serial.begin(9600);
  
}



void loop()
{
    digitalWrite(trig , HIGH);
    delayMicroseconds(10);
    digitalWrite(trig , LOW);
    
    duration = pulseIn(echo, HIGH );

    distance = (duration*.0343)/2;
    Serial.println( duration);

     if ( distance <= 50 && distance >= 2 )
  {
    digitalWrite(led1,HIGH);
  }
  else
  {
    digitalWrite(led1,LOW);
  }
  if(distance <= 100 && distance >= 50 )
  {
    digitalWrite(led2,HIGH);
  }
  else
  {
    digitalWrite(led2,LOW);
  }
  if( distance <= 150 && distance >=100)
  {
    digitalWrite(led3,HIGH);
  }
  else
  {
    digitalWrite(led3,LOW);
  }
   if( distance <= 200 && distance >= 150)
  {
    digitalWrite(led4,HIGH);
  }
  else
  {
    digitalWrite(led4,LOW);
  }
  if( distance <= 250 && distance >= 200 )
  {
    digitalWrite(led5,HIGH);
  }
  else
  {
    digitalWrite(led5,LOW);
  }
  if( distance <= 300 && distance >=250)
  {
    digitalWrite(led6,HIGH);
  }
  else
  {
    digitalWrite(led6,LOW);
  }
  delayMicroseconds(60);
}
