#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    PERSON,
    BOOK
} Type;

typedef struct Person{
    Type type;
    int age;
} Person;

typedef struct Book{
    Type type;
    int pages;
} Book;

bool are_persons_equals(Person *p1, Person *p2) {
    return p1->age == p2->age;
}

bool are_books_equals(Book *b1, Book *b2) {
    return b1->pages == b2->pages;
}

bool are_equals(void *obj1, void *obj2) {
    if (((Person *)obj1)->type == PERSON && ((Person *)obj2)->type == PERSON) {
        return are_persons_equals((Person *)obj1, (Person *)obj2);
    } else if (((Book *)obj1)->type == BOOK && ((Book *)obj2)->type == BOOK) {
        return are_books_equals((Book *)obj1, (Book *)obj2);
    } else {
        printf("Type error\n");
        return false;
    }
}

bool is_in_array(void *obj_found, void *array[], int nb_of_elems_in_array, size_t elem_size) {
    for (int i = 0; i < nb_of_elems_in_array; i++) {
        if (are_equals(obj_found, array[i])) {
            return true;
        }
    }
    return false;
}

bool is_persons_greater(Person *p1, Person *p2) {
    return p1->age > p2->age;
}

bool is_books_greater(Book *b1, Book *b2) {
    return b1->pages > b2->pages;
}

bool is_greater(void *obj1, void *obj2) {
    if (((Person *)obj1)->type == PERSON && ((Person *)obj2)->type == PERSON) {
        return is_persons_greater(obj1, obj2);
    } else if (((Book *)obj1)->type == BOOK && ((Book *)obj2)->type == BOOK) {
        return is_books_greater(obj1, obj2);
    } else {
        printf("Type error\n");
        return false;
    }
}

// On peut penser à une fonction de comparaison qui renvoie -1 si obj1 < obj2, 1 si obj1 > obj2 et 0 si égaux

void swap(void *a, void *b, size_t size) {
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void sort(void *array[], int nb_of_elems_in_array, size_t elem_size) {
    for (int i = 0; i < nb_of_elems_in_array; i++) {
        for (int j = i + 1; j < nb_of_elems_in_array; j++) {
            if (is_greater(array[i], array[j])) {
                swap(array[i], array[j], elem_size);
            }
        }
    }
}
