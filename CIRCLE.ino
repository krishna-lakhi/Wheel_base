void stop_all_motors()
{
      digitalWrite(dir1, 0);
      analogWrite(pwm1, 0);
      digitalWrite(dir2, 0);
      analogWrite(pwm2, 0);
      digitalWrite(dir3, 0);
      analogWrite(pwm3, 0);
}
