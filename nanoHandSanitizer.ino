#define GND1 2
#define ECHO 3
#define TRIGGER 4
#define VCC1 5

#define IN1 6

#define GND2 7
#define VCC2 8

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
  pinMode(VCC2, OUTPUT);
  
  digitalWrite(GND2, LOW);
  digitalWrite(VCC2, HIGH);

  delay(1000);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  fnDetect();

}

void fnDetect() {
  int curDistanceEntry = fnCalcDistanceEntry();
  Serial.print("Current Entry Distance = ");
  Serial.println(curDistanceEntry);

  long maxDistance = 15;

  if(curDistanceEntry < maxDistance) {
    Serial.println("Pouring sanitizer");
    digitalWrite(IN1, LOW);

    long delayVal = 100;
    unsigned long startTime = millis();
    digitalWrite(IN1, LOW);
    
    long curDis = fnCalcDistanceEntry();
    while((millis() - startTime) < delayVal) {
      if (fnCalcDistanceEntry() < maxDistance) {
        Serial.print(".");
        startTime = millis();
      }
    }
    Serial.println("");
    digitalWrite(IN1, HIGH);
  }
}

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
