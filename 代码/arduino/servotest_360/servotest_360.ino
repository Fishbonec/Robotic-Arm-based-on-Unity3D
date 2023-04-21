#include <Servo.h> // Include the Servo library
#include <Arduino.h>

Servo myservo; // Create a servo object

int pos = 0;

void setup() {
  myservo.attach(9); // Attach the servo to pin 9
  Serial.begin(9600); // Initialize the serial communication at 9600 baud rate
  
}

void loop() {
  
  if (Serial.available()) { // Check if there is any data in the serial buffer
     pos = Serial.parseInt(); // Read the input as a String object
   }
   
  if(pos == 0)
  {
    Serial.println(pos);
    myservo.writeMicroseconds(1500);      
  }
   
  if(pos>0)
  {
    Serial.println(pos);    
    myservo.write(180); 
    delay(pos*10);
    Serial.println(pos);
    myservo.write(90);
  }
  // 等待1秒钟
  delay(500);

  // 逆时针旋转180度
  if(pos<0)
  {
    Serial.println(pos);
    pos = -pos;    
    myservo.write(0); 
    delay(pos*10);      
    myservo.write(90);

  }
  delay(500);

  // if(pos>0)
  // {
  //   Serial.println(pos);
  //   for (int i = 0; i < pos; i++) 
  //   {
  //     //myservo.write(i);
  //     myservo.writeMicroseconds(1300);      
  //     Serial.println(i); 
  //     delay(150); // 控制旋转速度
  //   }
  //   Serial.println(pos);
  // } // 顺时针旋转
  
  // if(pos<0)
  // {
    
  //   for (int i = -pos; i > 0; i--) 
  //   {
  //     myservo.write(i);
  //     //myservo.writeMicroseconds(1500);
      
  //     Serial.println(pos);
  //     delay(100); // 控制旋转速度
  //   }
  // }
  // // 逆时针旋转
  // myservo.writeMicroseconds(1500);
  // // 等待1秒钟
  // delay(1000);
  
  // if(pos)
  // {
  //   Serial.println(pos);
  //   myservo.writeMicroseconds(1700);
    
  // }
  
  // //myservo.writeMicroseconds(1500);  // 设置中心位置（速度为0）
  // //delay(800);                      // 等待1秒
  // myservo.writeMicroseconds(-20);  // 设置反转方向
  // delay(800);                      // 等待1秒
  // //myservo.writeMicroseconds(2000);  // 设置正转方向
  // //delay(800);                      // 等待1秒
  // // delay(15);
}