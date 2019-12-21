// Excercise18_08012019.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include <stdio.h>
#include <cmath>
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
char username[3][100];
char password[3][100];
char user_password[5][100] = { {"12345"}, {"Franz"}, {"cyka blyat"}, {"54321"}, {"Hallo"} };
		printf("Bitte geben Sie Ihren Benutzernamen ein!");
	for (int i = 0; i < 3; i++) {
		scanf_s("%s", username[0], _countof(username[0]));
		printf("Bitte geben Sie Ihr Passwort ein!");
		scanf_s("%s\n", password[0], _countof(password[0]));
		for (int j = 0; j < 5; j++) {
			if (strcmp(password[0], user_password[j])) {
				i = 3;
			printf("Guten Morgen %s", username[0]);
				break;
			}
			else {
				printf("\nIhr Passwort ist falsch!");
				printf("\Sie haben noch ,%d", i ," Versuche!");
				i++;
			}
		}
		if(i <= 3) {
			printf("\nIhr Passwort ist falsch!");
		}

	}
	system("pause");
	system("cls");
    return 0;
}

