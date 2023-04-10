#include "mlv.h"
#include "kppv.h"

void afficher_zone()
{
    /*creation de l'interface graphique avec option*/
    MLV_draw_rectangle(
        65, 165, 520, 520, MLV_COLOR_WHITE);

    MLV_draw_text_box(65, 40, 125, 50, "Mode création", 2,
                      MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK,
                      MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_draw_text_box(230, 40, 125, 50, "Mode KPPV", 2,
                      MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER,
                      MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_draw_text_box(425, 40, 125, 50, "Valeur de k", 2,
                      MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER,
                      MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(800, 40, 180, 50, "Réinitialiser la fenêtre", 2,
                      MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER,
                      MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(585, 400, 200, 50, "Supprimer le dernier point", 2,
                      MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER,
                      MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(585, 450, 200, 50, "Classe du point", 2,
                      MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER,
                      MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    /*actualise la fenetre graphique*/
    MLV_actualise_window();
}

void afficher_points(point *p, int max_size)
{
    int i;
    float x, y;
    for (i = 0; i < max_size; i++)
    {
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
    MLV_actualise_window();
}
