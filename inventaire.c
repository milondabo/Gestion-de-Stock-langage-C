#include <stdio.h>
#include <string.h>
#include "inventaire.h"

void ajouter_produit(Inventaire* inv, const char* nom, int quantite) {
    for (int i = 0; i < inv->taille; i++) {
        if (strcmp(inv->produits[i].nom, nom) == 0) {
            inv->produits[i].quantite += quantite;
            printf("Quantité de '%s' mise à jour. Nouvelle quantité : %d\n", nom, inv->produits[i].quantite);
            return;
        }
    }
    if (inv->taille < MAX_PRODUITS) {
        strncpy(inv->produits[inv->taille].nom, nom, TAILLE_NOM);
        inv->produits[inv->taille].quantite = quantite;
        inv->taille++;
        printf("Produit '%s' ajouté avec la quantité %d.\n", nom, quantite);
    } else {
        printf("Erreur : inventaire plein.\n");
    }
}

void supprimer_produit(Inventaire* inv, const char* nom) {
    for (int i = 0; i < inv->taille; i++) {
        if (strcmp(inv->produits[i].nom, nom) == 0) {
            for (int j = i; j < inv->taille - 1; j++) {
                inv->produits[j] = inv->produits[j + 1];
            }
            inv->taille--;
            printf("Produit '%s' supprimé de l'inventaire.\n", nom);
            return;
        }
    }
    printf("Erreur : le produit '%s' n'existe pas.\n", nom);
}

void afficher_inventaire(const Inventaire* inv) {
    if (inv->taille == 0) {
        printf("L'inventaire est vide.\n");
        return;
    }
    printf("Inventaire actuel :\n");
    for (int i = 0; i < inv->taille; i++) {
        printf("- %s : %d\n", inv->produits[i].nom, inv->produits[i].quantite);
    }
}

int rechercher_produit(const Inventaire* inv, const char* nom) {
    for (int i = 0; i < inv->taille; i++) {
        if (strcmp(inv->produits[i].nom, nom) == 0) {
            printf("Produit '%s' : quantité = %d\n", nom, inv->produits[i].quantite);
            return inv->produits[i].quantite;
        }
    }
    printf("Le produit '%s' n'existe pas dans l'inventaire.\n", nom);
    return -1;
}
