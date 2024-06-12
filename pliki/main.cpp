#include "header.h"

int main() {
    FILE* wp;
    char file_name[50];
    struct person per;
    char decyzja = '0';
    char read[50];

    set_file_name(file_name, sizeof(file_name));

    fopen_s(&wp, file_name, "a+");

    do {
        info_fill(&per);
        save_in_file(wp, &per);
        getchar();
        printf("@ - koniec\n# - dalej (lub dowolny inny znak)\n");
        scanf_s("%c", &decyzja);

    } while (decyzja != '@');

    rewind(wp);

    printf("\nDane w pliku:\n\n");
    while (fscanf_s(wp, "%s", read, (unsigned)_countof(per.name)) == 1)
    {
        printf("%s\n", read);
    }

    fclose(wp);
    return 0;
}