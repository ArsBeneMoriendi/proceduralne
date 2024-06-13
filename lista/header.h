#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 50

struct Address
{
    char city[ARRAY_SIZE];
    char postal_code[ARRAY_SIZE];
    char street[ARRAY_SIZE];
    int house_number;
    int suite_number;
};

struct Person
{
    char name[ARRAY_SIZE];
    char surname[ARRAY_SIZE];
    int age;
    int pesel;
    Address address;
};

struct list_element
{
    Person person;
    struct list_element* next;
};

typedef struct list_element* list_element_ptr;

void insert(list_element_ptr* list_el, Person person);
int remove(list_element_ptr* list_el, int pesel);
int is_empty(list_element_ptr list_el);
void show_list(list_element_ptr list_el);

Person create_person();
Address create_address();
void personal_data_fill(Person* person);
void address_data_fill(Address* address);