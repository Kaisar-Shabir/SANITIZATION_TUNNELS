#include <EEPROM.h>

int pinE = 3;
int pinD = 2;
int decimal = 4;
int pinC = 5;
int pinG = 6;
int D4 = 7;
int D1 = 8;
int pinA = 9;
int pinF = 10;
int D2 = 11;
int D3 = 12;
int pinB = 13;

int iCount = 0;
int ones = (iCount / 10) % 1;
int tens = (iCount / 100) % 10;
int hundreads = (iCount / 1000) % 100;
int thousands = (iCount / 10000) % 1000;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.

  Serial.begin(9600);
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
}

// the loop routine runs over and over again forever:
void loop() {
  fnIncrement();
  fnDisp();
  
}

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
  fnD4();
  fnNumber(EEPROM.read(0));
  delay(1);
  fnD3();
  fnNumber(EEPROM.read(1));
  delay(1);
  fnD2();
  fnNumber(EEPROM.read(2));
  delay(1);
  fnD1();
  fnNumber(EEPROM.read(3));
  delay(1);
}
