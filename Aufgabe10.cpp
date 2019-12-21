// Excersice10from27_11_18.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <stdio.h>
#include <cmath>
#define PRINT(char) printf("char= %c\n")
using namespace std;
double einlage;
int laufzeit;


int main()
{
	printf("Bitte geben Sie Ihre Kapitaleinlage an:\n");
	scanf_s("%i", &einlage);

	printf("Bitte geben Sie die Laufzeit an:");
	scanf_s("%i", &laufzeit);

	for (int i = 0; i < laufzeit; i++) {
		einlage *= 1.035;
	}
	printf("%d", einlage);
	system("pause");
	return 0;
}

