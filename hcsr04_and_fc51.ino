//Connect GPIO
#define FC1 20 //IR Sensor Front
#define trigPin 9 // Acvtivate HC-SR04 Pin
#define echoPin 10 // HC-SR04 Receiver pin
//setup servo (if needed)
//Setup motor (if needed)


//Set state
int FR = 0; //Front IR Sensor
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
  //HC-SR04 Setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Motor Setup (Need someone to code this)

}

void loop() {
  FR = digitalRead(FC1);
    distance = getDistance();
  if (distance < BlockDistance) 
  {
    block = 1;
  }
  else
  {block = 0;}
  if(FR == 1,block == 0)
  {
    //Vehicle run (D gear)
  }
  else
  {
    //Vehicle Stop
    //Vehicle reverse (10 cm)
    //Servo check to see if Left or right empty
    //Vehicle Rotate 
    //Vehicle Run
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
