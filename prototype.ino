#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int receiver1 = A0;
int value1 = 0;
int receiver2 = A1;
int value2 = 0;
int receiver3 = A2;
int value3 = 0;

int right_initial;
int left_initial;
int front_initial;
int common_pos;
int lin_servo_pos;
int period;
int minwait = 128;

void setup() {
  // put your setup code here, to run once:
  delay(4000);
  value1 = analogRead(receiver1);
  value2 = analogRead(receiver2);
  value3 = analogRead(receiver3);
  
  right_initial = value1 - 200;
  left_initial = value2 - 200;
  front_initial = value3 - 200;
  
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  
  lin_servo_pos = 100;
  servo5.write(lin_servo_pos);
  delay(4000);
  origin();
  delay(4000);
}


void loop() {
  // put your main code here, to run repeatedly:
  period = 12;
  continuous(12);
  period = 40;
  halfturn_left();
  period = 40;
  intermittent(24);
  period = 40;
  halfturn_right();
  period = 14;
  continuous(8);
  period = 38;
  intermittent(48);
  period = 12;
  continuous(10);
  balance(80, 4, 36);
  period = 40;
  intermittent(32);
  balance(40, 4, 34);
  period = 14;
  continuous(16);
  balance(100, 2, 34);
  period = 38;
  intermittent(48);
  balance(120, 4, 38);
  period = 10;
  continuous(4);
  balance(180, 8, 32);
}


void detect(){
  int original;
  value1 = analogRead(receiver1);
  value2 = analogRead(receiver2);
  value3 = analogRead(receiver3);

  if (value2 < front_initial){
    if (value1 > value3){
      origin();
      original = period;
      period = 40;
      fullturn_right();
      period = original;
    }
    else {
      original = period;
      period = 40;
      fullturn_left();
      period = original;
    }
  }
  else if (value1 < right_initial){
    origin();
    original = period;
    period = 40;
    halfturn_left();
    period = original;
  }
  else if (value3 < left_initial){
    origin();
    original = period;
    period = 40;
    halfturn_right();
    period = original;
  }
    
}


void halfturn_left(){
  int pos = 140; /////////////////////////////////
  servo1.write(pos);
  delay(period);
  servo2.write(pos);
  delay(period);
  servo3.write(pos);
  delay(period);
  servo4.write(pos);
  delay(minwait);
  pos = 90; ///////////////
  servo1.write(pos);
  delay(period);
  servo2.write(pos);
  delay(period);
  servo3.write(pos);
  delay(period);
  servo4.write(pos);
  delay(minwait - 32);
}


void halfturn_right(){
  int pos = 40; /////////////////////////////////
  servo1.write(pos);
  delay(period);
  servo2.write(pos);
  delay(period);
  servo3.write(pos);
  delay(period);
  servo4.write(pos);
  delay(minwait);
  pos = 90; ///////////////
  servo1.write(pos);
  delay(period);
  servo2.write(pos);
  delay(period);
  servo3.write(pos);
  delay(period);
  servo4.write(pos);
  delay(minwait - 32);
}


void fullturn_left(){
  int pos = 140; /////////////////////////////////
  servo1.write(pos);
  delay(period);
  servo2.write(pos);
  delay(period);
  servo3.write(pos);
  delay(period);
  servo4.write(pos);
  delay(minwait);
  pos = 110; ///////////////
  servo1.write(pos);
  delay(period);
  servo2.write(pos);
  delay(period);
  servo3.write(pos);
  delay(period);
  servo4.write(pos);
  delay(minwait - 32);
  pos = 140; //*****************************
  servo1.write(pos);
  delay(period);
  servo2.write(pos);
  delay(period);
  servo3.write(pos);
  delay(period);
  servo4.write(pos);
  delay(minwait);
  pos = 90; //****************
  servo1.write(pos);
  delay(period);
  servo2.write(pos);
  delay(period);
  servo3.write(pos);
  delay(period);
  servo4.write(pos);
}


