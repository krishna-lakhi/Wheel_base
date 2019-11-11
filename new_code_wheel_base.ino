#include <SoftwareSerial.h>
#include<math.h>
/*
  Example sketch for the PS4 Bluetooth library - developed by Kristian Lauszus
  For more information visit my blog: http://blog.tkjelectronics.dk/ or
  send me an e-mail:  kristianl@tkjelectronics.com
*/

#include <PS4USB.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;

PS4USB PS4(&Usb);

#define dir1 26
#define pwm1 7
#define dir2 24
#define pwm2 6
#define dir3 5
#define pwm3 4
#define dir4 30
#define pwm4 11
#define minspd 0
#define maxspd 255

int spd = 90; //default speed for arrow buttons
int spd_arm=120; //default speed for speed of arm connected to piston
int spd_joystick = 120; //default speed for left joystick
int s1, s2, s3;
int d1, d2, d3;
int dr2 = 0;
int du2 = 1;

int spd2 = 140;
double ang;
//default speed for joystick left
int lhx, lhy, rhx, rhy;

void setup() {

  Serial.begin(9600);
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); // Halt
  }

  pinMode(dir1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  
  pinMode(dir2, OUTPUT);
  pinMode(pwm2, OUTPUT);
  
  pinMode(dir3, OUTPUT);
  pinMode(pwm3, OUTPUT);

  pinMode(dir4, OUTPUT);
  pinMode(pwm4, OUTPUT);

}

