void bot_idle()
{
      Serial.println("stop");
      digitalWrite(dir1, 1);
      analogWrite(pwm1, 0);
      digitalWrite(dir2, 0);
      analogWrite(pwm2, 0);
      digitalWrite(dir3, 1);
      analogWrite(pwm3, 0);
      digitalWrite(dir4, 1);
      analogWrite(pwm4, 0);
}
