boolean switchp=false;
boolean ledon=LOW;
boolean currentbutton=false;
void setup(){
  pinMode(2, INPUT);
  pinMode(10, OUTPUT);
}
boolean debounce(boolean(last)){
  boolean current=digitalRead(2);
  if(last!=current){
    delay(5);
    current=digitalRead(2);
    return(current);
  }
}
void loop(){
  currentbutton=debounce(switchp);
  if(switchp==false && currentbutton==true){
    ledon=!ledon;
  }
  switchp=currentbutton;
  digitalWrite(10,ledon);
}
