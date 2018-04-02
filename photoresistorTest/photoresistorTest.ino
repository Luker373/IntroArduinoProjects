void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogVal = analogRead(A0);
  Serial.println(analogVal);
  blinkLed(analogVal);
}

void blinkLed(int blnkRate){
  // blink LED based on the value of the photoresistor
  digitalWrite(8, HIGH);
  delay(600 - blnkRate);
  digitalWrite(8, LOW);
  delay(600 - blnkRate);  
}
