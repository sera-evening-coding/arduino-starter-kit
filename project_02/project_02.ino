int switchState = 0;

void setup() {
  pinMode(3,OUTPUT); //Greem
  pinMode(4,OUTPUT); //Red
  pinMode(5,OUTPUT); //Red
  
  pinMode(2,INPUT);

}

void loop() {
  switchState = digitalRead(2); //Reads the voltage level on the digital input.
  
  if (switchState == LOW) {
    //button not pressed
    
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  } else {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    
    delay(250);
    
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    
    delay(250);
  }
  
}
