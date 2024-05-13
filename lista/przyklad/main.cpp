#include "lista.h"

int main()
{
	ElementListyPtr elementStartowy = NULL;
	int element;
	int wybor;

	do
	{
		printf("\nWybierz opcje: \n1 - wstaw element na liste \n2 - usun element z listy \n3 - koniec\n");
		scanf_s("%d", &wybor);

		switch (wybor)
		{
		case 1:
			printf("Podaj dowolna liczbe calkowita: ");
			scanf_s("%d", &element);
			wstaw(&elementStartowy, element);
			pokazListe(elementStartowy);
			break;
		case 2:
			if (!czyPusty(elementStartowy))
			{
				printf("Podaj ktora liczbe usunac: ");
				scanf_s("%d", &element);

				if (usun(&elementStartowy, element))
				{
					printf("Usunieto wartosc: %d\n", element);
				}
				else
				{
					printf("Nie znaleziono wartosci\n");
				}
			}
			else
			{
				printf("Lista jest pusta\n");
			}
			break;
		case 3:
			printf("Koniec");
			break;
		default:
			printf("Nie ma takiej opcji\n");
			break;
		}

	} while (wybor != 3);

	return 0;
}
