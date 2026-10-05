#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 d(128, 64, &Wire, -1);
float bx = 64, by = 32, vx = 2, vy = 1.5;
int sL = 0, sR = 0;

void setup() { d.begin(SSD1306_SWITCHCAPVCC, 0x3C); }

void loop() {
  int pl = map(analogRead(A0), 0, 1023, 0, 48);
  int pr = map(analogRead(A1), 0, 1023, 0, 48);
  bx += vx; by += vy;
  if (by <= 0 || by >= 61) vy = -vy;
  if (bx <= 4 && by >= pl - 2 && by <= pl + 16) vx = abs(vx);
  else if (bx >= 121 && by >= pr - 2 && by <= pr + 16) vx = -abs(vx);
  if (bx < 0)   { sR++; bx = 64; by = 32; vx = 2; }
  if (bx > 127) { sL++; bx = 64; by = 32; vx = -2; }

  d.clearDisplay();
  d.fillRect(0, pl, 3, 16, WHITE);
  d.fillRect(125, pr, 3, 16, WHITE);
  d.fillRect(bx, by, 3, 3, WHITE);
  d.setTextColor(WHITE);
  d.setCursor(50, 0); d.print(sL);
  d.setCursor(72, 0); d.print(sR);
  d.display(); delay(15);
}