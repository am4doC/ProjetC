#include "mlv.h"
#include "kppv.h"

void afficher_zone()
{
    MLV_clear_window(MLV_COLOR_BLACK);
    /*creation de l'interface graphique avec option*/
    MLV_draw_rectangle(
        65, 165, 520, 520, MLV_COLOR_WHITE);

    /*Mode creation*/
    MLV_draw_text_box(65, 40, 125, 50, "Mode création", 2,
                      MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK,
                      MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_draw_text_box(65, 100, 80, 50, "Enregistrer", 2,
                      MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK,
                      MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_draw_text_box(300, 40, 125, 50, "Mode KPPV", 2,
                      MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER,
                      MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_draw_text_box(450, 40, 125, 50, "Valeur de k", 2,
                      MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER,
                      MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_draw_text_box(800, 40, 100, 50, "Quitter", 2,
                      MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER,
                      MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_draw_text_box(585, 350, 200, 50, "Réinitialiser la fenêtre", 2,
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

void choose_cercle(point circle)
{
    int x, y;
    MLV_wait_mouse(&x, &y);
    MLV_draw_circle(x, y, POINT_SIZE, MLV_COLOR_WHITE);
    printf("x = %d, y = %d\n", x, y);
    circle.x = ((float)x - 75 - (500 / 2)) / 250;
    circle.y = ((float)y - 175 - (500 / 2)) / 250;
    printf("x = %f, y = %f\n", circle.x, circle.y);
    MLV_actualise_window();
}

void choose_points(point *point)
{
}

void mode_creation(point *points)
{
    char *c;
    int nb_class;
    int end = 1;
    int i = 0;
    int x, y;
    int count = 0;
    int class;

    MLV_clear_window(MLV_COLOR_BLACK);
    afficher_zone();
    MLV_wait_input_box(190, 40, 100, 50, MLV_COLOR_WHITE,
                       MLV_COLOR_WHITE, MLV_COLOR_BLACK, " Nb Class: ", &c);
    nb_class = atoi(c);

    while (end)
    {
        MLV_wait_mouse(&x, &y);
        if (MLV_BUTTON_LEFT)
            class = 1;
        if (MLV_BUTTON_MIDDLE)
            class = 2;
        if (MLV_BUTTON_RIGHT)
            class = 3;

        if ((x >= 65) && (x <= 585) && (y >= 165) && (y <= 685))
        {
            points[i].x = (x - 75 - (500 / 2)) / 250;
            points[i].y = (y - 175 - (500 / 2)) / 250;
            points[i].class_label = class;
            count++;
        }
        if ((x >= 85) && (x <= 145) && (y >= 100) && (y <= 150))
        {
            sauvegarder_fichier(points, count, 2, nb_class);
            end = 0;
        }
    }
}
