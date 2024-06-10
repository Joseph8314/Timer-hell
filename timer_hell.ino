#include <AsyncDelay.h>
#include <Adafruit_CircuitPlayground.h>
AsyncDelay delay_r1;
AsyncDelay delay_r2;
AsyncDelay delay_r3;
AsyncDelay delay_r4;
AsyncDelay delay_r5;
AsyncDelay delay_r6;
AsyncDelay delay_net;
int objective = 0;
volatile bool button_flag = 0;
volatile bool start_button = 0;
int check;
bool start = 0;
bool button = 0;
bool primer = 1;
int timers = 1;
int count = 0;
float lights;
float round_status;
float success = 0;
float r1_var;
float p1_var;
bool onetime;
float r2_var;
float p2_var;
bool twotime;
float r3_var;
float p3_var;
bool threetime;
float r4_var;
float p4_var;
bool fourtime;
int gap = 500;
int score = 2;
int strikes = 0;
void setup(void) {
  CircuitPlayground.begin();
  Serial.begin(9600);
  pinMode(4, INPUT_PULLDOWN);
  pinMode(5, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(5), Input_action, FALLING);
  attachInterrupt(digitalPinToInterrupt(4), Input_start, FALLING);
}

void loop(void) {
CircuitPlayground.clearPixels();
  if (primer) {
    delay(2000);
    primer = 0;
  }

  if (start)
    start = 0;

  if (start_button == 1) {
    delay(20);
    start_button = 0;
    start = 1;
  }
  if (start) {
    if (strikes < 5) {
      if (score == 1) {
        Serial.println("round_1");
        delay(2000);
        round_1();
      }
      if (score == 2) {
        Serial.println("round_2");
        delay(2000);
        round_2();
      }
      if (score => 3) {
        Serial.println("round_3");
        delay(2000);
        round_3();
      }
      delay(500);
      Serial.print("evaluation ");
      CircuitPlayground.clearPixels();
      delay(1000);
      // score anylsis
      if (success == timers) {
        Serial.println("success");
        score++;
        Serial.println(score);
      for (int t = 0; t < 10; t++) {
      CircuitPlayground.setPixelColor(t, 0, 255, 0);
      }
      delay(200);
      CircuitPlayground.clearPixels();
      delay(200);
      for (int t = 0; t < 10; t++) {
      CircuitPlayground.setPixelColor(t, 0, 255, 0);
      }
      delay(200);
        //major success noise
      } else {
        Serial.println("failure");
        Serial.print("strike ");
        strikes++;
        Serial.println(strikes);
        //disapointing noises
        for (int t = 0; t < 10; t++) {
      CircuitPlayground.setPixelColor(t, 255, 0, 0);
      }
      delay(200);
      CircuitPlayground.clearPixels();
      delay(200);
      for (int t = 0; t < 10; t++) {
      CircuitPlayground.setPixelColor(t, 255, 0, 0);
      }
      delay(200);
      }
    } else {
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
}



void round_1() {
  objective = 0;
  timers = 1;
  r1_var = random(1, 20);
  r1_var = r1_var / 2;
  Serial.print("timers active: ");
  Serial.println(r1_var);
  r1_var = r1_var * 1000;
  p1_var = r1_var - gap / 2;
  Serial.println(p1_var);
  delay(500);
  // count down
  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  delay(1000);
  for (int x = 0; x < 10; x++) {
    CircuitPlayground.setPixelColor(x, 255, 0, 0);
  }
  Serial.println("go");
  delay_r1.start(p1_var, AsyncDelay::MILLIS);
  //set leds to red

  // round start
  while (objective != timers) {
    //clear input
    if (button_flag == 1) {
      button_flag = 0;
    }
    if (button == 1) {
      button = 0;
    }
    if (delay_r1.isExpired()) {
      delay_net.start(gap, AsyncDelay::MILLIS);
      while (delay_net.isExpired() == false) {
        if (button_flag == 1) {
          delay(10);
          button_flag = 0;
          button = 1;
        }
      }
      if (button == 1) {
        objective += 1;
        success += 1;
      }
      //leds become green
      //play minor success
    else {
      objective += 1;
    }
    }
    round_status = objective / timers;
    for (int x = 0; x < 10; x++) {
      lights = round_status * 10;
      if (lights > x)
        CircuitPlayground.setPixelColor(x, 0, 0, 255);
    }
  }
}
void round_2() {
  objective = 0;
  onetime = 1;
  twotime = 1;
  timers = 2;
  Serial.print("timers active: ");
  r1_var = random(1, 20);
  r1_var = r1_var / 2;
  r2_var = random(1, 20);
  r2_var = r2_var / 2;
  while(r1_var == r2_var)
  {
  r1_var = random(1, 20);
  r1_var = r1_var / 2;
  r2_var = random(1, 20);
  r2_var = r2_var / 2;
  }

  Serial.print(r1_var);
  Serial.print(", ");

  r1_var = r1_var * 1000;
  p1_var = r1_var - gap / 2;

  
    Serial.println(r2_var);
  r2_var = r2_var * 1000;
  p2_var = r2_var - gap / 2;

  delay(500);
  // count down
  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  delay(1000);
  for (int x = 0; x < 10; x++) {
    CircuitPlayground.setPixelColor(x, 255, 0, 0);
  }
  Serial.println("go");
  delay_r1.start(p1_var, AsyncDelay::MILLIS);
  delay_r2.start(p1_var, AsyncDelay::MILLIS);
  //set leds to red

  // round start
  while (objective != timers) {
    //clear input
    if (button_flag == 1) {
      button_flag = 0;
    }
    if (button == 1) {
      button = 0;
    }
    if (delay_r1.isExpired() && onetime) {
      onetime = 0;
      delay_net.start(gap, AsyncDelay::MILLIS);
      while (delay_net.isExpired() == false) {
        if (button_flag == 1) {
          delay(10);
          button_flag = 0;
          button = 1;
        }
      }
      if (button == 1) {
        objective += 1;
        success += 1;
      }
      //leds become green
      //play minor success
    else {
      objective += 1;
    }
    }
    if (delay_r2.isExpired() && twotime) {
      twotime = 0;
      delay_net.start(gap, AsyncDelay::MILLIS);
      while (delay_net.isExpired() == false) {
        if (button_flag == 1) {
          delay(10);
          button_flag = 0;
          button = 1;
        }
      }
      if (button == 1) {
        objective += 1;
        success += 1;
      }
      //leds become green
      //play minor success
    else {
      objective += 1;
    }
    }
    round_status = objective / timers;
    for (int x = 0; x < 10; x++) {
      lights = round_status * 10;
      if (lights > x)
        CircuitPlayground.setPixelColor(x, 0, 0, 255);
    }
  }
}





void round_25() {
  objective = 0;
  timers = 2;
  r1_var = random(1, 20);
  r1_var = r1_var / 2;
  p1_var = r1_var - gap / 2;
  r2_var = random(500, 10000);
  p2_var = r2_var - gap / 2;
  check = r1_var - r2_var;
  check = abs(check);
  //run check for range
  while (check <= 200) {
    r1_var = random(500, 10000);
    p1_var = r1_var - gap / 2;
    r2_var = random(500, 10000);
    p2_var = r2_var - gap / 2;
    check = r1_var - r2_var;
    check = abs(check);
  }
  //print timers
  Serial.print("timers active: ");
  Serial.print(r1_var);
  Serial.print(", ");
  Serial.println(r2_var);
  delay(1000);
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
  for (int x = 0; x < 10; x++) {
    CircuitPlayground.setPixelColor(x, 255, 0, 0);
  }
  // round start
  while (objective == !timers) {
    //clear input
    if (button_flag == 1) {
      button_flag = 0;
    }
    if (button == 1) {
      button = 0;
    }

    if (delay_r1.isExpired()) {
      delay_net.start(gap, AsyncDelay::MILLIS);

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
      delay_net.start(gap, AsyncDelay::MILLIS);
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
  objective = 0;
  onetime = 1;
  twotime = 1;
  threetime = 1;
  timers = 3;
  Serial.print("timers active: ");
  r1_var = random(1, 20);
  r1_var = r1_var / 2;
  r2_var = random(1, 20);
  r2_var = r2_var / 2;
  r3_var = random(1, 20);
  r3_var = r3_var / 2;
  while(r1_var == r2_var)
  {
  r1_var = random(1, 20);
  r1_var = r1_var / 2;
  r2_var = random(1, 20);
  r2_var = r2_var / 2;
  }

  Serial.print(r1_var);
  Serial.print(", ");

  r1_var = r1_var * 1000;
  p1_var = r1_var - gap / 2;

  
    Serial.println(r2_var);
  r2_var = r2_var * 1000;
  p2_var = r2_var - gap / 2;

    Serial.println(r3_var);
  r3_var = r3_var * 1000;
  p3_var = r3_var - gap / 2;
  delay(500);
  // count down
  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  delay(1000);
  for (int x = 0; x < 10; x++) {
    CircuitPlayground.setPixelColor(x, 255, 0, 0);
  }
  Serial.println("go");
  delay_r1.start(p1_var, AsyncDelay::MILLIS);
  delay_r2.start(p1_var, AsyncDelay::MILLIS);
  delay_r3.start(p3_var, AsyncDelay::MILLIS);
  //set leds to red

  // round start
  while (objective != timers) {
    //clear input
    if (button_flag == 1) {
      button_flag = 0;
    }
    if (button == 1) {
      button = 0;
    }
    if (delay_r1.isExpired() && onetime) {
      onetime = 0;
      delay_net.start(gap, AsyncDelay::MILLIS);
      while (delay_net.isExpired() == false) {
        if (button_flag == 1) {
          delay(10);
          button_flag = 0;
          button = 1;
        }
      }
      if (button == 1) {
        objective += 1;
        success += 1;
      }
      //leds become green
      //play minor success
    else {
      objective += 1;
    }
    }
    if (delay_r2.isExpired() && twotime) {
      twotime = 0;
      delay_net.start(gap, AsyncDelay::MILLIS);
      while (delay_net.isExpired() == false) {
        if (button_flag == 1) {
          delay(10);
          button_flag = 0;
          button = 1;
        }
      }
      if (button == 1) {
        objective += 1;
        success += 1;
      }
      //leds become green
      //play minor success
    else {
      objective += 1;
    }
    }
     if (delay_r3.isExpired() && threetime) {
      threetime = 0;
      delay_net.start(gap, AsyncDelay::MILLIS);
      while (delay_net.isExpired() == false) {
        if (button_flag == 1) {
          delay(10);
          button_flag = 0;
          button = 1;
        }
      }
      if (button == 1) {
        objective += 1;
        success += 1;
      }
      //leds become green
      //play minor success
    else {
      objective += 1;
    }
    }
    round_status = objective / timers;
    for (int x = 0; x < 10; x++) {
      lights = round_status * 10;
      if (lights > x)
        CircuitPlayground.setPixelColor(x, 0, 0, 255);
    }
  }
}
}
void Input_action() {
  button_flag = 1;
}
void Input_start() {
  start_button = 1;
}
