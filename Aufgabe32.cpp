// Exercise32.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "iostream"


void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int x = 0;
	int y = 2;
	swap(&x, &y);
	//printf("Das ist ein Test!");
	printf("Das ist x: %d und das ist y: %d\n", x, y);
	system("pause");
	return 0;
}

