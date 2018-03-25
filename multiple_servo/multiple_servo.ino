#include <Servo.h>

#define PIN_SERVO 8
Servo servo[6];
int servoPositions[6];
char receivedBytes[2];

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++)
  {
    servo[i] = Servo();
    servo[i].attach(PIN_SERVO + i);
  }
  servo[0].write(55);
  servo[1].write(110);
  servo[2].write(80);
  servo[3].write(180);
  servo[4].write(80);
  servo[5].write(110);
}

void loop() {
//looping:
//  servo[0].write(72);
//  servo[1].write(97);
//  servo[2].write(65);
//  servo[3].write(140);
//  servo[4].write(62);
//  servo[5].write(96);
//
//  delay(5000);
//
//  servo[0].write(55);
//  servo[1].write(110);
//  servo[2].write(80);
//  servo[3].write(180);
//  servo[4].write(80);
//  servo[5].write(110);
//
//  delay(1000);
//
//  goto looping;
  
  Serial.readBytes(receivedBytes, 1);
  /*
      on/off    peg index
       |         | | |
       0 0 0 0 0 0 0 0
      1/0         0-5

  */
  int peg_index = receivedBytes[0] & 0x07;
  int peg_up = receivedBytes[0] & 0x80;

  if (peg_up)
  {
    // move peg up
    switch (peg_index)
    {
      case 0:
        servo[peg_index].write(72);
        break;
      case 1:
        servo[peg_index].write(97);
        break;
      case 2:
        servo[peg_index].write(65);
        break;
      case 3:
        servo[peg_index].write(140);
        break;
      case 4:
        servo[peg_index].write(62);
        break;
      case 5:
        servo[peg_index].write(96);
        break;
      default:
        break;
    }
  }
  else
  {
    // move peg down
    switch (peg_index)
    {
      case 0:
        servo[peg_index].write(55);
        break;
      case 1:
        servo[peg_index].write(110);
        break;
      case 2:
        servo[peg_index].write(80);
        break;
      case 3:
        servo[peg_index].write(180);
        break;
      case 4:
        servo[peg_index].write(80);
        break;
      case 5:
        servo[peg_index].write(110);
        break;
      default:
        break;
    }
  }
}
