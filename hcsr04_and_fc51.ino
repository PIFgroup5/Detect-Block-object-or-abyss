//Connect GPIO
#define FC1 20 //IR Sensor Front
#define FC2 19 //IR Sensor Rear
#define FC3 18 //IR Sensor Right
#define trigPin 9 // Chân kích hoạt cảm biến siêu âm (HC-SR04)
#define echoPin 10 // Chân nhận tín hiệu cảm biến siêu âm (HC-SR04)

//mấy cái motor méo đứa nào setup hết dzậy?????????


//Set state
int FR = 0; //Front IR Sensor
int RR = 0; //Rear IR Sensor
int R = 0; //Right IR Sensor
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

  //FC-51 Setup
  pinMode(FC1,INPUT);
  pinMode(FC2,INPUT);
  pinMode(FC3,INPUT);

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

  FR = digitalRead(FC1);
  RR = digitalRead(FC2);
  R = digitalRead(FC3);
  if(FR == 1)
  {
    //Vehicle run (D gear)
  }
  else
  {
    //Vehicle stop
    if(RR==1)
    { 
      //Vehicle Run (R gear,backward 1m)
      if(R==1)
      {
        //Vehicle steering right
        if(FR == 1)
        {
          //Vehicle run
        }
      }
      else
      {
        //Vehicle steering left
        if(FR == 1)
        {
          //Vehicle run
        }
      }
    }
    else
    {
      //Vehicle stop
      //print("No road,cannot continue to run.")
    }
  }

  //HC-SR04 (Not done yet,still need some time to research.)
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
