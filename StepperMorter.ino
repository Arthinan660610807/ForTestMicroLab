
#define IN1 23
#define IN2 27
#define IN3 19
#define IN4 18
#define motorSpeed 2 //5.625°/64

void setup() {
 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
 clockWise();
}

void clockWise() {
  digitalWrite(IN4, HIGH);
  delay(motorSpeed);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  delay(motorSpeed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, HIGH);
  delay(motorSpeed);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  delay(motorSpeed);
  digitalWrite(IN1, LOW);
}
