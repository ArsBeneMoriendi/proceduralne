#include "header.h"

int main() 
{
    list_element_ptr starting_el = NULL;
    Person person;
    int pesel;
    int wybor;

    do 
    {
        printf("\nWybierz opcje: \n1 - wstaw osobe na liste \n2 - usun osobe z listy \n3 - pokaz liste \n4 - koniec\n");
        scanf_s("%d", &wybor);

        switch (wybor) 
        {
        case 1:
            person = create_person();
            insert(&starting_el, person);
            show_list(starting_el);
            break;
        case 2:
            if (!is_empty(starting_el)) 
            {
                printf("Podaj PESEL osoby do usuniecia: ");
                scanf_s("%d", &pesel);

                if (remove(&starting_el, pesel)) 
                {
                    printf("Usunieto osobe o nastepujacym numerze PESEL: %d\n", pesel);
                }
                else 
                {
                    printf("Nie znaleziono osoby o podanym numerze PESEL\n");
                }
            }
            else 
            {
                printf("Lista jest pusta\n");
            }
            break;
        case 3:
            show_list(starting_el);
            break;
        case 4:
            printf("Koniec\n");
            break;
        default:
            printf("Nie ma takiej opcji\n");
            break;
        }

    } while (wybor != 4);

    return 0;
}