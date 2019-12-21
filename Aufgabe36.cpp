// Excercise36.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "iostream"

typedef struct {
	int nummer = - 1;
	char name[10] = "Fehler";
}datensatz;

void gibSpeicher(datensatz** person) {
	for (int zaehler = 0; zaehler < 10; zaehler++) {
		person[zaehler] = new datensatz;
	}
}

void freeSpeicher(datensatz** person) {
	for(int i = 0; i < 10; i++){
		delete person[i];
	}
}

void setInformation(datensatz** person) {
	int i = 0;
	do {
		printf("Bitte geben Sie Ihren Namen ein: ");
		scanf_s("%s", person[i]->name, _countof(person[i]->name));
		printf("Bitte geben Sie Ihr Alter ein: ");
		scanf_s("%d", &person[i]->nummer);
		++i;
	} while (i < 10 && person[i - 1]->nummer != - 1);
}

void getInformation(datensatz** person) {
	for (int i = 0; i < 10; i++) {
		if (person[i]->nummer == -1 || person[i]->name == "Fehler" || person[i]->name == " ") {
			break;
		}
		printf("Dein Name ist %s und du bist %d Jahre alt\n", person[i]->name, person[i]->nummer);
	}
}

int main()
{
	printf("Wenn keine Zahl oder -1 als Alter angegeben wird, wird die Schleife abgebrochen!\n");
	datensatz* person[10];//Deklarierung eines Arrays mit 10 benutzerdefinierten Variablen.
	int zaehler = - 1;
	gibSpeicher(person);//Speicherbelegung der 10 Variablen
	setInformation(person);//Setzen der Informationen in einer Schleife
	getInformation(person);//Abrufen aller Informationen in einer Schleife
	freeSpeicher(person);
	system("pause"); //Konsole pausieren
    return 0;
}

