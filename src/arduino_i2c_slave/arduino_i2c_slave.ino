#include <Wire.h>
#include <Servo.h>
#define SLAVE_ADDRESS 0x40

Servo servo1, servo2;

const int servo1_rad1 = 0;
const int servo1_rad2 = 60;

const int servo2_rad1 = 0;
const int servo2_rad2 = 60;

const int pin_servo1 = 5;
const int pin_servo2 = 6;
const int pin_sw = 2;

const int pin_distance = 0;
const int pin_gyro = 1;

byte buf[4];
int num = 0;

byte data = 0;

void setup (void) {
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receive);
  Wire.onRequest(send);

  pinMode(pin_sw, INPUT_PULLUP);

  servo1.attach(pin_servo1);
  servo2.attach(pin_servo2);

  servo1.write(servo1_rad1);
  servo2.write(servo2_rad1);
}

void loop() {
  uint8_t val_distance = analogRead(pin_distance);
  uint8_t val_gyro = analogRead(pin_gyro);
  uint8_t val_sw = digitalRead(pin_sw);

  val_distance = (val_distance > 200) ? 1 : 0;

  val_gyro = ((val_gyro == 0) || (val_gyro == 1)) ? 3 : val_gyro;
  if (val_gyro > 200) {
    val_gyro = 1;//施錠時
  } else if (val_gyro < 100) {
    val_gyro = 0;//解錠時
  }

  val_sw = (val_sw == 0) ? 1 : 0;

  data = ((val_distance << 6) & B01000000) + ((val_sw << 5) & B00100000) + map(val_gyro, 0, 255, 0, 31);
}

void send() {
  Wire.write(data);
}

void receive(int numBytes) {
  num = numBytes;
  for (int i = 0; i < num - 1; i++) {
    buf[i] = Wire.read();
  }
}
