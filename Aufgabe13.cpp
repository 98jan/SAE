// Exercise13from271118.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int eingabe, eingabe2;
int days = 0;

int main()
{
	//Zuweisung der Tage des jeweiligen Monats
	int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	printf("Bitte geben Sie eine Monatszahl ein!\n");
	scanf_s("%i", &eingabe);

	printf("Bitte geben Sie eine Jahresszahl ein!\n");
	scanf_s("%i", &eingabe2);

	if (eingabe == 13) {
		//Es exestieren nur 12 Monate pro Jahr.
		return 0;
	}
	int i = eingabe;
	while (i >= 1) {
		days += daysPerMonth[i - 1];
		i--;
	}

	int schaltjahr;
	if (eingabe2 % 4 == 0 && eingabe2 % 100 != 0 || eingabe2 % 400 == 100) {
		printf("Es ist ein Schaltjahr");
	}
	else {
		printf("Es ist kein Schaltjahr");
	}


	printf("\nEs sind seid Jahresbeginn ");
	printf("%i", days);
	printf(" Tage vergangen!");

	system("pause");

	return 0;
}

