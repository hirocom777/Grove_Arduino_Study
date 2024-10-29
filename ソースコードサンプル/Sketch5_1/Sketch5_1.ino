// Sketch5_1.ino
// LCDモジュールの準備
#include "rgb_lcd.h"
rgb_lcd lcd;

// 温湿度センサーの準備
#include "DHT.h"
// DHT dht(DHT20); // DHT20(黒い温湿度センサー)用
DHT dht(3, DHT11);  // DHT11(青い温湿度センサー)用

void setup() {
  // LCDモジュールの初期化
  lcd.begin(16, 2);
  // lcd.setRGB(255, 255, 255);
  delay(1000);
}

void loop() {
  // 温湿度データを取得
  delay(500);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // 表示をクリアしてON
  lcd.clear();
  lcd.display();

  // 温度を表示
  lcd.setCursor(1, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");

  // 湿度を表示
  lcd.setCursor(1, 1);
  lcd.print("Hum:  ");
  lcd.print(hum);
  lcd.print(" %");

  // 5秒後に表示をOFF
  delay(5000);
  lcd.noDisplay();
}
