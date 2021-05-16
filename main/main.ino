#include "Lcd.h"
#include "Bouton.h"

Lcd lcd;
Bouton bouton(D3);
int select = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (bouton.is_pushed())
  {
    select=(select+1)%6;

    switch (select)
    {
    case 0:
      lcd.filter_screen();
      break;
    case 1:
      lcd.prepare_screen(0);
      break;
    case 2:
      lcd.prepare_screen(25);
      break;
    case 3:
      lcd.prepare_screen(50);
      break;
    case 4:
      lcd.prepare_screen(75);
      break;
    case 5:
      lcd.prepare_screen(100);
      break;
    
    default:
      break;
    }
  }
  delay(100);
}