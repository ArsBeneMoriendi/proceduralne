#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>

struct Address
{
	char* city;
	char* postal_code;
	char* street;
	int building;
	int apartment;
};

struct Person
{
	char* name;
	char* surname;
	int age;
	char* pesel;
	Address* address;
};

#endif // !LISTA_H