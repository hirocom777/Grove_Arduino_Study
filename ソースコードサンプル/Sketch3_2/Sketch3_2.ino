// Sketch3_2.ino
// 温湿度センサーの準備
#include "DHT.h"
DHT dht(DHT20);     // DHT20(黒いセンサー)用
// DHT dht(3, DHT11);  // DHT11(青いセンサー)用

// 大気圧センサーの準備
#include "Seeed_BMP280.h"
BMP280 bmp280;

void setup() {
  // シリアル通信の初期化
  Serial.begin(9600);
  // 大気圧センサーの初期化
  bmp280.init();
}

void loop() {

  float readData;
  String command = Serial.readString();

  if (command == "T") {
    // 温度の表示
    readData = dht.readTemperature();
    Serial.print("Temp:  ");
    Serial.print(readData);
    Serial.println("℃");
  } else if (command == "H") {
    // 湿度の表示
    readData = dht.readHumidity();
    Serial.print("Hum:   ");
    Serial.print(readData);
    Serial.println("％");
  } else if (command == "P") {
    // 大気圧の表示
    readData = bmp280.getPressure() / 100;
    Serial.print("Press: ");
    Serial.print(readData);
    Serial.println("hPa");
  }
}