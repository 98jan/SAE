// Exercise33.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "iostream"

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


int main()
{
	int* x = new int;
	int* y = new int;
	*x = 2;
	*y = 4;
	swap(x,y);
	printf("Das ist der Wert von x: %d und dass der Wert von y: %d\n", *x, *y);
	system("pause");
}