void fullturn_right(){
  int pos = 45; /////////////////////////////////
  servo1.write(pos);
  delay(period);
  servo2.write(pos);
  delay(period);
  servo3.write(pos);
  delay(period);
  servo4.write(pos);
  delay(minwait);
  pos = 80; ///////////////
  servo1.write(pos);
  delay(period);
  servo2.write(pos);
  delay(period);
  servo3.write(pos);
  delay(period);
  servo4.write(pos);
  delay(minwait);
  pos = 45; //*****************************
  servo1.write(pos);
  delay(period);
  servo2.write(pos);
  delay(period);
  servo3.write(pos);
  delay(period);
  servo4.write(pos);
  delay(minwait);
  pos = 90; //****************
  servo1.write(pos);
  delay(period);
  servo2.write(pos);
  delay(period);
  servo3.write(pos);
  delay(period);
  servo4.write(pos);
}


void continuous(int duration){
  int threshold = 0;
  int cycle = 8;
  while (duration != 0){
    duration -= 1;
    if (period == 6){
      if (threshold == cycle + 8){
        period += 1;
        threshold = 0;
      }
    }
    if (period == 10){
      if (threshold == cycle){
        period -= 1;
        threshold = 0;
      }
    }
    servo1.write(100); // 111111 //////////////////////////
    delay(period);
    servo2.write(60); // 222222
    delay(period);
    servo3.write(130); // 33333
    delay(period);
    servo4.write(155); // 44444
    delay(period);
    servo1.write(104); // 111111 ////////
    delay(period);
    servo2.write(68); // 222222
    delay(period);
    servo3.write(110); // 33333
    delay(period);
    servo4.write(148); // 44444
    delay(period);
    servo1.write(108); // 111111 ////////
    delay(period);
    servo2.write(76); // 222222
    delay(period);
    servo3.write(90); // 33333
    delay(period);
    servo4.write(140); // 44444
    delay(period);
    servo1.write(112); // 111111 ////////
    delay(period);
    servo2.write(84); // 222222
    delay(period);
    servo3.write(70); // 33333
    delay(period);
    servo4.write(133); // 44444
    delay(period);
    detect();
    servo1.write(114); // 111111 ////////////////////////////
    delay(period);
    servo2.write(90); // 222222
    delay(period); 
    servo3.write(50); // 33333
    delay(period);
    servo4.write(125); // 44444
    delay(period);
    servo1.write(110); // 111111 ////////
    delay(period);
    servo2.write(98); // 222222
    delay(period);
    servo3.write(52); // 33333
    delay(period);
    servo4.write(105); // 44444
    delay(period);
    servo1.write(102); // 111111 ////////
    delay(period);
    servo2.write(106); // 222222
    delay(period);
    servo3.write(55); // 33333
    delay(period);
    servo4.write(85); // 44444
    delay(period);
    servo1.write(96); // 111111 ////////
    delay(period);
    servo2.write(114); // 222222
    delay(period);
    servo3.write(58); // 33333
    delay(period);
    servo4.write(65); // 44444
    delay(period);
    detect();
    servo1.write(88); // 111111 /////////////////////////////
    delay(period);
    servo2.write(120); // 222222
    delay(period);
    servo3.write(60); // 33333
    delay(period);
    servo4.write(45); // 44444
    delay(period);
    servo1.write(84); // 111111 ////////
    delay(period);
    servo2.write(120); // 222222
    delay(period);
    servo3.write(82); // 33333
    delay(period);
    servo4.write(49); // 44444
    delay(period);
    servo1.write(80); // 111111 ////////
    delay(period);
    servo2.write(110); // 222222
    delay(period);
    servo3.write(105); // 33333
    delay(period);
    servo4.write(53); // 44444
    delay(period);
    servo1.write(75); // 111111 ////////
    delay(period);
    servo2.write(100); // 222222
    delay(period);
    servo3.write(124); // 33333
    delay(period);
    servo4.write(57); // 44444
    delay(period);
    detect();
    servo1.write(70); // 111111 /////////////////////////////////
    delay(period);
    servo2.write(90); // 222222
    delay(period);
    servo3.write(145); // 33333
    delay(period);
    servo4.write(60); // 44444
    delay(period);
    servo1.write(77); // 111111 ////////
    delay(period);
    servo2.write(84); // 222222
    delay(period);
    servo3.write(142); // 33333
    delay(period);
    servo4.write(85); // 44444
    delay(period);
    servo1.write(85); // 111111 ////////
    delay(period);
    servo2.write(76); // 222222
    delay(period);
    servo3.write(137); // 33333
    delay(period);
    servo4.write(110); // 44444
    delay(period);
    servo1.write(92); // 111111 ////////
    delay(period);
    servo2.write(68); // 222222
    delay(period);
    servo3.write(134); // 33333
    delay(period);
    servo4.write(132); // 44444
    delay(period);
    detect();
  }
}


