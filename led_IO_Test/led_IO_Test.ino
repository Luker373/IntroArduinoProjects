int reduceDelay = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(10, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(10)){
    blinkLED();
  }
}

void blinkLED() {
  do{
    digitalWrite(13, HIGH);
    delay(1000 - reduceDelay);
    digitalWrite(13, LOW);
    delay(1000 - reduceDelay);
    if (reduceDelay < 1000){
      reduceDelay += 50; 
    }else{
        reduceDelay = 0;
      }
  }while(reduceDelay != 0);
}
