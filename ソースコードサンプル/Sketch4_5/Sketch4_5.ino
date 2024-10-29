// Sketch4_5.ino
// OLEDディスプレイの準備
#include "U8x8lib.h"
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/U8X8_PIN_NONE);

int timerMode = 0;        // モード管理
int btnStatus = LOW;      // ボタン状態
int setTime = 60;         // カウント時間の設定
int countTime = setTime;  // カウントの管理
//時間の管理
unsigned long measureTime = millis();

void setup() {
  pinMode(6, INPUT);   // ボタン
  pinMode(4, OUTPUT);  // LED
  // OLEDディスプレイの初期化
  u8x8.begin();
  u8x8.setFlipMode(1);
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.clear();
}

void loop() {
  if (digitalRead(6) == LOW) {
    btnStatus = LOW; // 直前のボタン状態を記録
  } else {
    delay(10);
    // ボタンが押されたら10ミリ秒待って再度確認
    // 直前までボタンが押されていなかったことを確認
    if (digitalRead(6) == HIGH && btnStatus == LOW) {
      // モードの切り替え
      timerMode++;
      if (3 <= timerMode) {
        timerMode = 0;
      }
      btnStatus = HIGH; // 直前のボタン状態をHIGHで記録
    }
  }
  // 1秒ごとの処理
  if (1000 <= (millis() - measureTime)) {
    measureTime += 1000;
    u8x8.setCursor(2, 1);
    u8x8.println(TimeText(countTime) + "/" + TimeText(setTime));
    // モード0の処理
    if (timerMode == 0) {
      digitalWrite(4, LOW);
      countTime = setTime;
    }
    // モード1の処理
    if (timerMode == 1) {
      digitalWrite(4, !digitalRead(4));
      countTime--;
      if (countTime == 0) {
        timerMode = 2;
      }
    }
    //モード2の処理
    if (timerMode == 2) {
      tone(5, 392, 800);
      digitalWrite(4, HIGH);
    }
  }
}

// 秒数を時間表示にする（例　60　→　01:00）
String TimeText(int seconds) {
  String textData = "";
  //分の表示
  int minutes = seconds / 60;
  if (minutes < 10) {
    textData = "0";
  }
  textData += String(minutes) + ":";
  // 秒の表示
  seconds = seconds % 60;
  if (seconds < 10) {
    textData += "0";
  }
  textData += String(seconds);
  return textData;
}
