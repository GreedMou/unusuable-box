#include <Servo.h>
Servo servo_door;
Servo servo_hand;


#define prx_pin 12
#define irStatus digitalRead(prx_pin)//Далеко
#define Away 1
#define Close 0
#define A1_A 8
#define A1_B 9
#define switch_d 7
byte v;
int motor_on_rand, motor_dir, door_rand;
boolean switch_dr;

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);
  pinMode(switch_d, INPUT_PULLUP);
  pinMode(prx_pin, INPUT);
  pinMode (A1_A, OUTPUT);
  pinMode (A1_B, OUTPUT);
  servo_door.attach(4);
  servo_hand.attach(5);
  motor_dir = 0;
  servo_door.write(175);
  servo_hand.write(15);

}

void loop() {
  switch_dr = digitalRead(switch_d);
  if (irStatus == Away)
  {
    if ( irStatus == Close ) {
      motor_on_rand = random(15);
      Serial.println(motor_on_rand);
    }
    if (motor_on_rand == 5) {
      if ( motor_dir == 1) {
        motorStart(motor_dir, 750);
        motor_dir = 0;
      } else {
        motorStart(motor_dir, 750);
        motor_dir = 1;
      }
      delay(800);
    }
    motor_on_rand = 2;
  }
  if (switch_dr == 0) {
    door_rand = random(1, 8);
    switch (door_rand) {
      case 1:
        servo_door.write(125);
        delay(50);
        servo_hand.write(75);
        delay(150);
        servo_hand.write(15);
        delay(50);
        servo_door.write(175);
        break;
      case 2:
        for (int n = 175; n > 120; n--) {
          servo_door.write(n);
          delay(70);
        }
        for (int n = 15; n <= 50; n++) {
          servo_hand.write(n);
          delay(60);
        }
        servo_hand.write(75);
        delay(150);
        servo_hand.write(15);
        delay(50);
        servo_door.write(175);
        break;
      case 3:
        servo_door.write(125);
        delay(50);
        servo_hand.write(70);
        delay(2000);
        for (int n = 70; n >= 15; n--) {
          servo_hand.write(n);
          delay(70);
        }
        servo_door.write(175);
        break;
      case 4:
        for ( int n = 0; n <= 20; n++) {
          servo_door.write(135);
          delay(60);
          servo_door.write(175);
          delay(60);
        }
        servo_door.write(125);
        delay(50);
        servo_hand.write(75);
        delay(150);
        servo_hand.write(15);
        delay(50);
        servo_door.write(175);
        break;
      case 5:
        servo_door.write(125);
        for (int n = 0; n <= 25; n++) {
          servo_hand.write(60);
          delay(65);
          servo_hand.write(40);
          delay(65);
        }
        servo_hand.write(75);
        delay(150);
        servo_hand.write(15);
        delay(50);
        servo_door.write(175);
        break;
      case 6:
        for (int n = 0; n <= 10; n++) {
          servo_door.write(125);
          delay(150);
          servo_hand.write(60);
          delay(150);
          servo_hand.write(15);
          delay(150);
          servo_door.write(175);
          delay(150);
        }
        servo_door.write(125);
        delay(50);
        servo_hand.write(75);
        delay(150);
        servo_hand.write(15);
        delay(50);
        servo_door.write(175);
        break;
      case 7:
        delay(10000);
        servo_door.write(125);
        delay(50);
        servo_hand.write(75);
        delay(150);
        servo_hand.write(15);
        delay(50);
        servo_door.write(175);
        break;
    }
  }
}     //4314



void motorStart( int dir, int time) {
  if (dir == 1) {
    digitalWrite (A1_A, HIGH);
    digitalWrite (A1_B, LOW);
    delay(time);
    digitalWrite (A1_A, LOW);
    digitalWrite (A1_B, LOW);
  } else {
    digitalWrite (A1_A, LOW);
    digitalWrite (A1_B, HIGH);
    delay(time);
    digitalWrite (A1_A, LOW);
    digitalWrite (A1_B, LOW);
  }
}
