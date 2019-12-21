// Exercise8vom23102018.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
int gerade = 0;
int ungerade = 0;
int nullen = 0;
int eingabe = 0;

int main()
{
	//Schleife, die solange läuft, bis 1000 eingegeben wird
	int i = 0;
	while (i < 1000) {
		printf("\n Bitte geben Sie eine Zahl ein");
		scanf_s("%i", &eingabe);
		printf("\nIhre eingegebene Zahl lautet: %i", eingabe);



		//Prüft ob die Eingabe 1000 ist um die Abbruchbedingung einzuläuten
		if (eingabe == 1000) {
			printf("\n Sie haben %i", gerade);
			printf(" gerade Zahlen eingegeben. \n Sie haben %i", ungerade);
			printf(" ungerade Zahlen eingegeben. \n Sie haben %i", nullen);
			printf(" Nullen eingegeben. \n");
			break;
		}
		//Prüfung, ob die Zahl gerade, ungerade oder null ist und inkrementiert.
		if (eingabe < 0) {
			ungerade++;
		}
		else if (eingabe > 0) {
			gerade++;
		}
		else {
			nullen++;
		}

	}
	system("pause"); 			// Warten auf Tastatureingabe
	system("cls");
	return 0;
}


