// Sketch2_4.ino
void setup() {
  Serial.begin(9600);  // シリアル通信の初期化
  pinMode(A0, INPUT);  // ポテンショメーターからの入力
  pinMode(6, OUTPUT);  // アナログ（PWM）出力
  pinMode(A5, INPUT);  // PWM出力をアナログ入力
}

void loop() {
  // ポテンショメーターからの入力を反転
  int analogInput = 1023 - analogRead(A0);

  // ポテンショメーターからの入力をアナログ（PWM）出力
  analogWrite(6, analogInput / 4);

  // ポテンショメーターからの入力(反転値)をシリアルプロッターに出力
  Serial.print("Input:");
  Serial.print(analogInput);
  Serial.print(",");

  // アナログ出力をシリアルプロッターに出力
  Serial.print("Output:");
  Serial.print(analogRead(A5));
  Serial.print(",");

  // シリアルプロッター表示の範囲を設定
  Serial.println("L:-100,H:1100");
}