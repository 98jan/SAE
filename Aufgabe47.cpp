// Aufgabe47.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "iostream"

class GiroKonto {
//muss nicht gesetzt werden
private:
	float kontostand;
	float dispo;

public:
	GiroKonto();
	GiroKonto(float wert);
	~GiroKonto();
	int einzahlen(float wert);
	int auszahlen(float wert);
	float getKontostand();
	void setDispo(float wert);
};

class SparKonto {
private: 
	float kontostand;
	float zinssatz;
public:
	SparKonto();
	SparKonto(float wert);
	~SparKonto();
	int einzahlen(float wert);
	int auszahlen(float wert);
	float getKontostand();
	float getZins();
	void setZinssatz(float wert);
};

GiroKonto::GiroKonto() {
	kontostand = 0;
	dispo = 0;
}

GiroKonto::GiroKonto(float wert) {
	this->kontostand = kontostand;
}

GiroKonto::~GiroKonto() {
	printf("Ihr Girokonto wurde aufgelöst!");
}

int GiroKonto::einzahlen(float wert) {
	if (wert < 1) {
		printf("Bitte geben Sie einen gültigen Wert an!");
		return -1;
	}
		kontostand += wert;
		printf("Ihrem Konto wurden %f gutgeschrieben, ihr neuer Kontostand beträgt: %f", wert, kontostand);
		return 1;
}

int GiroKonto::auszahlen(float wert) {
	if (wert < 1 || (kontostand - wert) < 1) {
		printf("Invalider Wert oder Kontostand reicht nicht aus!");
		return -1;
	}
	kontostand -= wert;
	printf("Ihr neuer Kontostand beträgt: %f", kontostand);
	return 1;
}

float GiroKonto::getKontostand() {
	return this->kontostand;
}

void GiroKonto::setDispo(float wert) {
	this->dispo = wert;
}

SparKonto::SparKonto() {
	this->kontostand = 0;
	this->zinssatz = 1.05;
}

SparKonto::SparKonto(float wert) {
	this->kontostand = wert;
	this->zinssatz = 1.05;
}

SparKonto::~SparKonto() {
	printf("Ihr Sparkonto wurde aufgelöst");
}

int SparKonto::einzahlen(float wert) {
	if (wert < 1) {
		printf("Bitte geben Sie einen gültigen Wert an!");
		return -1;
	}
	kontostand += wert;
	printf("Ihrem Konto wurden %f gutgeschrieben, ihr neuer Kontostand beträgt: %f", wert, kontostand);
	return 1;
}

int SparKonto::auszahlen(float wert) {
	if (wert < 1 || (kontostand - wert) < 0) {
		printf("Invalider Wert oder Kontostand reicht nicht aus!");
		return -1;
	}
	kontostand -= wert;
	printf("Ihr neuer Kontostand beträgt: %f", kontostand);
	return 1;
}

float SparKonto::getKontostand() {
	return this->kontostand;
}

float SparKonto::getZins() {
	return (this->kontostand * this->zinssatz) - this->kontostand;
}

void SparKonto::setZinssatz(float wert) {
	this->zinssatz = wert;
}

int flag = -1;
void sparGUI(SparKonto *sparKonto, GiroKonto *giroKonto);

void giroGUI(SparKonto *sparKonto, GiroKonto *giroKonto) {
	system("cls");
	printf("GIRO - KONTOVERWALTUNG");
	printf("\nBitte wählen Sie Ihre Aktion!");
	printf("\n1 = Einzahlen");
	printf("\n2 = Auszahlen");
	printf("\n3 = Umbuchen auf Sparkonto");
	printf("\n4 = Wechseln zur Sparkontoverwaltung");
	printf("\n5 = Kontostand anzeigen");
	printf("\n0 = Ende der Aktion");
	while (true) {
		if (flag == 0) {
			printf("\n\nIhre Wahl: ");
			int wahl;
			scanf_s("%d", &wahl); //User-Eingabe welche Wahl er trifft
			float input = 0;
			int value = 0;
			switch (wahl)
			{
			case 0: //0 wurde gewählt
				return; //Beenden der Applikation
			case 1: //1 wurde gewählt
				printf("\nEinzahlungsbetrag: ");
				scanf_s("%f", &input);
				giroKonto->einzahlen(input);
				break; //Abbruch des switch
			case 2: //2 wurde gewählt
				printf("\nAuszahlungsbetrag: ");
				scanf_s("%f", &input);
				giroKonto->auszahlen(input);
				break;
			case 3:
				printf("\nUmbuchungsbetrag: ");
				scanf_s("%f", &input);
				value = giroKonto->auszahlen(input);
				if (value != -1) {
					sparKonto->einzahlen(input);
				}
				break;
			case 4: 
				flag = 1;
				sparGUI(sparKonto, giroKonto);
				break;
			case 5: 
				printf("Ihr Kontostand betr\u00c4gt: %f", giroKonto->getKontostand());
				break;
			default: //falls keine gültige Wahl erfolgt ist(kein case zugetroffen hat)
				printf("Fehlerhafte Eingabe: %d", wahl);
				break;
			}
		}
		else {
			break;
		}
	}
}

