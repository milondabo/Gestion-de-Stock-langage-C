#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventaire.h"

int main() {
    Inventaire inv = { .taille = 0 };
    int choix;
    char nom[TAILLE_NOM];
    int quantite;

    do {
        printf("\n=== Menu Gestion d'Inventaire ===\n");
        printf("1. Ajouter un produit\n");
        printf("2. Supprimer un produit\n");
        printf("3. Afficher l'inventaire\n");
        printf("4. Rechercher un produit\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                printf("Nom du produit : ");
                fgets(nom, TAILLE_NOM, stdin);
                nom[strcspn(nom, "\n")] = 0;
                printf("Quantité : ");
                scanf("%d", &quantite);
                getchar();
                ajouter_produit(&inv, nom, quantite);
                break;
            case 2:
                printf("Nom du produit à supprimer : ");
                fgets(nom, TAILLE_NOM, stdin);
                nom[strcspn(nom, "\n")] = 0;
                supprimer_produit(&inv, nom);
                break;
            case 3:
                afficher_inventaire(&inv);
                break;
            case 4:
                printf("Nom du produit à rechercher : ");
                fgets(nom, TAILLE_NOM, stdin);
                nom[strcspn(nom, "\n")] = 0;
                rechercher_produit(&inv, nom);
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 5);

    return 0;
}