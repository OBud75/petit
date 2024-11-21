#include "lib.h"

int main(int argc, char *argv[]) {
    int a = 1;
    int b = 2;

    printf("### Echange de valeur ###\n\n");
    printf("Adresse memoire de a: %p.\n", &a);
    printf("Adresse memoire de b: %p.\n", &b);
    printf("a = %d, b = %d.\n", a, b);
    swap(&a,&b);
    printf("Adresse memoire de a: %p.\n", &a);
    printf("Adresse memoire de b: %p.\n", &b);
    printf("a = %d, b = %d.\n", a, b);

    printf("\n### Récupération valeur de a à partir du pointeur de a ###\n\n");
    int* pointer_a = &a;
    int a_value = *pointer_a;
    printf("Valeur de a %d\n", a_value);

}