//Connect GPIO
#define trigPin 9 // Chân kích hoạt cảm biến siêu âm (HC-SR04)
#define echoPin 10 // Chân nhận tín hiệu cảm biến siêu âm (HC-SR04)

//mấy cái motor méo đứa nào setup hết dzậy?????????


//Set state
int block = 0; //HC-SR04 Sensor

//Store location
int targetX = 0;
int targetY = 0;
//Store distance
int distance = 0;
//For HC-SR04
#define BlockDistance 10 //Detect distance (cm)
#define Rotate 90 //Rotate when detect object/abyss (degrees)
#define MAX_DISTANCE 250 //(cm)





void setup() {
  Serial.begin(115200);


  //HC-SR04 Setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Motor Setup (méo có motor dinhmenhdoi)

}

void loop() {

  //User input...toạ độ (méo biết từ toạ độ)
  Serial.print("Enter location X: ");
  while (!Serial.available()) ;
  targetX = Serial.parseInt();
  Serial.println();

  Serial.print("Enter location Y: ");
  while (!Serial.available()) ;
  targetY = Serial.parseInt();
  Serial.println();

  distance = getDistance();
  if (distance < BlockDistance) 
  {
    block = 1;
  }


}




// Calculating distance
float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  float duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343; // (cm)
  
  if (distance >= MAX_DISTANCE) {
    return MAX_DISTANCE;
  } else {
    return distance;
  }
}
