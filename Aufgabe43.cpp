// Aufgabe43.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "iostream"

class Konto {
	float kontostand = 0;
	float Zins_Berechnung(float);

public:
	Konto(void);
	Konto(float);
	int wertAenderung(float);
	float kontostandLesen(void);
	float Zins_Lesen(void);
};

 Konto::Konto(void) {
	 kontostand = 0;
}

 Konto::Konto(float wert) {
	 kontostand = wert;
 }

int Konto::wertAenderung(float wert) {
	if (wert <= 0) {
		return 0;
	}
		kontostand = wert;
		return 1;
}

float Konto::kontostandLesen(void) {
	return kontostand;
}

float Konto::Zins_Berechnung(float wert) {
	return kontostand * (1+wert);
}

float Konto::Zins_Lesen(void) {
	return Zins_Berechnung(0.015f); //Zinssatz anpassen
}

int main()
{
	Konto konto(100);
	printf("KONTOVERWALTUNG");
	printf("\n1 = Kontostand \u00c4ndern");
	printf("\n2 = Kontostand lesen");
	printf("\n3 = Zinsen berechnen");
	printf("\n0 = Ende der Aktion");
	while (true) {
	printf("\n\nIhre Wahl: ");
	int wahl;
	scanf_s("%d", &wahl); //User-Eingabe welche Wahl er trifft
		switch (wahl)
		{
		case 0: //0 wurde gewählt
			return 0; //Beenden der Applikation
		case 1: //1 wurde gewählt
			float value;
			int state;
			printf("Bitte geben Sie Ihren neuen Kontostand an:");
			scanf_s("%f", &value); //User-Eingabe des neuen Kontostandes
			state = konto.wertAenderung(value); //Kontostand ändern
			//Prüfung ob Kontostand geändert werden konnte(kein Minus möglich)
			if (state == 0) { 
				printf("Kontostand konnte nicht geändert werden!");
			}
			else {
				printf("Kontostand wurde erfolgreich geändert werden!");
			}
			break; //Abbruch des switch
		case 2: //2 wurde gewählt
			printf("Ihr Kontostand betr\u00c4gt: %f", konto.kontostandLesen()); //Ausgabe des Kontostandes
			break;
		case 3:
			printf("Ihre Zinsen betragen: %f",konto.Zins_Lesen());
			break;
		default: //falls keine gültige Wahl erfolgt ist(kein case zugetroffen hat)
			printf("Fehlerhafte Eingabe: %d", wahl);
			break;
		}
	}
}

