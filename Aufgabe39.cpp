// Uebung_39.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"       // Einbindung von Bibliotheken
#include <iostream>
#include <cmath>
#include "string.h"
using namespace std;      //Namensräume grenzen Gültigkeitsbereiche ab

#define MAXLEN 20

                        //Struktur vom Datentyp ListElement
typedef struct ListElement
{
    char name[MAXLEN];
    struct ListElement *next;
}ListElement;

// Prototypen
void append(char n[]);
void print();

//der Zeiger first soll als "Anker"
//immer auf den Anfang der Liste zeigen
ListElement *first;


void del(char*name) {
    ListElement *ptr;
    if (first == NULL) {
        return;
    }
    else if (strcmp(first->name, name) == 0) {
        ptr = first->next;
        delete first;
        first = ptr;
    }
    else {
        ptr = first;
        ListElement *ptr1 = first->next;
        while (ptr1 != NULL) {
            if (strcmp(ptr1->name, name)==0) {
                ptr->next = ptr1->next;
                delete ptr1;
                ptr1 = ptr->next;
            }
            ptr = ptr->next;
            ptr1 = ptr1->next;
        }
    }
}

int main()
{
    append((char*)"Matthias");
    append((char*)"Hans");
    append((char*)"Monika");
    append((char*)"Armin");
    append((char*)"Almut");
    printf("\nListe nach dem Anhaengen:\n\n");
    print();
    del((char*) "Hans");
    printf("\nListe nach dem Anhaengen :\n\n");
    print();

    system("pause");
    return 0;
}

//Anhängen neuer Listenelemente
void append(char n[])
{
    ListElement *ptr;
    if (first == NULL)
    {
        first = new ListElement;
        strcpy_s(first->name, n);
        first->next = NULL;
    }
    else
    {
        ptr = first;
        while (ptr->next != NULL) ptr = ptr->next;
        ptr->next = new ListElement;
        ptr = ptr->next;
        strcpy_s(ptr->name, n);
        ptr->next = NULL;
    }
}

//Ausgeben der Liste
void print()
{
    ListElement *ptr;
    ptr = first;
    while (ptr != NULL)
    {
        printf("%s\n", ptr->name);
        ptr = ptr->next;
    }
}
