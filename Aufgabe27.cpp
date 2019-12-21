// Exercise27.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <stdio.h>
#include "iostream"

typedef struct {
	int kontoNummer;
	float kontostand;
}Konto;


int main()
{
	Konto giroKonto;
	Konto giroKonto2;
	giroKonto.kontostand = 5.000;
	giroKonto2 = giroKonto;
	printf("Das ist der Kontostand von Konto2: %f", giroKonto2.kontostand);
	system("pause");
    return 0;
}

