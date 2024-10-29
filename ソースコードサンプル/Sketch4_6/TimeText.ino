// TimeText.ino
// 秒数を時間表示にする（例　60　→　01:00）
String TimeText(int seconds) {
  String textData = "";
  // 分の表示
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
