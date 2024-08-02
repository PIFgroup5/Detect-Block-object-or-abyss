//Connect GPIO
#define FC1 (GPIO) //IR Sensor Front Left - Replace (GPIO) with your GPIO Number
#define FC2 (GPIO) //IR Sensor Front Right - Replace (GPIO) with your GPIO Number
#define FC3 (GPIO) //IR Sensor Back - Replace (GPIO) with your GPIO Number
#define FC4 (GPIO) //IR Sensor Back Left-For Reverse - Replace (GPIO) with your GPIO Number
#define FC5 (GPIO) //IR Sensor Back Right-For Reverse - Replace (GPIO) with your GPIO Number
#define trigPin (GPIO) // Acvtivate HC-SR04 Pin - Replace (GPIO) with your GPIO Number
#define echoPin (GPIO) // HC-SR04 Receiver pin - Replace (GPIO) with your GPIO Number
//setup servo (if needed)
//Setup motor (if needed)


//Set state
int FR = 0; //Front Right IR Sensor
int FL = 0; //Front Left IR Sensor
int BW = 0; //Back IR Sensor
int RL = 0; //Reverse Left IR Sensor
int RR = 0; //Reverse Right IR Sensor
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
  pinMode(FC4,INPUT);
  pinMode(FC5,INPUT);
  //HC-SR04 Setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Motor Setup (Need someone to code this)

}

void loop() {
  FR = digitalRead(FC1);
  FL = digitalRead(FC2);
  BW = digitalRead(FC3);
  RL = digitalRead(FC4);
  RR = digitalRead(FC5);
    distance = getDistance();
  if (distance < BlockDistance) 
  {
    block = 1;
  }
  else
  {block = 0;}
  if(FR == 0 && FL == 0 && block == 0)
  {
    //Vehicle run straight forward
  }
  else if (FR == 0 && FL == 1 && block == 0)
  {
    //Vehicle move slightly to the Right
  }
  else if (FR == 1 && FL == 0 && block == 0)
  {
    //Vehicle move slightly to the Left
  }
  else
  {
    //Vehicle stop
    if (BW == 0 && RL == 0 && RR == 0)
    {
      //Vehicle backward 10 cm
      //Servo turn right to check if there are any block
      //if not then turn right,then:
      if (FR == 0)
      {
        //Vehicle run
      }
      else
      {
        //Reverse back to the last stop location
        //Servo turn left to check if there are any block
        //if not then turn left,then:
        if (FL == 0)
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
