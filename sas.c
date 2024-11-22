#include <stdio.h>

void afficherMenu() {
    printf("=== Gestion des Tâches ===\n");
    printf("1. Ajouter une tâche\n");
    printf("2. Afficher les tâches\n");
    printf("3. Modifier une tâche\n");
    printf("4. Supprimer une tâche\n");
    printf("5. Quitter\n");
    printf("Entrez votre choix: ");
}

int main() {
    int choix;

    do {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Vous avez choisi d'ajouter une tâche.\n");
                break;
            case 2:
                printf("Vous avez choisi d'afficher les tâches.\n");
                break;
            case 3:
                printf("Vous avez choisi de modifier une tâche.\n");
                break;
            case 4:
                printf("Vous avez choisi de supprimer une tâche.\n");
                break;
            case 5:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choix != 5);

    return 0;
}
