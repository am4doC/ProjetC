#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "kppv.h"
#include "mlv.h"
#include <MLV/MLV_all.h>

int main()
{
    int max_size; /*La taille maximal*/
    int dim;      /*La dimension*/
    int nb_class; /*nombre de la classe*/
    char *fichier;
    int x, y;
    point *p = NULL;
    FILE *f = NULL;

    /*Initialisation de la fenêtre graphique*/
    MLV_create_window("Points en 2D", "Points en 2D", WINDOW_WIDTH, WINDOW_HEIGHT);

    /*affichage graphique des points du fichier*/
    afficher_zone();

    MLV_wait_mouse(&x, &y);
    if ((x >= 65) && (x <= 190) && (y >= 40) && (y <= 90))
    {
    }

    if ((x >= 230) && (x <= 355) && (y >= 40) && (y <= 90))
    {
        MLV_wait_input_box(230, 100, 125, 50,
                           MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, " Fichier: ", &fichier);
        MLV_actualise_window();
    }

    f = fopen(fichier, "r");
    if (f == NULL)
    {
        MLV_draw_text(360, 120, "Ce fichier n'existe pas.", MLV_COLOR_RED);
        MLV_actualise_window();
        MLV_wait_seconds(2);
    }
    else
    {
        MLV_draw_text(360, 120, "OK!", MLV_COLOR_GREEN);
        MLV_actualise_window();
        
        if (fscanf(f, "%d %d %d", &max_size, &dim, &nb_class) != 3)
        {
            printf("erreur fichier pas compatible\n");
            exit(-1);
        }

        /*Allouer l'espace pour la table*/
        p = (point *)malloc(max_size * sizeof(struct Point));

        if (p == NULL)
        {
            fprintf(stderr, "Erreur allocation\n");
            exit(-1);
        }

        /*chargement du fichier*/
        chargement_fichier(f, max_size, dim, nb_class, p);

        afficher_points(p, max_size);
    }

    /* indices = (point *)malloc(k*sizeof(struct Point));
    indices = k_nearest_neighbors(p,cercle,max_size,k);
    */

    MLV_wait_seconds(20);

    /*Fermeture de la fenêtre graphique*/
    MLV_free_window();

    /*Liberation de la memoire*/
    free(p);

    fclose(f);
    return 0;
}