void loop()
{
  spd = constrain(spd, 0, 255); //speed limits

  //map lefthatx and lefthaty according to 4 quadrants
  lhx = map(PS4.getAnalogHat(LeftHatX), 0, 255, -128, 127);
  lhy = map(PS4.getAnalogHat(LeftHatY), 0, 255, 127, -128);
  //Serial.println("LHX : " + String(lhx)+"LHY : "+String(lhy));
  Usb.Task();
  
  

  if (PS4.connected())
  {
    if (PS4.getButtonPress(UP))
    {
     void up();
    }

    else if (PS4.getButtonPress(DOWN))
    {
      void down();
    }

    else if (PS4.getButtonPress(LEFT))
    {
      void left();
    }

    else if (PS4.getButtonPress(RIGHT))
    {
      void right();
    }

    else if (PS4.getButtonPress(L1))
    {
     void anticlockwise();
    }

    else if (PS4.getButtonPress(R1))
    {
      void clockwise();
    }


    else if (PS4.getButtonPress(L2))
    {
      void arm_anticlockwise(spd_arm);
    }
    
    else if (PS4.getButtonPress(R2))
    {
      void arm_clockwise(spd_arm);
    }
    else if (PS4.getButtonClick(TRIANGLE))
    {
      void increase_speed();
    }

    else if (PS4.getButtonClick(CROSS))
    {
     void decrease_speed();
    }


    else if (PS4.getButtonPress  (CIRCLE))
    {
      void stop_all_motors();
    }

    else if ((lhx <= -7 || lhx >= 7) && (lhy <= -7 || lhy >= 7))
    {
      Serial.println("Joystick");
      ang = atan2(lhy, lhx);
      ang = ang * 180 / 3.141;
      if (ang < 0)
      {
        ang = map(ang, -179, -1, 181, 359);
      }
      Serial.print(ang);
      

      if (ang >= 15 && ang <= 30)
      {
        //sector1 Right
        Serial.println("sector 1");
        

        spd_joystick = map(lhy, 0, 127, 200, 60);
        digitalWrite(dir1, 0);
        analogWrite(pwm1, (spd_joystick / 2));
        digitalWrite(dir2, 0);
        analogWrite(pwm2, (spd_joystick / 2));
        digitalWrite(dir3, 0);
        analogWrite(pwm3, (spd_joystick));

      }
      else if (ang > 30 && ang <= 60)
      {
        Serial.println("sector 2");
        
        //sector 2 north east
        spd_joystick = map(lhy, 0, 127, 200, 60);
        digitalWrite(dir1, 0);
        analogWrite(pwm1, (spd_joystick / 2));
        digitalWrite(dir2, 0);
        analogWrite(pwm2, 0);
        digitalWrite(dir3, 0);
        analogWrite(pwm3, (spd_joystick));


      }


      else if (ang > 60 && ang <= 90)
      {
        Serial.println("sector 3");
        
        //sector 3 UP-RIGHT
        spd_joystick = map(lhy, 0, 127, 200, 60);
        digitalWrite(dir1, 0);
        analogWrite(pwm1, (spd_joystick));
        digitalWrite(dir2, 1);
        analogWrite(pwm2, spd_joystick);
        digitalWrite(dir3, 0);
        analogWrite(pwm3, 0);


      }

      else if (ang > 90 && ang <= 120)
      {
        Serial.println("sector 4");
        
        //sector 4 UP-LEFT
        spd_joystick = map(lhy, 0, 127, 200, 60);
        digitalWrite(dir1, 0);
        analogWrite(pwm1, (spd_joystick));
        digitalWrite(dir2, 1);
        analogWrite(pwm2, spd_joystick);
        digitalWrite(dir3, 0);
        analogWrite(pwm3, 0);

      }
      else if (ang > 120 && ang <= 150)
      {
        Serial.println("sector 5");
        
        //sector 5 n north west
        spd_joystick = map(lhy, 0, 127, 200, 60);
        digitalWrite(dir1, 0);
        analogWrite(pwm1, 0);
        digitalWrite(dir2, 1);
        analogWrite(pwm2, spd_joystick);
        digitalWrite(dir3, 1);
        analogWrite(pwm3, spd_joystick);

      }
      else if (ang > 150 && ang <= 180)
      {
        //sector 6 left
        Serial.println("sector 6");
        
        spd_joystick = map(lhy, 0, 127, 200, 60);
        digitalWrite(dir1, 1);
        analogWrite(pwm1, spd_joystick / 2);
        digitalWrite(dir2, 1);
        analogWrite(pwm2, spd_joystick / 2);
        digitalWrite(dir3, 1);
        analogWrite(pwm3, spd_joystick);

      }

    


      else if(ang>180 && ang<=210)
      {
        Serial.println("sector 7");
        
        //sector 7 left down
        spd_joystick = map(lhy, 0, -128, 200, 60);
        digitalWrite(dir1, 1);
        analogWrite(pwm1, spd_joystick / 2);
        digitalWrite(dir2, 1);
        analogWrite(pwm2, spd_joystick / 2);
        digitalWrite(dir3, 1);
        analogWrite(pwm3, spd_joystick);

      }
     else if(ang>210 && ang<=240)
      {
        Serial.println("sector 8");
        
        //sector 8  South west
 spd_joystick = map(lhy, 0, -128, 200, 60);
        digitalWrite(dir1, 1);
        analogWrite(pwm1, (spd_joystick / 2));
        digitalWrite(dir2, 0);
        analogWrite(pwm2, 0);
        digitalWrite(dir3, 1);
        analogWrite(pwm3, (spd_joystick));

      }
      else if(ang>240 && ang<=270)
      {
        Serial.println("sector 9");
        
        //sector 9 down
    spd_joystick = map(lhy, 0, -128, 200, 60);
        digitalWrite(dir1, 1);
        analogWrite(pwm1, spd_joystick);
        digitalWrite(dir2, 0);
        analogWrite(pwm2, spd_joystick);
        digitalWrite(dir3, 1);
        analogWrite(pwm3, 0);


      }
      else if(ang>270 && ang<=300)
      {
        Serial.println("sector 10");
        
        //sector 10 down right

  spd_joystick = map(lhy,-128,0, 200, 60);
        digitalWrite(dir1, 1);
        analogWrite(pwm1, spd_joystick);
        digitalWrite(dir2, 0);
        analogWrite(pwm2, spd_joystick);
        digitalWrite(dir3, 1);
        analogWrite(pwm3, 0);
      
      }
      
      else if(ang>300 && ang<=330)
      {
        //sector 11
        Serial.println("sector 11");
        
        
        spd_joystick = map(lhy,-128,0, 200, 60);
        digitalWrite(dir1, 1);
        analogWrite(pwm1, 0);
        digitalWrite(dir2, 0);
        analogWrite(pwm2, spd_joystick);
        digitalWrite(dir3, 1);
        analogWrite(pwm3, spd_joystick);
      


      }
      else if(ang>330 && ang<=360)
      {
        Serial.println("sector 12");
        
        //sector 12 n north west
         spd_joystick = map(lhy,-128,0, 200, 60);
      digitalWrite(dir1,0);
      analogWrite(pwm1,(spd_joystick/2));
      digitalWrite(dir2,0);
      analogWrite(pwm2,(spd_joystick/2));
      digitalWrite(dir3,0);
      analogWrite(pwm3,(spd_joystick));

      }
    }
    

    else
    {
      void bot_idle();

    }
  }











}
