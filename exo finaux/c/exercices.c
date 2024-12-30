#include "exercices.h"


void equals_test(){
    Person person1 = {PERSON, 50};
    Person person2 = {PERSON, 50};
    bool equal_persons = are_equals(
        &person1,
        &person2
    );
    if (equal_persons) {
        printf("Persons are equals\n");
    } else {
        printf("Persons are not equals\n");
    }

    Book book1 = {BOOK, 50};
    Book book2 = {BOOK, 50};
    bool equal_books = are_equals(
        &book1,
        &book2
    );
    if (equal_books) {
        printf("Books are equals\n");
    } else {
        printf("Books are not equals\n");
    }
}

void is_in_test(){
    Person person1 = {PERSON, 50};
    Person person2 = {PERSON, 50};
    Person *people[] = {&person1, &person2};
    
    bool is_in_people = is_in_array(
        &person1,
        (void **) people,
        sizeof(people) / sizeof(Person),
        sizeof(Person)
    );

    if (is_in_people) {
        printf("Person is in array\n");
    } else {
        printf("Person is not in array\n");
    }

    Book book1 = {BOOK, 50};
    Book book2 = {BOOK, 50};
    Book *books[] = {&book1, &book2};

    bool is_in_books = is_in_array(
        &book1,
        (void **) books,
        sizeof(books) / sizeof(Book),
        sizeof(Book)
    );

    if (is_in_books) {
        printf("Book is in array\n");
    } else {
        printf("Book is not in array\n");
    }
}

void is_greater_test(){
    Person person1 = {PERSON, 50};
    Person person2 = {PERSON, 40};
    bool greater_persons = is_greater(
        &person1,
        &person2
    );
    if (greater_persons) {
        printf("Person1 is greater than person2\n");
    } else {
        printf("Person1 is not greater than person2\n");
    }

    Book book1 = {BOOK, 50};
    Book book2 = {BOOK, 40};
    bool greater_books = is_greater(
        &book1,
        &book2
    );
    if (greater_books) {
        printf("Book1 is greater than book2\n");
    } else {
        printf("Book1 is not greater than book2\n");
    }
}

void swap_test(){
    Person person1 = {PERSON, 50};
    Person person2 = {PERSON, 40};
    printf("Person1 age: %d -> Person2 age: %d\n", person1.age, person2.age);
    swap(&person1, &person2, sizeof(Person));
    printf("Person1 age: %d -> Person2 age: %d\n", person1.age, person2.age);

    Book book1 = {BOOK, 50};
    Book book2 = {BOOK, 40};
    printf("Book1 pages: %d -> Book2 pages: %d\n", book1.pages, book2.pages);
    swap(&book1, &book2, sizeof(Book));
    printf("Book1 pages: %d -> Book2 pages: %d\n", book1.pages, book2.pages);
}

void sort_test() {
    Person person1 = {PERSON, 50};
    Person person2 = {PERSON, 40};
    Person person3 = {PERSON, 60};
    Person *people[] = {&person1, &person2, &person3};
    sort(
        (void **) people,
        sizeof(people) / sizeof(Person),
        sizeof(Person)
    );
    for (int i = 0; i < sizeof(people) / sizeof(Person); i++) {
        printf("Person %d: %d\n", i, people[i]->age);
    }

    Book book1 = {BOOK, 50};
    Book book2 = {BOOK, 40};
    Book book3 = {BOOK, 60};
    Book *books[] = {&book1, &book2, &book3};
    sort(
        (void **) books,
        sizeof(books) / sizeof(Book),
        sizeof(Book)
    );
    for (int i = 0; i < sizeof(books) / sizeof(Book); i++) {
        printf("Book %d: %d\n", i, books[i]->pages);
    }
}

int main() {
    equals_test();
    is_in_test();
    is_greater_test();
    swap_test();
    sort_test();
    return 0;
}