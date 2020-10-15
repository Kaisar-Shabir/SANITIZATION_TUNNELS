#define GND1 2
#define ECHO 3
#define TRIGGER 4
#define VCC1 5

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

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
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int curDistanceEntry = fnCalcDistanceEntry();
  Serial.print("Current Entry Distance = ");
  Serial.println(curDistanceEntry);
  
  long maxDistance = 60;//fnGetDistance();

  if(curDistanceEntry < maxDistance) {
    Serial.println("Entering the office");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(3000);
//    fnGetDelayValue();
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
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
