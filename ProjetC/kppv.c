#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "kppv.h"
#include "MLV/MLV_all.h"

float distance(point p1, point p2)
{
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

/*
void open_file(char *fichier, FILE *f)
{
    f = fopen(fichier, "r");
    if (f == NULL)
    {
        MLV_draw_text(360, 120, "Ce fichier n'existe pas.", MLV_COLOR_RED);
    }
    else
    {
        MLV_draw_text(360, 120, "OK!", MLV_COLOR_GREEN);
    }
    MLV_actualise_window();
}
*/

void chargement_fichier(FILE *f, int max_size, int dim, int nb_class, point *p)
{

    /*Ouvrir file argv[1]*/
    int i = 0, n = 0;
    if (f == NULL)
    {
        printf("Error open file\n");
        exit(EXIT_FAILURE);
    }

    printf("%d %d %d\n", max_size, dim, nb_class);

    /*Boucle pour attribuer a la table*/
    while (!feof(f))
    {
        n = fscanf(f, "%d %f %f", &(p + i)->class_label, &(p + i)->x, &(p + i)->y);

        if (n == 3)
        {
            i++;
        }
    }
}

void sauvegarder_fichier(struct Point *p, int max_size, int dim, int nb_class)
{
    int i;
    FILE *f;
    f = fopen("sauvegarder.txt", "w");
    if (f == NULL)
    {
        printf("erreur sauvegarde fichier\n");
        exit(-1);
    }
    fprintf(f, "%d %d %d\n", max_size, dim, nb_class);
    for (i = 0; i < max_size; i++)
    {
        fprintf(f, "%d %f %f\n", (p + 1)->class_label, (p + 1)->x, (p + 1)->y);
    }
}

point *k_nearest_neighbors(point *points, point cercle, int n, int k)
{
    int i, j;
    point tmp;

    /* Créer un tableau pour stocker les indices des K Plus Proches Voisins */
    point *indices = (point *)malloc(k * sizeof(struct Point));

    /*Verifier allouer memoire*/
    /* if (distance == NULL)
       {
       printf("Echec de l'allocation");
       exit(EXIT_FAILURE);
       }*/

    if (indices == NULL)
    {
        printf("Echec de l'allocation");
        exit(EXIT_FAILURE);
    }

    /* Calculer les distances et les stocker dans le tableau */
    for (i = 0; i < n; i++)
    {
        points[i].distance = distance(points[i], cercle);
    }

    /* Trouver les K Plus Proches Voisins en parcourant les distances */
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (points[j].distance > points[j + 1].distance)
            {
                tmp.x = points[j].x;
                tmp.y = points[j].y;
                tmp.class_label = points[j].class_label;
                tmp.distance = points[j].distance;

                points[j].x = points[j + 1].x;
                points[j].y = points[j + 1].y;
                points[j].class_label = points[j + 1].class_label;
                points[j].distance = points[j + 1].distance;

                points[j + 1].x = tmp.x;
                points[j + 1].y = tmp.y;
                points[j + 1].class_label = tmp.class_label;
                points[j + 1].distance = tmp.distance;
            }
        }
    }

    for (i = 0; i < k; i++)
    {
        indices[i].x = points[i].x;
        indices[i].y = points[i].y;
        indices[i].class_label = points[i].class_label;
        indices[i].distance = points[i].distance;
    }

    /* free(distances);*/ /* Libérer la mémoire allouée pour le tableau des distances */
    return indices;
    free(indices); /* Libérer la mémoire allouée pour le tableau des indices */
}

int classer(point *indices, int nb_class, int k)
{
    int i;
    int *count_class;
    int class = 0;
    int compte = 0;
    count_class = (int *)malloc(nb_class * sizeof(int));
    if (count_class == NULL)
    {
        printf("Echec de l'allocation");
        exit(EXIT_FAILURE);
    }
    for (i = 1; i < k; i++)
    {
        count_class[indices[i].class_label]++;
    }
    compte = count_class[1];
    class = 1;
    for (i = 1; i < nb_class; i++)
    {
        if (compte < count_class[i])
        {
            compte = count_class[i];
            class = i;
        }
    }
    MLV_draw_text(450, 120, KNN, MLV_COLOR_GREEN);
    printf("classe de cercle est %d\n", class);
    free(count_class);
    return class;
}
