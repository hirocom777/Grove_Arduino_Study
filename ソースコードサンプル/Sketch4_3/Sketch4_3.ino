// Sketch4_3.ino
int timerMode = 0;    // モード管理
int btnStatus = LOW;  // ボタン状態
// 時間の管理
unsigned long measureTime = millis();

void setup() {
  pinMode(6, INPUT);   // ボタン
  pinMode(4, OUTPUT);  // LED
}

void loop() {
  if (digitalRead(6) == LOW) {
    btnStatus = LOW;  // 直前のボタン状態を記録
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
      btnStatus = HIGH;  // 直前のボタン状態をHIGHで記録
    }
  }
  // 1秒ごとの処理
  if (1000 <= (millis() - measureTime)) {
    measureTime += 1000;
    // モード0の処理
    if (timerMode == 0) {
      digitalWrite(4, LOW);
    }
    // モード1の処理
    if (timerMode == 1) {
      digitalWrite(4, !digitalRead(4));
    }
    // モード2の処理
    if (timerMode == 2) {
      digitalWrite(4, HIGH);
    }
  }
}
