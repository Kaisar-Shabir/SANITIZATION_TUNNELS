#define GND1 2
#define ECHO 3
#define TRIGGER 4
#define VCC1 5

#define IN1 6

#define GND2 8
#define ECHO2 9
#define TRIGGER2 10
#define VCC2 11

int flag;

void setup() {
  // put your setup code here, to run once:          
  
  pinMode(GND1, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(VCC1, OUTPUT);

  digitalWrite(GND1, LOW);
  digitalWrite(VCC1, HIGH);

  pinMode(IN1, OUTPUT);

  digitalWrite(IN1, HIGH);

  pinMode(GND2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIGGER2, OUTPUT);
  pinMode(VCC2, OUTPUT);

  digitalWrite(GND2, LOW);
  digitalWrite(VCC2, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int curDistanceEntry = fnCalcDistanceEntry();
  Serial.print("Current Entry Distance = ");
  Serial.println(curDistanceEntry);
  
  int curDistanceExit = fnCalcDistanceExit();
  Serial.print("Current Exit Distance = ");
  Serial.println(curDistanceExit);
  
  long maxDistance = 60;//fnGetDistance();


  if(curDistanceExit < maxDistance) {
    Serial.println("Exiting the office");
    while (fnCalcDistanceEntry() > maxDistance);
    Serial.println("Exitted the office");
    delay(1000);
  }
  if(curDistanceEntry < maxDistance) {
    Serial.println("Entering the office");
    digitalWrite(IN1, LOW);
    delay(3000);
//    fnGetDelayValue();
    digitalWrite(IN1, HIGH);
  }
  else if (curDistanceEntry > 400) {
    delay(2000);
  }
}

/*
long fnGetDistance() {
  int curValue = analogRead(POTENTIOMETER2);
  delay(60);
  int distance = map(curValue, 0, 1023, 0, 100);

  Serial.print("Max Duistance = ");
  Serial.println(distance);

  return distance;
}
*/

int fnCalcDistanceEntry() {
  digitalWrite(TRIGGER, LOW);
  delay(2);
  digitalWrite(TRIGGER, HIGH);
  delay(10);
  digitalWrite(TRIGGER, LOW);

  long d = pulseIn(ECHO, HIGH);
  int distance = d * 0.034 / 2;
  
  return distance;
}

int fnCalcDistanceExit() {
  digitalWrite(TRIGGER2, LOW);
  delay(2);
  digitalWrite(TRIGGER2, HIGH);
  delay(10);
  digitalWrite(TRIGGER2, LOW);

  long d = pulseIn(ECHO2, HIGH);
  int distance = d * 0.034 / 2;
  
  return distance;
}

/*
long fnGetDelayTime() {
  int curValue = analogRead(POTENTIOMETER);
  delay(60);
  int delayTime = map(curValue, 0, 1023, 0, 20000);

  Serial.print("Delay Time = ");
  Serial.println(delayTime);

  return delayTime;
}
*/
