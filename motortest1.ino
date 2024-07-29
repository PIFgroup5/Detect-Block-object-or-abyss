#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 14
#define ENA 33
#define ENB 32

// control the motor speed with para PWM pin and dutyCycle
void motorSpeed(int PWM_pin,int dutyCycle){
  dutyCycle = constrain(dutyCycle, 50, 80);
  int point = (dutyCycle/100)*255;
  analogWriteResolution(PWM_pin, 8);
  analogWriteFrequency(PWM_pin, 2000);
  analogWrite(PWM_pin,point);
}
//control motor direction.
/*
Input: 
direction = 1: forward
direction = 0: stop
direction = -1: backward
*/
void motorDirection(int pin1,int pin2,int direction){
  direction = constrain(direction, -1, 1);
  switch (direction){
    case 1:
      digitalWrite(pin1, 1);
      digitalWrite(pin2, 0);
      break;
    case -1:
      digitalWrite(pin1, 0);
      digitalWrite(pin2, 1);
      break;
    default:
      digitalWrite(pin1, 0);
      digitalWrite(pin2, 0);
  }

}
void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 50;i<=80;i++){
    motorDirection(IN1,IN2,1);
    motorSpeed(ENA,i);
    motorDirection(IN3,IN4,1);
    motorSpeed(ENB,i);
    delay(5);
  }
  for (int i =80;i>=50;i++){
    motorDirection(IN1,IN2,-1);
    motorSpeed(ENA,i);
    motorDirection(IN3,IN4,-1);
    motorSpeed(ENB,i);
    delay(5);
  }
  motorDirection(IN1,IN2,0);
  motorDirection(IN3,IN4,0);
  delay(1000);
}
