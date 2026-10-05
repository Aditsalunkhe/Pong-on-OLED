# Arduino OLED Pong

A classic two-player Pong game on a 128x64 OLED. Each player controls a
paddle with a potentiometer, and the score is shown at the top.

**Live simulation:** https://wokwi.com/projects/477022524738887681

## Features
- Two-player gameplay with analog paddle control
- Ball bounces off walls and paddles
- Live score for both players
- Ball resets to the centre after each point

## Components
| Part | Qty |
|---|---|
| Arduino Uno | 1 |
| SSD1306 OLED 128x64 (I2C) | 1 |
| Potentiometer | 2 |

## Wiring
| Component | Pin | Arduino |
|---|---|---|
| OLED | SDA | A4 |
| OLED | SCL | A5 |
| OLED | VCC / GND | 5V / GND |
| Potentiometer 1 (left paddle) | Wiper | A0 |
| Potentiometer 2 (right paddle) | Wiper | A1 |
| Both potentiometers | Outer pins | 5V and GND |

## Libraries
- Adafruit SSD1306
- Adafruit GFX Library

## How to run
1. Open the Wokwi link and press ▶.
2. Turn the left potentiometer to move the left paddle, and the right
   potentiometer for the right paddle.
3. Miss the ball and the opponent scores.

## How it works
Each loop reads both potentiometers with `analogRead()` and maps the value
to a paddle position. The ball position is updated by its velocity, and
collisions with the walls and paddles flip its direction. The frame is
redrawn on the OLED every 15 ms.

## Future improvements
- Buzzer beep on each bounce
- Ball speeds up over time
- Winning score and game-over screen

## License
MIT
