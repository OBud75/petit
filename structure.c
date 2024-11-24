#include "lib-structure.h"

int main() {
    printf("---User1 in detail---\n");
    struct Person user1;
    user1.age = 22;
    strcpy(user1.firstname, "Kantin"); // kantin = 6 lettre or firstname = 2 lettre donc probleme de lecture
    user1.lastname = "Petit";
    printf("%s %s à %d ans\n", user1.firstname, user1.lastname, user1.age);
    struct Person* user1_addr = &user1;
    printf("L'adresse de %s %s est %p\n", user1.firstname, user1.lastname, user1_addr);

    printf("\n---Change age User1 with pointer---\n");
    user1_addr->age = 23;
    printf("%s %s à %d ans\n", user1.firstname, user1.lastname, user1.age);

    printf("\n---Pointeur attribut User1---\n");
    printf("Person: %p\n", &user1);
    printf("Age: %p\n", &user1.age);
    printf("Firstname: %p\n", &user1.firstname);
    printf("Lastname: %p\n", &user1.lastname);

    printf("\n---User2 inline---\n");
    struct Person user2 = {25, "Charlene", "Petit"};
    printf("%s %s à %d ans\n", user2.firstname, user2.lastname, user2.age);

    printf("\n---Pointeur attribut User2---\n");
    printf("Person: %p\n", &user2);
    printf("Age: %p\n", &user2.age);
    printf("Firstname: %p\n", &user2.firstname);
    printf("Lastname: %p\n", &user2.lastname);

    printf("\n---Set Siblings---\n");
    user1.siblings = malloc(sizeof(struct Person));
    user1.siblings[0] = &user2;
    printf("%s's siblings : %s\n", user1.firstname, user1.siblings[0]->firstname);
    user2.siblings = malloc(sizeof(struct Person));
    user2.siblings[0] = &user1;
    printf("%s's siblings : %s\n", user2.firstname, user2.siblings[0]->firstname);

    printf("\n---User3 and Children---\n");
    struct Person user3 = {49, "Raphael", "Petit"};
    user3.childrens_number = 2;
    user3.childrens = malloc(user3.childrens_number * sizeof(struct Person));
    user3.childrens[0] = &user1;
    user3.childrens[1] = &user2;
    printf("%s %s à %d ans\n", user3.firstname, user3.lastname, user3.age);
    printf("Enfants: %s et %s\n", user3.childrens[0]->firstname, user3.childrens[1]->firstname);

    printf("\n---User4 and Children---\n");
    struct Person user4 = {47, "Stéphanie", "Petit"};
    user4.childrens_number = 2;
    user4.childrens = malloc(user3.childrens_number * sizeof(struct Person));
    user4.childrens[0] = &user1;
    user4.childrens[1] = &user2;
    printf("%s %s à %d ans\n", user4.firstname, user4.lastname, user4.age);
    printf("Enfants: %s et %s\n", user4.childrens[0]->firstname, user4.childrens[1]->firstname);
}