void sparGUI(SparKonto *sparKonto, GiroKonto *giroKonto) {
	system("cls");
	printf("SPAR - KONTOVERWALTUNG");
	printf("\nBitte wählen Sie Ihre Aktion!");
	printf("\n1 = Einzahlen");
	printf("\n2 = Auszahlen");
	printf("\n3 = Umbuchen auf Girokonto");
	printf("\n4 = Wechseln zur Girokontoverwaltung");
	printf("\n5 = Kontostand anzeigen");
	printf("\n6 = Zinsberechnung");
	printf("\n0 = Ende der Aktion");
	while (true) {
		if (flag == 1) {
			printf("\n\nIhre Wahl: ");
			int wahl = 0, value = 0;;
			scanf_s("%d", &wahl); //User-Eingabe welche Wahl er trifft
			float input = 0;
			switch (wahl)
			{
			case 0: //0 wurde gewählt
				return; //Beenden der Applikation
			case 1: //1 wurde gewählt
				printf("\nEinzahlungsbetrag: ");
				scanf_s("%f", &input);
				sparKonto->einzahlen(input);
				break; //Abbruch des switch
			case 2: //2 wurde gewählt
				printf("\nAuszahlungsbetrag: ");
				scanf_s("%f", &input);
				sparKonto->auszahlen(input);
				break;
			case 3:
				printf("\nUmbuchungsbetrag: ");
				scanf_s("%f", &input);
				value = sparKonto->auszahlen(input);
				if (value != -1) {
					giroKonto->einzahlen(input);
				}
				break;
			case 4:
				flag = 0;
				giroGUI(sparKonto, giroKonto);
				break;
			case 5:
				printf("Ihr Kontostand betr\u00c4gt: %f", sparKonto->getKontostand());
				break;
			case 6:
				printf("Ihre aktuellen Zinsen betragen: %f", sparKonto->getZins());
				break;
			default: //falls keine gültige Wahl erfolgt ist(kein case zugetroffen hat)
				printf("Fehlerhafte Eingabe: %d", wahl);
				break;
			}
		}
		else {
			break;
		}
	}
}

int main()
{
	SparKonto *sparKonto = new SparKonto;
	GiroKonto *giroKonto = new GiroKonto;
	while (true) {
		system("cls");
		printf("KONTOVERWALTUNG");
		printf("\nBitte wählen Sie Ihre Aktion!");
		printf("\n1 = GiroKonto");
		printf("\n2 = SparKonto");
		printf("\n0 = Ende der Aktion");
		printf("\n\nIhre Wahl: ");
		int wahl;
		scanf_s("%d", &wahl); //User-Eingabe welche Wahl er trifft
		switch (wahl)
		{
		case 0: //0 wurde gewählt
			delete sparKonto;
			delete giroKonto;
			return 0; //Beenden der Applikation
		case 1: //1 wurde gewählt
			flag = 0;
			giroGUI(sparKonto, giroKonto);
			break; //Abbruch des switch
		case 2: //2 wurde gewählt
			flag = 1;
			sparGUI(sparKonto, giroKonto);
			break;
		default: //falls keine gültige Wahl erfolgt ist(kein case zugetroffen hat)
			printf("Fehlerhafte Eingabe: %d", wahl);
			break;
		}
	}
	return 0;
}

