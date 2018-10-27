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

byte data = 0x55;

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

  if ((buf[0] == 0x10) && (buf[1] == 0x1)) {
    servo.write(servo_rad2);
  } else if ((buf[0] == 0x10) && (buf[1] == 0x0)) {
    servo.write(servo_rad1);
  }

  /*
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
  */
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
