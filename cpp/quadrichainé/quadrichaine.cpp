#include "quadrichaine.hpp"

void Player::move(char direction){
    //direction => 't','r','b','l'
    Block *newPosition = NULL;

    switch (direction)
    {
        case 't': newPosition = position->top; break;
        case 'r': newPosition = position->right; break;
        case 'l': newPosition = position->left; break;
        case 'b': newPosition = position->bot; break;
        case 'q': printf("Au revoir\n"); return;
        default:
            printf("Choisissez une direction correcte (t, r, l ,b)\n");
            return;
    }

    if (newPosition)
    {
        position = newPosition;
        printf("Déplacement effectué\n");
    }else{
        printf("Vous êtes au bord de la carte\n");
    }
    
}