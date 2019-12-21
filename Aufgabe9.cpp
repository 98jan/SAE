// Exercise9_13_11_2018.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
int eingabe, restwert;

int main()
{
	printf("Bitte geben Sie eine Zahl ein!");
	scanf_s("%i", eingabe);

	while (eingabe > 0) {
		restwert = eingabe;
		eingabe /= 2;
		restwert %= 2;
		printf("%i", restwert);
 }
}

