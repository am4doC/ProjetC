#include "mlv.h"

void afficher_zone(point *p, int max_size)
{
    int i;
    float x, y;

    /*creation de l'interface graphique avec option*/
    MLV_draw_rectangle(65, 165, 520, 520, MLV_COLOR_WHITE);

    MLV_draw_text_box(100, 100, 125, 50, "Mode création", 2, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(225, 100, 125, 50, "Mode KPPV", 2, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(425, 100, 125, 50, "Valeur de k", 2, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(800, 100, 180, 50, "Réinitialiser la fenêtre", 2, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(585, 400, 200, 50, "Supprimer le dernier point", 2, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(585, 450, 200, 50, "Classe du point", 2, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    /*Affichage des points*/
    for (i = 0; i < max_size; i++)
    {

        /*switch ((p+1)->class_label){
          case 1:
          MLV_draw_filled_circle((p + i)->x * (800 / 2) + 800 / 2, (p + i)->y * (800 / 2) + 1000 / 2,POINT_SIZE, MLV_COLOR_BLUE);
          break;
          case 2:
          MLV_draw_filled_circle((p + i)->x * (1000 / 2) + 900 / 2, (p + i)->y * (1000 / 2) + 1000 / 2, POINT_SIZE, MLV_COLOR_RED);
          break;
          }*/
        x = ((500 / 2 * (p + i)->x) + (500 / 2) + 75);
        y = ((500 / 2 * (p + i)->y) + (500 / 2) + 175);
        if ((p + i)->class_label == 1)
        {

            MLV_draw_filled_circle(x, y,
                                   POINT_SIZE, MLV_COLOR_BLUE);
        }
        else
        {
            if ((p + i)->class_label == 2)
            {

                MLV_draw_filled_circle(x, y,
                                       POINT_SIZE, MLV_COLOR_RED);
            }
        }
    }

    /*actualise la fenetre graphique*/
    MLV_actualise_window();

    /*Attendre la fin du programme*/
    MLV_wait_seconds(20);
}
