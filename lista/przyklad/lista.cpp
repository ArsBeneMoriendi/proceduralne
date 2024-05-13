#include "lista.h"

void wstaw(ElementListyPtr* elListy, int wartosc)
{
	ElementListyPtr nowyElement = (ElementListyPtr)malloc(sizeof(ElementListy));

	if (nowyElement != NULL)
	{
		nowyElement->dane = wartosc;
		nowyElement->kolejnyElement = NULL;

		ElementListyPtr poprzedniElement = NULL;
		ElementListyPtr bElement = *elListy;

		while (bElement != NULL && wartosc > bElement->dane)
		{
			poprzedniElement = bElement;
			bElement = bElement->kolejnyElement;
		}

		if (poprzedniElement == NULL)
		{
			nowyElement->kolejnyElement = *elListy;
			*elListy = nowyElement;
		}
		else
		{
			poprzedniElement->kolejnyElement = nowyElement;
			nowyElement->kolejnyElement = bElement;
		}
	}
	else
	{
		printf("Brak pamieci!\n");
	}
}

int usun(ElementListyPtr* elListy, int wartosc)
{
	if (wartosc == (*elListy)->dane)
	{
		ElementListyPtr tempElement = *elListy;
		*elListy = (*elListy)->kolejnyElement;
		free(tempElement);
		return wartosc;
	}
	else
	{
		ElementListyPtr poprzedniElement = *elListy;
		ElementListyPtr bElement = (*elListy)->kolejnyElement;

		while (bElement != NULL && bElement->dane != wartosc)
		{
			poprzedniElement = bElement;
			bElement = bElement->kolejnyElement;
		}

		if(bElement != NULL)
		{
			ElementListyPtr tempElement = bElement;
			poprzedniElement->kolejnyElement = bElement->kolejnyElement;
			free(tempElement);
			return wartosc;	
		}
	}

	return 0;
}

int czyPusty(ElementListyPtr elListy)
{
	return elListy == NULL;
}

void pokazListe(ElementListyPtr elListy)
{
	if (czyPusty(elListy))
	{
		printf("Lista jest pusta\n");
	}
	else
	{
		printf("\nZawartosc listy: \n");
		while (elListy != NULL)
		{
			printf("%d ===> ", elListy->dane);
			elListy = elListy->kolejnyElement;
		}
		printf("Koniec listy\n");
	}
}
