/* Aufgabe38.cpp : 
	Schreiben Sie ein Programm mit zwei Funktionen "print" und "append". "print" hat die einzige Aufgabe die mit "append" angelegte Liste wieder auszugeben.
	"append" ist eine Funktion, mit der Listen-Elemente des folgenden Objekts angelegt werden können:

	Hinweis:
	Verwenden Sie dazu zwei ListElement-Pointer. Den globalen(von überall hier erreichbar) Pointer "first", als Anker(immer das erste ListElement) und einen bezüglich der Funktion "append" lokalen(nur in der Funktion nutzbar) Pointer "ptr" zum Zugriff auf die Liste.
	Da "first" ein globaler Zeiger ist, muss der Funktion "append" lediglich die Komponente "name"(der gesetzt werden soll) übergeben werden.
*/

#include <iostream>

//With typedef we can design new datatype name
//define typedef struct
typedef struct ListElement{
	//char-array(pointer) which can hold up to 9 chars + "\0"
	char name[10];
	//add an ListElement to make an linear List
	struct ListElement* next;
	//define name of typedef struct
} ListElement;

//define prototyps(only needed when functions are underneath main function)
//char* == char[] -> an array is also a pointer
void append(char* name);
void print();

//add first-Pointer as global pointer and set it to NULL
ListElement* first = NULL;

//main-function which will be called on startup
int main()
{
	//cast string into char-array and append it to the List
	append((char*) "Jan");
	append((char*) "Roman");
	append((char*) "Aman");
	print();
	return 0;
}
	

void append(char* name) {
	//check if List is empty
	if (first == NULL) {
		//initialize the custom datatype from type ListElement
		first = new ListElement;
		strcpy_s(first->name, name);
		first->next = NULL;
	}
	else {
		//set ptr to first
		ListElement* ptr = first;
		//find the end of the list
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		//add new ListElement to List
		ptr->next = new ListElement;
		//set ptr to new ListElement
		ptr = ptr->next;
		//Copy name into ListElement
		strcpy_s(ptr->name, name);
		//set next ListElement to NULL
		ptr->next = NULL;
	}
}

void print() {
	ListElement* ptr = first;
	printf("Das sind die Namen, die sich in der Liste befinden");
	//print all names which are in ListElement till the end is reached.
	while (ptr != NULL) {
		printf("\n Name: %s", ptr->name);
		ptr = ptr->next;
	}
}


