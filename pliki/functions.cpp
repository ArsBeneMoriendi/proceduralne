#include "header.h"

void set_file_name(char* file_name, size_t rozmiar) {
    printf("Podaj nazwe pliku (bez rozszerzenia): ");
    scanf_s("%s", file_name, rozmiar);
    strcat_s(file_name, rozmiar, ".txt");
}

void info_fill(struct person* per) {
    printf("Podaj imie: ");
    scanf_s("%s", per->name, (unsigned)_countof(per->name));
    printf("Podaj nazwisko: ");
    scanf_s("%s", per->surname, (unsigned)_countof(per->surname));
    printf("Podaj wiek (liczba calkowita): ");
    scanf_s("%d", &per->age);
    printf("Podaj PESEL (liczba calkowita): ");
    scanf_s("%d", &per->pesel);
}

void save_in_file(FILE* file, struct person* per) {
    fprintf(file, "Imie: %s\n", per->name);
    fprintf(file, "Nazwisko: %s\n", per->surname);
    fprintf(file, "Wiek: %d\n", per->age);
    fprintf(file, "PESEL: %d\n", per->pesel);
    fprintf(file, "\n==================================\n");
}