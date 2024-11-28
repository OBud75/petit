#include "lib-quadrichaine.h"

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
    
    char input;
    setNonCanonicalMode(1);   
    do
    {
        system("clear");

        printf("\n--------------------------------------------------\n");
        printf("Menu:\nz-Monter\nd-Droite\ns-Descendre\nq-Gauche\n.-Quitter\n");
        printf("\n--------------------------------------------------\n");
        get_map(&map, &player);

        printf("Utilisez les flèches directionnelles pour déplacer le joueur. Appuyez sur 'q' pour quitter.\n");
        input = getDirection();

        move(&player, input);
    } while(input != 'q');
    setNonCanonicalMode(0);
    

    // Libération de la mémoire
    free_map(map);
    return 0;
}