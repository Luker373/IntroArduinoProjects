int startLightVal = 0;
int currLightVal = 0;
int startBtn = 0;
int LEDflashDelay = 0;
bool shouldBuzz = 0, shouldWait = 0, shouldIdle = 1;

void setup() {
  // put your setup code here, to run once:
  startLightVal = analogRead(A0);
  pinMode(10, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  startBtn = digitalRead(10);
  if (startBtn == 1 && !shouldBuzz && !shouldWait){
      startTimer();
      shouldBuzz = 1;
      startBtn = digitalRead(10);
    }
  if (shouldBuzz && (currLightVal - startLightVal > 25 || startBtn == 1)){
    shouldBuzz = 0;
    noTone(8);
    digitalWrite(9, LOW);
    delay(200);
    startBtn = digitalRead(10);
    }
  if (shouldBuzz){
    tone(8, 300);
    flashLED();
    }else{
      noTone(8);
      }
}

void startTimer(){
  digitalWrite(9, HIGH);
  int timeToRest = 10000; // 10 seconds
  delay(timeToRest);
}

void flashLED(){
  if (LEDflashDelay <= 0){
    digitalWrite(9, !digitalRead(9));
    LEDflashDelay = 10;
  }else{
    LEDflashDelay--;
    }
  }
