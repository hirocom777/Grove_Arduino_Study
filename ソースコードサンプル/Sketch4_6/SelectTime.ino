// SelectTime.ino
// ポテンショメーターで測定時間を調整する
int SelectTime() {
  pinMode(A0, INPUT); // ポテンショメーター
  int inputTime = 1023 - analogRead(A0);
  if (1000 < inputTime) {
    return 600;
  }
  if (900 < inputTime) {
    return 540;
  }
  if (800 < inputTime) {
    return 480;
  }
  if (700 < inputTime) {
    return 420;
  }
  if (600 < inputTime) {
    return 360;
  }
  if (500 < inputTime) {
    return 300;
  }
  if (400 < inputTime) {
    return 240;
  }
  if (300 < inputTime) {
    return 180;
  }
  if (200 < inputTime) {
    return 120;
  }
  return 60;
}