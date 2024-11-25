#include <stdio.h>
#include <stdlib.h>

typedef struct Map {
    int height;
    int width;
    struct Block **blocks;
} Map;

typedef struct Block {
    struct Block *top;
    struct Block *right;
    struct Block *bot;
    struct Block *left;
} Block;

typedef struct Player {
    struct Block *position;
} Player;

// Fonction pour créer un map
struct Map set_map(int height, int width) {

    // Allocation pour les pointeurs de lignes
    struct Block **blocks = (struct Block **)malloc( sizeof(Block *) * width * height);
    if (blocks == NULL){
        printf("Allocation de la mémoir impossible pour les blocks");
        return (struct Map){0, 0, NULL}; // Retourne une map vide en cas d'erreur
    }

    struct Block **top = (struct Block **)malloc( sizeof(Block *) * width );
    if (top == NULL){
        printf("Allocation de memoire impossible pour top");
        free(blocks); // Libération de `blocks` avant de retourner
        return (struct Map){0, 0, NULL};
    }

    for (size_t x = 0; x < width; x++)
    {
        top[x] = NULL; //Initialisation à NULL
    }
    
    for (size_t y = 0; y < height; y++){
        
        blocks[y] = (struct Block *)malloc(sizeof(Block) * width); // Allocation pour chaque ligne
        if(blocks[y] == NULL){
            printf("Allocation de mémoir impossible pour la ligne %d\n", y);
            for (size_t k = 0; k < y; k++) free(blocks[k]); // Libère les lignes déja allouées
            free(blocks);
            free(top);
            return (struct Map){height, width, NULL};
        }

        Block *left = NULL; //Initialisation du pointeur gauche
        for (int x = 0; x < width; x++){
            Block *current = &blocks[y][x]; // Lien avec le block courant
            
            current->top = top[x]; // Lien avec le block du dessus
            if(top[x]) current->top->bot = current; // Lien du block du dessus vers le current
            
            current->left = left; // Lien avec le block de gauche
            if(left) current->left->right = current; // Lien du block précédent vers le current
            
            left = current; // Mise à jour de `prev` pour le prochain bloc
        }
        
        // Mise à jour des pointeurs `top` pour la porchiane ligne
        for (int x = 0; x < width; x++) {
            top[x] = &blocks[y][x];
        }
    }

    free(top);
    return (struct Map){height, width, blocks};
}

// Fonction pour libérer la mémoire associée à une Map
void free_map(struct Map map){
    if (map.blocks){
        for (size_t y = 0; y < map.height; y++)
        {
            free(map.blocks[y]); // Libération de chaque ligne
        }
        free(map.blocks); // Libération du tableau principal
    }
    
}

void get_map(Map* map, Player* player){
    if (map == NULL)
    {
        printf("Map invalid");
        return;
    }
    if (player == NULL)
    {
        printf("Player invalid");
    }
    
    printf("-------------------------------------\n");

    for (size_t y = 0; y < map->height; y++)
    {
        for (size_t x = 0; x < map->width; x++)
        {
            if (&map->blocks[y][x] == player->position) printf("X");
            else printf("O");
        }
        printf("\n");
    }

    printf("-------------------------------------\n");
}

struct Player set_player(Map* map){
    return (struct Player){&map->blocks[map->height/2][map->width/2]};
}

void move(Player* player, char direction){
    //direction => 't','r','b','l'
    switch (direction)
    {
    case 't':
        if(player->position->top) player->position = player->position->top;
        else printf("Vous ètes au bord de la carte\n");
        break;

    case 'r':
        if(player->position->right) player->position = player->position->right;
        else printf("Vous ètes au bord de la carte\n");
        break;

    case 'l':
        if(player->position->left) player->position = player->position->left;
        else printf("Vous ètes au bord de la carte\n");
        break;

    case 'b':
        if(player->position->bot) player->position = player->position->bot;
        else printf("Vous ètes au bord de la carte\n");
        break;

    default:
        printf("Choisissez une direction correcte\n");
        break;
    }
}