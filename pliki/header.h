#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person 
{
    char name[50];
    char surname[50];
    int age;
    int pesel; 
    //pesel jest int, zgodnie z poleceniem zadania, jednak moim zdaniem to troche bez sensu 
    //poniewaz w przypadku mlodszych osob ucinane jest '0' na poczatku, lepiej zrobic by bylo np. char pesel[9]
};

void set_file_name(char* file_name, size_t size);
void info_fill(struct person* per);
void save_in_file(FILE* file, struct person* per);