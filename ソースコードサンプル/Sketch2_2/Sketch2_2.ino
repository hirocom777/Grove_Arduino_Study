// Sketch2_2.inp
int btnStatus;  // 直前のボタンの状態を記憶

void setup() {
  pinMode(6, INPUT);   // ボタン
  pinMode(4, OUTPUT);  // LED
}

void loop() {
  if (digitalRead(6) == LOW) {
    btnStatus = LOW;  // 直前のボタン状態をLOWで記録
  } else {
    delay(10);
    // ボタンが押されたら10ミリ秒待って再度確認
    // 直前までボタンが押されていなかったことを確認
    if (digitalRead(6) == HIGH && btnStatus == LOW) {
      // LEDの表示状態を読み込んで反転させる
      digitalWrite(4, !digitalRead(4));
      btnStatus = HIGH;  // 直前のボタン状態をHIGHで記録
    }
  }
}