void intermittent(int duration){
  int runs = 0;
  int original = period;
  while (duration != 0){
    duration -= 1;
    runs += 1;
    period -= 1;
    if (runs > 8){
      origin();
      delay (400);
      period = 20;
      continuous(3);
      period = 18;
      continuous(2);
      origin();
      delay(200);
      period = 12;
      continuous(6);
      origin();
      delay(600);
      period = 20;
      continuous(4);
      period = 14;
      continuous(4);
      period = 16;
      continuous(4);
      period = 18;
      continuous(4);
      period = 20;
      runs = 0;
      period = original;
    }
    servo1.write(110);
    delay(period);
    servo2.write(60);
    delay(period);
    servo3.write(130);
    delay(period);
    servo4.write(155);
    delay(period);
    servo1.write(125);
    delay(period);
    servo2.write(90);
    delay(period);
    servo3.write(50);
    delay(period);
    servo4.write(125);
    delay(period);
    servo1.write(70);
    delay(period);
    servo2.write(130);
    delay(period);
    servo3.write(60);
    delay(period);
    servo4.write(45);
    delay(period);
    servo1.write(60);
    delay(period);
    servo2.write(90);
    delay(period);
    servo3.write(145);
    delay(period);
    servo4.write(60);
    delay(period);
    detect();
  }
}


void balance(int angle, int delta, int per){
  servo5.write(angle);
  delay(100);
  servo5.write(angle);
  while (delta != 0){
    delta -= 1;
    servo1.write(110);
    delay(per);
    servo2.write(60);
    delay(per);
    servo3.write(130);
    delay(per);
    servo4.write(155);
    delay(per);
    servo1.write(125);
    delay(per);
    servo2.write(90);
    delay(per);
    servo3.write(50);
    delay(per);
    servo4.write(125);
    delay(per);
    servo1.write(70);
    delay(per);
    servo2.write(130);
    delay(per);
    servo3.write(60);
    delay(per);
    servo4.write(45);
    delay(per);
    servo1.write(60);
    delay(per);
    servo2.write(90);
    delay(per);
    servo3.write(145);
    delay(per);
    servo4.write(60);
    delay(per);
  }
  servo5.write(100);
  delay(100);
  servo5.write(100);
}


void reset_pos(){
  /*value6 = analogRead(receiver6);
  while (value6 > 420 || value6 < 380){
    value6 = analogRead(receiver6);
    if (value6 > 420){
      delay(100);
      if (value6 > 420){
        lin_servo_pos += 10;
        servo5.write(lin_servo_pos);
      }
    }
    if (value6 < 380){
      delay(100);
      if (value6 < 380){
        lin_servo_pos -= 10;
        servo5.write(lin_servo_pos);
      }
    }
    delay(1000);
  }*/
  servo5.write(100);
  common_pos = 90;
  servo1.write(common_pos);
  servo2.write(common_pos);
  servo3.write(common_pos);
  servo4.write(common_pos);
}

void origin(){
  common_pos = 90;
  servo1.write(common_pos);
  servo2.write(common_pos);
  servo3.write(common_pos);
  servo4.write(common_pos);
}
