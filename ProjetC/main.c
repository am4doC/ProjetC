#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "kppv.h"
#include "mlv.h"
#include <MLV/MLV_all.h>

int main(int argc, char *argv[]) {
    int max_size; /*La taille maximal*/
    int dim;      /*La dimension*/
    int nb_class; /*nombre de la classe*/
    /* int k;
    point *indices = NULL;
    point cercle;
    float x,y;*/
    point *p=NULL;
    FILE *f;
    
    if (argc != 2) {
        printf("Usage: %s <data_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    /* printf("Entrer x et y: \n");
    scanf("%f %f", &x, &y);
    if ((1 < x) || (x < -1) || (1 < y) || (y < -1))
      {
        printf("x et y doivent être compris entre -1 inclu et 1 inclu\n");
        exit(-1);
      }
    cercle.x = x;
    cercle.y = y;
    
    printf("Entrer K:\n");
    scanf("%d", &k);*/

   

    f = fopen(argv[1], "r");
    if(fscanf(f, "%d %d %d", &max_size, &dim, &nb_class)!=3){
      printf("erreur fichier pas compatible\n");
      exit(-1);
    }
    
    /*Allouer l'espace pour la table*/
    p = (point *)malloc(max_size * sizeof(struct Point));
    
    if(p==NULL){
      fprintf(stderr,"Erreur allocation\n");
      exit(-1);
    }

    /*chargement du fichier*/
    chargement_fichier(f,max_size,dim,nb_class,p);

    /* indices = (point *)malloc(k*sizeof(struct Point));
    indices = k_nearest_neighbors(p,cercle,max_size,k);
    */

    /*Initialisation de la fenêtre graphique*/
    MLV_create_window("Points en 2D", "Points en 2D", WINDOW_WIDTH, WINDOW_HEIGHT);

    
    /*affichage graphique des points du fichier*/
    afficher_zone(p,max_size);

    /*Fermeture de la fenêtre graphique*/
    MLV_free_window();
    
    
    /*Liberation de la memoire*/
    free(p);


    return 0;
}



