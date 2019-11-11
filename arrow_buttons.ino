  void up()
  {
      Serial.println("UP");

      digitalWrite(dir1, 0);
      analogWrite(pwm1, spd);
      digitalWrite(dir2, 1);
      analogWrite(pwm2, spd);
      digitalWrite(dir3, 0);
      analogWrite(pwm3, 0);
  }

  void down()
  {
      Serial.println("DOWN");

      digitalWrite(dir1, 1);
      analogWrite(pwm1, spd);
      digitalWrite(dir2, 0);
      analogWrite(pwm2, spd);
      digitalWrite(dir3, 1);
      analogWrite(pwm3, 0);
  }

  void left()
  {
      Serial.println("LEFT");

      digitalWrite(dir1, 1);
      analogWrite(pwm1, (spd / 2));
      digitalWrite(dir2, 1);
      analogWrite(pwm2, (spd / 2));
      digitalWrite(dir3, 1);
      analogWrite(pwm3, (spd));
  }

  void right()
  {
      Serial.println("RIGHT");

      digitalWrite(dir1, 0);
      analogWrite(pwm1, (spd / 2));
      digitalWrite(dir2, 0);
      analogWrite(pwm2, (spd / 2));
      digitalWrite(dir3, 0);
      analogWrite(pwm3, (spd));
  }

  
