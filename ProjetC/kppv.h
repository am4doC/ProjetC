#ifndef _KPPV_H_
#define _KPPV_H_
#include <MLV/MLV_all.h>
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define POINT_SIZE 2.5

struct Point
{
    float x;
    float y;
    int class_label;
    float distance;
};

typedef struct Point point;

void usage(char *s);
float distance(point p1, point p2);
/*void open_file(char *fichier, FILE *f);*/
void chargement_fichier(FILE *f, int max_size, int dim, int nb_class, struct Point *p);
void afficher_zone();
point *k_nearest_neighbors(point *p, point cercle, int n, int k);
int classer(point *indices, int nb_class, int k);

#endif
