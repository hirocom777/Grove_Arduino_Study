// Sketch2_1.ino
void setup() {
  pinMode(6, INPUT);   // ボタン
  pinMode(4, OUTPUT);  // LED
}

void loop() {
  int button = digitalRead(6);  // ボタンから読み込む
  digitalWrite(4, button);      // LEDに出力
}