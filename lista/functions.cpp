#include "header.h"

void insert(list_element_ptr* list_el, Person person)
{
    list_element_ptr new_element = (list_element_ptr)malloc(sizeof(struct list_element));
    if (new_element != NULL)
    {
        new_element->person = person;
        new_element->next = NULL;

        list_element_ptr previous_element = NULL;
        list_element_ptr current_element = *list_el;

        while (current_element != NULL && person.pesel > current_element->person.pesel)
        {
            previous_element = current_element;
            current_element = current_element->next;
        }

        if (previous_element == NULL)
        {
            new_element->next = *list_el;
            *list_el = new_element;
        }
        else
        {
            previous_element->next = new_element;
            new_element->next = current_element;
        }
    }
    else
    {
        printf("Brak pamieci!\n");
    }
}

int remove(list_element_ptr* list_el, int pesel)
{
    if (*list_el == NULL)
    {
        return 0;
    }

    list_element_ptr temp_element;

    if (pesel == (*list_el)->person.pesel)
    {
        temp_element = *list_el;
        *list_el = (*list_el)->next;
        free(temp_element);
        return pesel;
    }
    else
    {
        list_element_ptr previous_element = *list_el;
        list_element_ptr current_element = (*list_el)->next;

        while (current_element != NULL && current_element->person.pesel != pesel)
        {
            previous_element = current_element;
            current_element = current_element->next;
        }

        if (current_element != NULL)
        {
            temp_element = current_element;
            previous_element->next = current_element->next;
            free(temp_element);
            return pesel;
        }
    }

    return 0;
}

int is_empty(list_element_ptr list_el)
{
    return list_el == NULL;
}

void show_list(list_element_ptr list_el)
{
    if (is_empty(list_el))
    {
        printf("Lista jest pusta\n");
    }
    else
    {
        printf("\nZawartosc listy:\n");
        while (list_el != NULL)
        {
            printf("Imie: %s, Nazwisko: %s, Wiek: %d, PESEL: %d, Adres: %s, %s, %s %d/%d\n",
                list_el->person.name,
                list_el->person.surname,
                list_el->person.age,
                list_el->person.pesel,
                list_el->person.address.city,
                list_el->person.address.postal_code,
                list_el->person.address.street,
                list_el->person.address.house_number,
                list_el->person.address.suite_number);
            list_el = list_el->next;
        }
    }
}

Person create_person()
{
    Person person;
    personal_data_fill(&person);
    return person;
}

Address create_address()
{
    Address address;
    address_data_fill(&address);
    return address;
}

void personal_data_fill(Person* person)
{
    printf("\nDane osobowe:\n");
    printf("Podaj imie: ");
    scanf_s("%s", person->name, (unsigned)_countof(person->name));
    printf("Podaj nazwisko: ");
    scanf_s("%s", person->surname, (unsigned)_countof(person->surname));
    printf("Podaj wiek: ");
    scanf_s("%d", &person->age);
    printf("Podaj PESEL: ");
    scanf_s("%d", &person->pesel);
    printf("\nDane adresowe:\n");
    person->address = create_address();
}

void address_data_fill(Address* address)
{
    printf("Miasto: ");
    scanf_s("%s", address->city, (unsigned)_countof(address->city));
    printf("Kod pocztowy: ");
    scanf_s("%s", address->postal_code, (unsigned)_countof(address->postal_code));
    printf("Nazwa ulicy: ");
    scanf_s("%s", address->street, (unsigned)_countof(address->street));
    printf("Numer domu: ");
    scanf_s("%d", &address->house_number);
    printf("Numer mieszkania: ");
    scanf_s("%d", &address->suite_number);
}