//Connect GPIO
#define FC1 20 //IR Sensor Front Left
#define FC2 19 //IR Sensor Front Right
#define FC3 18 //IR Sensor Back
#define trigPin 9 // Acvtivate HC-SR04 Pin
#define echoPin 10 // HC-SR04 Receiver pin
//setup servo (if needed)
//Setup motor (if needed)


//Set state
int FR = 0; //Front Right IR Sensor
int FL = 0; //Front Left IR Sensor
int BW = 0; //Back IR Sensor
int block = 0; //HC-SR04 Sensor

//Store location
int targetX = 0;
int targetY = 0;
//Store distance
int distance = 0;
//For HC-SR04
#define BlockDistance 10 //Detect distance (cm)
#define Rotate 90 //Rotate when detect object (degrees)
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

  //Motor Setup (Need someone to code this)

}

void loop() {
  FR = digitalRead(FC1);
  FL = digitalRead(FC2);
  BW = digitalRead(FC3);
    distance = getDistance();
  if (distance < BlockDistance) 
  {
    block = 1;
  }
  else
  {block = 0;}
  if(FR == 1,FL == 1,block == 0)
  {
    //Vehicle run straight forward
  }
  else if (FR == 1,FL == 0,block == 0)
  {
    //Vehicle move slightly to the Right
  }
  else if (FR == 0,FL == 1,block == 0)
  {
    //Vehicle move slightly to the Left
  }
  else
  {
    //Vehicle stop
    //Servo turn backward
    if (BW == 1;block == 0)
    {
      //Vehicle backward 10 cm
      //Servo turn right to check if there are any block
      //if not then turn right,then:
      if (FR == 1)
      {
        //Vehicle run
      }
      else
      {
        //Reverse back to the last stop location
        //Servo turn left to check if there are any block
        //if not then turn left,then:
        if (FL == 1)
        {
          //Vehicle run
        }
        else
        {
          //Vehicle stop
          //print that:*Can't continue to drive.*
        }
      }
    }
    else
    {
      //print that:*Can't continue to drive.*
    }
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
