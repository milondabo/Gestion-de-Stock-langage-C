# Système de Gestion d'Inventaire en C

Ce projet est une application de console robuste développée en **Langage C**, conçue pour gérer un inventaire de produits de manière efficace. Il illustre les principes de la **programmation modulaire** et de la manipulation de structures de données.

## Fonctionnalités
* **Gestion complète (CRUD)** : Ajouter, rechercher, afficher et supprimer des produits.
* **Logique de mise à jour** : Détection automatique des produits existants pour incrémenter les quantités.
* **Sécurité** : Gestion des limites de stockage (MAX_PRODUITS) et nettoyage des entrées utilisateur.

## Architecture du Code
* `inventaire.h` : Définition des structures `Produit` et `Inventaire`, et prototypes des fonctions.
* `inventaire.c` : Implémentation de la logique de gestion (algorithmes de recherche et de décalage pour la suppression).
* `main.c` : Interface utilisateur (menu interactif) et boucle principale du programme.

## Compilation
Utilisez n'importe quel compilateur C (GCC recommandé) :
```bash
gcc main.c inventaire.c -o gestion_inventaire
