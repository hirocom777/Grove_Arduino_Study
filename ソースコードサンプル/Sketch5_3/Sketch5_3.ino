// Sketch5_3.ino
void setup() {
  Serial.begin(9600);
  delay(100);

  Serial.println(String(1.2).toInt());    // 1を返す
  Serial.println(String(1.2).toFloat());  // 1.20を返す

  String testString = " Arduino ";
  testString.trim();
  Serial.println(testString);  // "Arduino"(前後の空白を削除)を返す

  testString.toLowerCase();
  Serial.println(testString);  // "arduino"(小文字に変換)を返す

  testString.toUpperCase();
  Serial.println(testString);  // "ARDUINO"(大文字に変換)を返す

  Serial.println(testString.substring(2, 4));  // "DU"(部分切り取り)を返す

  Serial.println(testString.length());  // 7(文字列長さ)を返す

  Serial.println(testString[5]);  // 'N'（6番目の文字）を返す
}
void loop() {
}