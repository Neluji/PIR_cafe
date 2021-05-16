#include "Afficheur.h"
#include "Bouton.h"

Afficheur afficheur;
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
      afficheur.filter_screen();
      break;
    case 1:
      afficheur.prepare_screen(0);
      break;
    case 2:
      afficheur.prepare_screen(25);
      break;
    case 3:
      afficheur.prepare_screen(50);
      break;
    case 4:
      afficheur.prepare_screen(75);
      break;
    case 5:
      afficheur.prepare_screen(100);
      break;
    
    default:
      break;
    }
  }
  delay(100);
}