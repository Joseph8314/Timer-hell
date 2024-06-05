#include <AsyncDelay.h>

AsyncDelay delay_r1;
AsyncDelay delay_r2;
AsyncDelay delay_r3;
AsyncDelay delay_r4;
AsyncDelay delay_r5;
AsyncDelay delay_r6;
AsyncDelay delay_net;
int objective = 0;
volatile bool button_flag = 0;
int check;
bool button = 0;
bool primer = 1;
int timers = 1;
int count = 0;
int success = 0;
int r1_var;
int p1_var;
int r2_var;
int p2_var;
int r3_var;
int p3_var;
int r4_var;
int p4_var;
int r5_var;
int p5_var;
int r6_var;
int p6_var;
int score = 1;
int strikes = 0;
void setup(void) {
  Serial.begin(9600);
  pinMode(5, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(5), Input, LOW);
}

void loop(void) {
  if (strikes <= 3) {
    if (score = 1) {
      Serial.print("round_1");
      delay(100);
      round_1();
    }
    if (score = 2) {
      Serial.print("round_2");
      delay(100);
      round_2();
    }
    if (score = 3) {
      Serial.print("round_3");
      delay(100);
      round_3();
    }
    delay(500);
    // score anylsis
    if (success == timers) {
      score++;
      //major success noise
    } else {
      strikes++;
      //disapointing noises
    }
  } else {
    delay(100);
    Serial.print("you lose: your score was ");
    Serial.println(score);
  }
  success = 0;
  //if (primer)
  //{
  //primer = 0;
  //r_var = random(100, 1000);
  //delay_rs.start(r_var, AsyncDelay::MILLIS);

  //}

  //if (delay_rs.isExpired()) {
  //Serial.print("3s delay millis=");
  //Serial.println(millis());
  //r_var = random(100, 1000);
  //delay_rs.repeat(); // Count from when the delay expired, not now
  //}
}

void round_2() {
  objective = 0;
  timers = 2;
  r1_var = random(500, 10000);
  p1_var = r1_var - 150;
  r2_var = random(500, 10000);
  p2_var = r2_var - 150;
  check = r1_var - r2_var;
  check = abs(check);
  //run check for range
  while (check <= 200) {
    r1_var = random(500, 10000);
    p1_var = r1_var - 150;
    r2_var = random(500, 10000);
    p2_var = r2_var - 150;
    check = r1_var - r2_var;
    check = abs(check);
  }
  //print timers
  Serial.print("timers active: ");
  Serial.print(r1_var);
  Serial.print(", ");
  Serial.println(r2_var);
  delay(500);
  // count down
  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  delay(1000);
  Serial.println("go");
  delay_r1.start(p1_var, AsyncDelay::MILLIS);
  delay_r2.start(p2_var, AsyncDelay::MILLIS);
  //set leds to red

  // round start
  while (objective = !timers) {
    //clear input
    if (button_flag == 1) {
      button_flag = 0;
    }
    if (button == 1) {
      button = 0;
    }

    if (delay_r1.isExpired()) {
      delay_net.start(300, AsyncDelay::MILLIS);

      while (false == delay_net.isExpired()) {
        if (button_flag == 1) {
          delay(10);
          button_flag = 0;
          button = 1;
        }
      }
      if (button == 1) {
        objective += 1;
        success += 1;
        //leds become green
        //play minor success
      } else {
        objective += 1;
      }
    }
    if (delay_r2.isExpired()) {
      delay_net.start(300, AsyncDelay::MILLIS);
      while (delay_net.isExpired() == false) {
        if (button_flag = 1) {
          delay(10);
          button_flag = 0;
          button = 1;
        }
      }
      if (button == 1) {
        objective += 1;
        success += 1;
        //leds become green
        //play minor success
      } else {
        objective += 1;
      }
    }
  }
}
void round_1() {
  objective = 0;
   timers = 1;
  r1_var = random(500, 10000);
  Serial.print("timers active: ");
  Serial.println(r1_var);
  p1_var = r1_var - 150;
  delay(500);
  // count down
  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  delay(1000);
  Serial.println("go");
  delay_r1.start(p1_var, AsyncDelay::MILLIS);
  //set leds to red

  // round start
  while (objective = !timers) {
    //clear input
    if (button_flag == 1) {
      button_flag = 0;
    }
    if (button == 1) {
      button = 0;
    }
    if (delay_r1.isExpired()) {
      delay_net.start(300, AsyncDelay::MILLIS);
      while (delay_net.isExpired() == false) {
        if (button_flag = 1) {
          delay(10);
          button_flag = 0;
          button = 1;
        }
      }
      if (button == 1) {
        objective += 1;
        success += 1;
        //leds become green
        //play minor success
      } else {
        objective += 1;
      }
    }
  }
}
void round_3() {
}
void Input() {
  button_flag = 1;
}
