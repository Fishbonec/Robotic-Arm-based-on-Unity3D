void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int num1 = Serial.parseInt();
    int num2 = Serial.parseInt();
    int num3 = Serial.parseInt();
    int num4 = Serial.parseInt();

    Serial.print("num1: ");
    Serial.println(num1);
    Serial.print("num2: ");
    Serial.println(num2);
    Serial.print("num3: ");
    Serial.println(num3);
    Serial.print("num4: ");
    Serial.println(num4);
  }
}
