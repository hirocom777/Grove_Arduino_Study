// Sketch5_5.ino
// OLEDディスプレイの準備
#include "U8x8lib.h"
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/U8X8_PIN_NONE);

// 1~4行までの表示内容
String line_1 = "";
String line_2 = "";
String line_3 = "";
String line_4 = "";

void setup() {
  // シリアル通信初期設定
  Serial.begin(9600);
  Serial.setTimeout(100);
  // OLEDディスプレイの初期化
  u8x8.begin();
  u8x8.setFlipMode(1);
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.clear();
  u8x8.setCursor(0, 0);
  u8x8.print("Ready!");
}
void loop() {
  if (Serial.available()) {
    String readString = Serial.readString();  // 読み込み文字列
    int leng = readString.length();           // 文字列長さ
    int colCount = 0;                         // 表示列カウント

    for (int i = 0; i < leng; i++) {
      colCount++;
      char chrData = readString[i];  // 1文字分のデータ
      int chrCode = (int)chrData;    // 文字コード

      // 入力文字ごとの処理
      if (chrCode == 13) {
        // 改行コード（CR）処理
        line_1 = line_2;
        line_2 = line_3;
        line_3 = line_4;
        line_4 = "";
        colCount = 0;
        u8x8.clear();
      } else if (chrCode < 32 || 122 < chrCode) {
        // 文字コード以外は非対応
        break;
      } else if (colCount < 16) {
        // 表示データ追加
        line_4 = line_4 + chrData;
        // シリアルモニターに出力
        Serial.print(chrData);
      } else {
        // スクロール処理
        line_1 = line_2;
        line_2 = line_3;
        line_3 = line_4 + chrData;
        line_4 = "";
        colCount = 0;
        u8x8.clear();
        // シリアルモニターに出力
        Serial.print(chrData);
      }
      // 表示処理
      u8x8.setCursor(0, 0);
      u8x8.print(line_1);
      u8x8.setCursor(0, 1);
      u8x8.print(line_2);
      u8x8.setCursor(0, 2);
      u8x8.print(line_3);
      u8x8.setCursor(0, 3);
      u8x8.print(line_4);
    }
    // シリアルモニター改行
    Serial.print("\n");
  }
}
