#include <EEPROM.h>

#define GND1 2
#define ECHO 3
#define TRIGGER 4
#define VCC1 5

#define IN1 6
#define IN2 7

#define pinE 8
#define pinD 9
#define decimal 10
#define pinC 11
#define pinG 12
#define D4 13
#define D1 14
#define pinA 15
#define pinF 16
#define D2 17
#define D3 18
#define pinB 19

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

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);

  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);
  pinMode(decimal, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

 // while(1)
  fnDisp();
  
  //fnDetect();
  fnNewDetect();
}

void fnNewDetect() {
  int curDistanceEntry = fnCalcDistanceEntry();
  Serial.print("Current Entry Distance = ");
  Serial.println(curDistanceEntry);

//  long maxDistance = fnGetDistance();
  long maxDistance = 60;

  if(curDistanceEntry < maxDistance) {
    fnIncrement();
    fnDisplayJunk();

    Serial.println("Entering the office");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
//    long delayVal = fnGetDelayValue() - 100;
    long delayVal = 3000;

    unsigned long startTime = millis();
    while((millis() - startTime) < delayVal) {
      fnDispIn();
      if (fnCalcDistanceEntry() < maxDistance) {
        Serial.println("New person entered");
        startTime = millis();
      }
    }

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
  }
}

void fnDetect() {
  int curDistanceEntry = fnCalcDistanceEntry();
  Serial.print("Current Entry Distance = ");
  Serial.println(curDistanceEntry);
  
  long maxDistance = 60;//fnGetDistance();

  if(curDistanceEntry < maxDistance) {
    fnIncrement();
    fnDisplayJunk();
    Serial.println("Entering the office");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    delay(3000);
//    fnGetDelayValue();
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
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
void ZERO() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
}

void ONE() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
}

void TWO() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
}

void THREE() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
}

void FOUR() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}

void FIVE() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}

void SIX() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}

void SEVEN() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
}

void EIGHT() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}

void NINE() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}

void fnD1() {
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}

void fnD2() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}

void fnD3() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
}

void fnD4() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
}

void fnNumber(int num) {
  switch(num) {
    case 0:
      ZERO();
      break;
    case 1:
      ONE();
      break;
    case 2:
      TWO();
      break;
    case 3:
      THREE();
      break;
    case 4:
      FOUR();
      break;
    case 5:
      FIVE();
      break;
    case 6:
      SIX();
      break;
    case 7:
      SEVEN();
      break;
    case 8:
      EIGHT();
      break;
    case 9:
      NINE();
      break;
  }  
}

void fnDisp() {  
  fnD1();
  fnNumber(EEPROM.read(3));
  delay(1);
  
  fnD2();
  fnNumber(EEPROM.read(2));
  delay(1);

  fnD3();
  fnNumber(EEPROM.read(1));
  delay(1);

  fnD4();
  fnNumber(EEPROM.read(0));
  delay(1);
}

void fnDisplayJunk() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);

}

void fnDispIn() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);

  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);

  delay(1);

  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);

  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);

  delay(1);
  
}

void fnIncrement() {
  EEPROM.update(0, EEPROM.read(0) + 1);
  if (EEPROM.read(0) == 10) {
    EEPROM.update(0, 0);
    EEPROM.update(1, EEPROM.read(1) + 1);
    if (EEPROM.read(1) == 10) {
      EEPROM.update(1, 0);
      EEPROM.update(2, EEPROM.read(2) + 1);
      if (EEPROM.read(2) == 10) {
        EEPROM.update(2, 0);
        EEPROM.update(3, EEPROM.read(3) + 1);
        if (EEPROM.read(3) == 10) {
          EEPROM.update(3, 0);
        }
      }
    }
  }

  EEPROM.update(4, EEPROM.read(4) + 1);
}
