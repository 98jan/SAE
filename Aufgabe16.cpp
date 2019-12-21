// Excercise16from111218.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char wort1[20];
char wort2[20];
char wort3[20];

int main()
{
	

	printf("Bitte geben Sie Ihr Wort ein!");
	scanf_s("%d", &wort1);
	printf("\nIhr eingegebenes Wort ist %d", wort1);
	printf("\nDie Länge beträgt %i", wort1);
	
	system("pause");
    return 0;
}

