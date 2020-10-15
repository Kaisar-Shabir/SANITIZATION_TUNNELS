void setup() {
  // put your setup code here, to run once:

  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);

  digitalWrite(2, HIGH);
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:

  int ir = analogRead(A0);
  Serial.println(ir);
  delay(1000);
}
