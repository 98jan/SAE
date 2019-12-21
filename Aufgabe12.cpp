// Uebung12vom27_11_18.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
int eingabe, modulo, ergebnis;

int main()
{
	printf("Bitte geben Sie eine Zahl ein!");
	scanf_s("%i", &eingabe);

	modulo = ergebnis;
	for(int i = 0; eingabe !=0; i++) {
		eingabe /= 2;
		modulo  %= 2;

   }
}

