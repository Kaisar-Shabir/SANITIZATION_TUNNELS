#define TRIGGER 3
#define ECHO 2
#define MAXDISTANCE 40
#define VCC1 13
#define VCC2 11
#define VCC3 5
#define GND1 12
#define GND2 6
#define IN1 9
#define IN2 8

const int POTENTIOMETER = A1;
const int POTENTIOMETER2 = A2;


void setup() {
  // put your setup code here, to run once:         
  
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(VCC1, OUTPUT);
  pinMode(VCC2, OUTPUT);
  pinMode(VCC3, OUTPUT);
  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(VCC1, HIGH);
  digitalWrite(VCC2, HIGH);
  digitalWrite(VCC3, HIGH);
  digitalWrite(GND1, LOW);
  digitalWrite(GND2, LOW);

  delay(1000);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int curDistance = fnCalcDistance();
  Serial.print("Current Distance = ");
  Serial.println(curDistance);
  
  long maxDistance = fnGetDistance();
  
  if (curDistance < maxDistance) {
    //on the relay
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
 
    long delayVal =  fnGetDelayTime();
    Serial.print("Delay Time = ");
    Serial.println(delayVal);
    
    unsigned long startTime = millis();
    while((millis() - startTime) < delayVal) {
      if (fnCalcDistance() < maxDistance) {
        Serial.println("New person entered");
        startTime = millis();
      }
    }
    
    //off the relay
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
  }
  delay(60);
}

long fnGetDistance() {
  int curValue = analogRead(POTENTIOMETER2);
  delay(60);
  int distance = map(curValue, 0, 1023, 10, 100);

  Serial.print("Max Duistance = ");
  Serial.println(distance);

  return distance;
}

int fnCalcDistance() {
  digitalWrite(TRIGGER, LOW);
  delay(2);
  digitalWrite(TRIGGER, HIGH);
  delay(10);
  digitalWrite(TRIGGER, LOW);

  long d = pulseIn(ECHO, HIGH);
  int distance = d * 0.034 / 2;
  
  return distance;
}

long fnGetDelayTime() {
  int curValue = analogRead(POTENTIOMETER);
  delay(60);
  int delayTime = map(curValue, 0, 1023, 1500, 20000);

  return delayTime;
}
