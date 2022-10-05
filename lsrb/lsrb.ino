#include "aether_bot.h"

int l, s, r;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(IRS, INPUT);
  pinMode(IRR, INPUT);
  pinMode(IRL, INPUT);

  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while (status != 0) { }
  
  // Calculate MPU6050 offsets
  Serial.println(F("Calculating offsets..."));
  delay(500);
  mpu.calcOffsets();
}

void loop() {
  l = digitalRead(IRL);
  s = digitalRead(IRS);
  r = digitalRead(IRR);

  // LSRB algorithm
  if (l == LOW && s == HIGH && r == HIGH) // left
    left();

  if (l == HIGH && s == LOW && r == HIGH) // straight
    forward();

  if (l == HIGH && s == HIGH && r == LOW) // right
    right();

  if (l == LOW && s == HIGH && r == LOW) // T intersection
    left();

  if (l == LOW && s == LOW && r == HIGH) // left T intersection
    left();

  if (l == HIGH && s == LOW && r == LOW) // right T intersection
    forward();

  if (l == HIGH && s == HIGH && r == HIGH) // dead end
    u_turn();

  if (l == LOW && s == LOW && r == LOW) // end of maze
  {
     forward();
     delay(3000); // move forward for 3 seconds
     stop();

     if (l == LOW && s == LOW && r == LOW)
        stop();
        
     else
        left();
  }
}
