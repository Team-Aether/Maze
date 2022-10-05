#include "aether_bot.h"

void forward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void reverse()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void u_turn()
{
  float turn_angle = 0.0;
  
  while (abs(turn_angle) < 180) {
    Serial.print("Turning...");
    Serial.print(turn_angle);
    Serial.println(" Degrees");
    
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  
    analogWrite(ENA, 40);
    analogWrite(ENB, 70);

    mpu.update();
    turn_angle = mpu.getAngleZ();
  } 
}

void left()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);  
}
