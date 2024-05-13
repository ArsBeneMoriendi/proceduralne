#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>

struct ElementListy
{
	int dane;
	ElementListy* kolejnyElement;
};

typedef ElementListy* ElementListyPtr;

void wstaw(ElementListyPtr* elListy, int wartosc);
int usun(ElementListyPtr* elListy, int wartosc);
int czyPusty(ElementListyPtr elListy);
void pokazListe(ElementListyPtr elListy);

#endif // !LISTA_H
