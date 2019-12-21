// Aufgabe26.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

long nett(int a, int b) {
	if (b) {
		printf("Das ist der Wert von a: %d und das der Wert von b: %d\n", a, b);
		return nett(a, b - 1) + 1;
	}
	else {
		printf("Das ist der Wert von a: %d und das der Wert von b: %d\n", a, b);
		return a;
	}
}

int main()
{
	int a = 2, b = 3;
	printf("Das ist der Wert von a: %d und das der Wert von b: %d\n", a, b);
	long f = nett(a, b);
	printf("Das ist der Wert von a: %d und das der Wert von b: %d und das ist f: %d\n", a, b, f);
	system("pause");
    return 0;
}

