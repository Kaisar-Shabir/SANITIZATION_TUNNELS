#define TRIGGER 3
#define ECHO 2
#define LAZER 6
#define MAXDISTANCE 40
#define VCC1 13
#define VCC2 11
#define VCC3 5
#define GND1 12
#define GND2 6
#define IN1 9
#define IN2 8

const int POTENTIOMETER = A1;


void setup() {
  // put your setup code here, to run once:
  
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(VCC1, OUTPUT);
  pinMode(GND1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(VCC2, OUTPUT);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(VCC1, HIGH);
  digitalWrite(VCC2, HIGH);
  digitalWrite(VCC3, HIGH);
  digitalWrite(GND1, LOW);
  digitalWrite(GND2, LOW);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int curDistance = fnCalcDistance();
  //int maxDistance = fnGetDistance();
  
  if (curDistance <= MAXDISTANCE) {
    //on the relay
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    
    delay(fnGetDelayTime());
    
    //off the relay
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
  }
}
/*
int fnGetDistance() {
  int value = analogRead(POTENTIOMETER2);
  Serial.print("Value P2: ");
  Serial.println(value);
  int maxDistance = map(value, 0, 1023, 0, 60);
  Serial.print("MAX DISTANCE: ");
  Serial.println(maxDistance);
  return maxDistance;
}
*/

int fnCalcDistance() {
  digitalWrite(TRIGGER, LOW);
  delay(2);
  digitalWrite(TRIGGER, HIGH);
  delay(10);
  digitalWrite(TRIGGER, LOW);

  long d = pulseIn(ECHO, HIGH);
  int distance = d * 0.034 / 2;

  Serial.print("Current Distance = ");
  Serial.println(distance);
  
  return distance;
}

long fnGetDelayTime() {
  int curValue = analogRead(POTENTIOMETER);
  delay(60);
  int delayTime = map(curValue, 0, 1023, 0, 20000);

  Serial.print("Delay Time = ");
  Serial.println(delayTime);

  if(delayTime == 20000) {
    delayTime = 3000;
  }
  return delayTime;
}
