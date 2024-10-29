
// Sketch5_6.ino
#include <SoftwareSerial.h>
// 7番ピンを送信（RX）、8番ピンを受信（TX）に指定
SoftwareSerial mySerial(7, 8);
void setup()
{
  // 0番ピン、1番ピンは入力に設定することでシリアル通信を無効化
  pinMode(0, INPUT);
  pinMode(1, INPUT);

  // ソフトウェアシリアルの初期化
  mySerial.begin(9600);
  mySerial.setTimeout(100);
}
void loop() {
  if (mySerial.available()) {
    String readData = mySerial.readString();
    mySerial.println(readData);
  }
}