#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "kppv.h"
#include "mlv.h"
#include <MLV/MLV_all.h>

#define TRUE 0
#define FALSE 1

void run_programme()
{
    int count = 0;
    int max_size; /*La taille maximal*/
    int dim;      /*La dimension*/
    int nb_class; /*nombre de la classe*/
    char *fichier;
    int x, y;
    char *KNN;
    int k = 0;
    point *p = NULL;
    point cercle;
    point *indices;
    FILE *f = NULL;
    int endProgramme = FALSE;

    afficher_zone();
    while (endProgramme)
    {
        /*affichage graphique des points du fichier*/

        MLV_wait_mouse(&x, &y);

        if ((x >= 65) && (x <= 190) && (y >= 40) && (y <= 90))
        {
            mode_creation(p);
        }

        if ((x >= 300) && (x <= 425) && (y >= 40) && (y <= 90))
        {
            MLV_wait_input_box(300, 100, 125, 50,
                               MLV_COLOR_WHITE, MLV_COLOR_WHITE,
                               MLV_COLOR_BLACK, " Fichier: ", &fichier);
            MLV_actualise_window();

            f = fopen(fichier, "r");

            if (f == NULL)
            {
                MLV_draw_text(300, 120, "Ce fichier n'existe pas.", MLV_COLOR_RED);
                MLV_actualise_window();
                MLV_wait_seconds(5);
                afficher_zone();
            }
            else
            {
                afficher_zone();
                MLV_draw_text(300, 120, "OK!", MLV_COLOR_GREEN);
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
        }

        /*choose cercle*/
        if ((x >= 65) && (x <= 585) & (y >= 165) & (y <= 785))
        {
            if (count == 0)
            {
                choose_cercle(cercle);
                count++;
            }
        }

        /*input num K*/
        if ((x >= 450) && (x <= 575) && (y >= 40) && (y <= 90))
        {
            MLV_wait_input_box(450, 100, 125, 50,
                               MLV_COLOR_WHITE, MLV_COLOR_WHITE,
                               MLV_COLOR_BLACK, " k =  ", &KNN);

            MLV_draw_text(450, 120, KNN, MLV_COLOR_GREEN);

            k = atoi(KNN);
            MLV_actualise_window();
        }

        if ((x >= 400) && (x <= 525) && (y >= 40) && (y <= 90))
        {
        }

        if ((x >= 585) && (x <= 755) && (y >= 450) && (y <= 500))
        {
            indices = (point *)malloc(k * sizeof(struct Point));
            indices = k_nearest_neighbors(p, cercle, max_size, k);
            classer(indices, nb_class, k);
        }

        /*
        if ((x >= 800) && (x <= 900) && (y >= 40) && (y <= 90))
        {
            endProgramme = TRUE;
        }
        */
    }
    free(p);
    free(indices);
    fclose(f);
}

int main()
{
    /*Initialisation de la fenêtre graphique*/
    MLV_create_window("Points en 2D", "Points en 2D", WINDOW_WIDTH, WINDOW_HEIGHT);

    run_programme();

    /*Fermeture de la fenêtre graphique*/
    MLV_free_window();

    return 0;
}
