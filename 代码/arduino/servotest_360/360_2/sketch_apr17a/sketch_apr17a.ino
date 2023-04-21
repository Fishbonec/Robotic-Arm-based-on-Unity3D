#include <Servo.h>
#include <Arduino.h>

Servo myservo;  // 创建Servo对象
int pos = 0;
int mod = 0;
void setup() {
  myservo.attach(10);  // 将舵机连接到PIN 9
  Serial.begin(9600);
}

void loop() {
  // 向前转动
  if (Serial.available()) { // Check if there is any data in the serial buffer
     mod = Serial.parseInt(); // Read the input as a String object
   }
  if(mod == 1)
  {
    for (pos = 90; pos <= 180; pos += 1) {
      myservo.write(pos);     // 将当前位置写入servo
      delay(30);              // 等待15ms使舵机转到指定位置
    }
    Serial.println(mod);
    myservo.writeMicroseconds(1500);
  }
  else if (mod == 2)
  {
  // 向后转动
  for (pos = 90; pos >= 1; pos -= 1) {
    myservo.write(pos);     // 将当前位置写入servo
    delay(5);              // 等待15ms使舵机转到指定位置
  }
  Serial.println(mod);
  myservo.writeMicroseconds(1500);
  }

  
  
}