#include <Wire.h>
#include <Servo.h>
#define SLAVE_ADDRESS 0x40

Servo servo;

const int servo_rad1 = 90;
const int servo_rad2 = 180;

const int pin_servo = 5;

const int pin_sw = 2;

const int pin_distance = 0;
const int pin_gyro = 1;

byte buf[4];
int num = 0;

byte data = 0x00;

void setup (void) {
  Serial.begin(9800);

  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receive);
  Wire.onRequest(send);

  pinMode(pin_sw, INPUT_PULLUP);

  servo.attach(pin_servo);

  servo.write(servo_rad1);
}

void loop() {
  /*
    サーボ駆動部
  */
  if ((buf[0] == 0x10) && (buf[1] == 0x1)) {
    servo.write(servo_rad2);
  } else if ((buf[0] == 0x10) && (buf[1] == 0x0)) {
    servo.write(servo_rad1);
  }


  /*
     センサー読み取り部
  */
  uint8_t val_distance = analogRead(pin_distance);
  uint8_t status_distance = 0;

  uint8_t val_gyro = analogRead(pin_gyro);
  uint8_t status_gyro = 0;

  uint8_t status_sw = 1 - digitalRead(pin_sw);

  status_distance = (val_distance > 200) ? 1 : 0;

  if (val_gyro > 200) {
    status_gyro = 0;//施錠時
  } else if (val_gyro < 100) {
    status_gyro = 1;//解錠時
  }

  data = ((status_distance<<2)&B00000100)+((status_gyro<<1)&B00000010)+((status_sw<<2)&B00000001);
}

void send() {
  Wire.write(data);
  Serial.print("I2C written : ");
  Serial.println(data);
}

void receive(int numBytes) {
  num = numBytes;

  Serial.print("num = ");
  Serial.println(num);

  Serial.print("I2C read : ");

  int i = 0;
  while (i < num) {
    if (Wire.available() != 0) {
      buf[i] = Wire.read();
      i++;
    }
  }

  for (int j = 0; j < num; j++) {
    Serial.print(buf[j]);
    Serial.print("  ");
  }
  Serial.println("");
}
