 //Excercise24.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "iostream"


int main()
{
	int zahlen[10];
	for (int i = 0; i < 10; i++) {
		printf("Bitte geben Sie Ihre %d Zahl ein", i);
		scanf_s("%d", zahlen[i]);
	}
	system("pause");
    return 0;
}

