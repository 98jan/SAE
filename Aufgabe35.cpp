// Exercise35.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "iostream"

typedef struct {
	int nummer;
	char name[10];
}datensatz;



void setInformation(datensatz* person) {
	printf("Bitte geben Sie Ihren Namen ein: ");
	scanf_s("%s", person->name, _countof(person->name));
	printf("Bitte geben Sie Ihr Alter ein: ");
	scanf_s("%d", &person->nummer);
}

void getInformation(datensatz* person) {
	printf("Dein Name ist %s und du bist %d Jahre alt\n", person->name, person->nummer);
}

int main()
{
	datensatz* person; //Deklarieren der benutzerdefinierten Variable als Pointer
	person = new datensatz; //Speicherbelegung für benutzerdefinierte Variable
	setInformation(person); //setzen der Informationen
	getInformation(person); //Abrufen der Informationen
	system("pause"); //Konsole pausieren
	delete person; //Freigeben des Speichers
    return 0;
}

