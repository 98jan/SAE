// Exercise34.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "iostream"

float* p1;

void print(float num) {
	printf("%f", num);
}

void tuwas(){
	float x = 3.14;
	*p1 = x;
}

int main()
{
	p1 = new float;
	float y = 2.71;
	*p1 = y;
	print(*p1);
	tuwas();
	printf("Funktion wird ausgefuehrt!\n");
	print(*p1);
	system("pause");
    return 0;
}

