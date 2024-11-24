#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    int age;
    char firstname[10];
    char* lastname;
    struct Person* mother;
    struct Person* father;
    struct Person** siblings;
    size_t siblings_number;
    struct Person** childrens;
    size_t childrens_number;
} Person;