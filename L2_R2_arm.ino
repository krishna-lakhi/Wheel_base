void arm_anticlockwise(int spd_arm)
  {
      digitalWrite(dir4, 0);
      analogWrite(pwm4, spd_arm);
      Serial.println("piston arm anticlockwise");
  }
  
  void arm_clockwise(int spd_arm)
  {
      digitalWrite(dir4, 1);
      analogWrite(pwm4, spd_arm);
      Serial.println("piston arm clockwise");
  }
  
