// Sketch2-3.ino
void setup() {
  pinMode(4, INPUT); // 4番ピンは入力に設定LED接続を無効にする
  pinMode(6, OUTPUT); // GROVEケーブルでLEDへアナログ出力
  pinMode(A0, INPUT); // ポテンショメーター
  pinMode(A2, INPUT); // 音センサー
  pinMode(A6, INPUT); // 光センサー
}

void loop() {
  // ポテンショメーターでLEDを制御
  int analogInput = (1023 - analogRead(A0)) / 4;
  // 音センサーでLEDを点灯
  // int analogInput = analogRead(A2) / 4 - 100;
  // 光センサーで暗くなったらLEDを点灯
  // int analogInput = (1023 - analogRead(A6)) / 4 - 200;
  // 入力がマイナスになった場合はゼロにする
  if (analogInput <= 0) {
    analogInput = 0;
  }
  analogWrite(6, analogInput);
}