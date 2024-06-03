#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* wp;
	char name[50];
	char surname[50];
	char read[50];
	char end = '0';
	int age = 0;

	fopen_s(&wp, "nowy.txt", "a+");

	do
	{
		printf("Podaj swoje imie: ");
		scanf_s("%s", name, (unsigned)_countof(name));
		fprintf(wp, "Imie: %s\n", name);

		printf("Podaj swoje nazwisko: ");
		scanf_s("%s", surname, (unsigned)_countof(surname));
		fprintf(wp, "Nazwisko: %s\n", surname);

		printf("Podaj swoj wiek: ");
		scanf_s("%d", &age);
		fprintf(wp, "Wiek: %d", age);
		fprintf(wp, "\n==================================\n");

		getchar();

		printf("@ - koniec\n# - dalej");
		scanf_s("%c", &end);

	} while (end != '@');

	rewind(wp);

	while (fscanf_s(wp, "%s", read, (unsigned)_countof(name)) == 1)
	{
		printf("Dane w pliku: %s\n", read);
	}

	fclose(wp);

	return 0;
}
