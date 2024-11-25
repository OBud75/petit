#include "lib-quadrichaine.h"
#include <time.h>

int main() {
    int height = 5, width = 5;

    // Création de la carte
    Map map = set_map(height, width);
    if (map.blocks == NULL) {
        printf("Échec de la création de la carte.\n");
        return 1;
    }

    printf("Carte de %dx%d créée avec succès.\n", map.height, map.width);

    struct Player player = (struct Player){&map.blocks[map.height/2][map.width/2]};
    if (player.position == NULL)
    {
        printf("Échec de la création du joueur.\n");
        free_map(map);
        return 1;
    }
    
    printf("Joueur créé avec succès.\n");

    // Tableau des choix possibles
    char choices[] = {'t', 'l', 'b', 'r'};
    int num_choices = sizeof(choices) / sizeof(choices[0]);

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL)); // Utilise l'heure actuelle comme graine pour rendre le tirage aléatoire
    
    for (size_t i = 0; i < 10; i++)
    {
        get_map(&map, &player);


        // Génération d'un index aléatoire
        int random_index = rand() % num_choices;

        printf("%c\n", choices[random_index]);

        move(&player, choices[random_index]);
    }
    

    // Libération de la mémoire
    free_map(map);
    return 0;
}