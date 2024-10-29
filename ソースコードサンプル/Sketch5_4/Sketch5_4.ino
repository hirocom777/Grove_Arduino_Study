// Sketch5_4.ino
#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  delay(100);

  // 1~127のアドレスで通信をテストする
  byte address;
  for (address = 1; address < 127; ++address) {

    // データ通信を試みて結果を取得
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    // エラーが発生しなかったアドレスを表記
    if (error == 0) {
      Serial.print("0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
}

void loop() {
}
