#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#define MAX_PRODUITS 100
#define TAILLE_NOM 50

typedef struct {
    char nom[TAILLE_NOM];
    int quantite;
} Produit;

typedef struct {
    Produit produits[MAX_PRODUITS];
    int taille;
} Inventaire;

void ajouter_produit(Inventaire* inv, const char* nom, int quantite);
void supprimer_produit(Inventaire* inv, const char* nom);
void afficher_inventaire(const Inventaire* inv);
int rechercher_produit(const Inventaire* inv, const char* nom);

#endif
