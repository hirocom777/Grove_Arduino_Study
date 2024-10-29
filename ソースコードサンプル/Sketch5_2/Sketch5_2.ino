// Sketch5_2.ino
void setup() {
  Serial.begin(9600);
  delay(100);
  // "Arduino"と送信
  Serial.println("Arduino");
  // 配列で順番に"Arduino"と送信
  for (int i = 0; i <= 7; i++) {
    Serial.print("Arduino"[i]);
  }
  Serial.print("\n");
  // 配列変数でまとめて"Arduino"と送信
  char c[] = "Arduino";
  Serial.println(c);
  // 配列変数で順番に"Arduino"と送信
  for (int i = 0; i <= 7; i++) {
    Serial.print(c[i]);
  }
  Serial.print("\n");
}
void loop() {
}