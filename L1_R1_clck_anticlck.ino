  void anticlockwise()
  {
      Serial.println("anticlockwise"); 
      digitalWrite(dir1, 1);
      analogWrite(pwm1, (spd / 2));
      digitalWrite(dir2, 1);
      analogWrite(pwm2, (spd / 2));
      digitalWrite(dir3, 0);
      analogWrite(pwm3, (spd / 2));
  }
  
  void clockwise()
  {
      Serial.println("clockwise");
      digitalWrite(dir1, 0);
      analogWrite(pwm1, (spd / 2));
      digitalWrite(dir2, 0);
      analogWrite(pwm2, (spd / 2));
      digitalWrite(dir3, 1);
      analogWrite(pwm3, (spd / 2));
  }

  
