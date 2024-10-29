// Sketch4_1.ino
// 3軸加速度センサーの準備
#include "LIS3DHTR.h"
LIS3DHTR<TwoWire> accelemeter;

// OLEDディスプレイの準備
#include "U8x8lib.h"
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

void setup() {
  // 3軸加速度センサーの初期化
  accelemeter.begin(Wire, 0x19);
  // OLEDディスプレイの初期化
  u8x8.begin();
  u8x8.setFlipMode(1);
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.clear();
  pinMode(4, OUTPUT); // LEDモジュール
}

void loop() {
  // X方向加速度の表示
  u8x8.setCursor(2, 1);
  u8x8.print("X = ");
  u8x8.print(accelemeter.getAccelerationX());
  u8x8.print(" ");
  // 1秒ごとにLED点滅
  delay(1000);
  digitalWrite(4, !digitalRead(4));
}
