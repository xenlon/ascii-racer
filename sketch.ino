#include <LiquidCrystal.h>

const int rs = PA8, en = PB1, d4 = PB6, d5 = PB7, d6 = PB0, d7 = PA12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int toggle_lane = PB5;
bool player_row = false;
bool opponent_row;
int score = 0;
int column = 15;

void setup() {
   pinMode(toggle_lane, INPUT_PULLUP);
   lcd.begin(16, 2);
   lcd.print("  ASCII  RACER  ");
   lcd.setCursor(6,1);
   lcd.print("v1.0");
   delay(2500);
   lcd.clear();
}
void loop() {
  lcd.clear();
  if (digitalRead(toggle_lane) == LOW){
    delay(150);
    player_row = !player_row;
  }
  lcd.setCursor(0,player_row);
  lcd.print("-=}-");
  if (column < 0){
    column = 15;
    score += 1;
  }
  if (column == 15){
    opponent_row = random(0,2);
  }
  lcd.setCursor(column, opponent_row);
  lcd.print("I[]I");
  column -= 1;
  delay(100);
  if (player_row == opponent_row && column <= 3){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("   Game over!   ");
    lcd.setCursor(1,1);
    lcd.print("Score: ");
    lcd.print(score);
    player_row = false;
    column = 15;
    score = 0;
    delay(5000);
  }
}
