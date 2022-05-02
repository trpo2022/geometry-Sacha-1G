#include <geometry/geometry.h>

char* name_figure(char* figure)
{
    char* cir = malloc(100 * sizeof(char));
    char circle[] = {"circle"};
    int i = 0;

    while (figure[i] != '(') {
        if ((figure[i] >= 'A' && figure[i] <= 'Z')
            || (figure[i] >= 'a' && figure[i] <= 'z')
            || (figure[i] >= '0' && figure[i] <= '9')) {
            strncat(cir, &figure[i], 1);
        }
        i++;
    }
    if (strcmp(cir, circle) == 0) {
        return cir;
    } else {
        cir = '\0';
        return cir;
    }
}

struct cords cordinates(char* figure)
{
    struct cords cords;
    char* num = malloc(100 * sizeof(char));
    char x[20], y[20], rad[20];
    int i = 0;

    while (figure[i] != ')') {
        if (figure[i] == '-')
            strncat(num, &figure[i], 1);
        if ((figure[i] >= '0' && figure[i] <= '9') || figure[i] == '.') {
            strncat(num, &figure[i], 1);
        }
        i++;
        if (figure[i] == ' ' && figure[i - 1] != ',') {
            strcpy(x, num);
            strcpy(num, "");
            cords.cord_x = atof(x);
        }
        if (figure[i] == ',') {
            strcpy(y, num);
            strcpy(num, "");
            cords.cord_y = atof(y);
        }
        if (figure[i] == ')') {
            strcpy(rad, num);
            strcpy(num, "");
            cords.rad = atof(rad);
        }
    }

    return cords;
}

void print_circle(struct circle circle)
{
    if (!circle.name) {
        printf("\nОшибка в названии фигуры!\n\n");
        return;
    }

    else if (circle.name && circle.cords.rad < 0) {
        printf("\nОшибка в координатах (радиус не может быть отрацательным) "
               "!\n\n");
    }

    else {
        printf("%s(%.1f %.1f, %.1f) \n",
               circle.name,
               circle.cords.cord_x,
               circle.cords.cord_y,
               circle.cords.rad);
    }
}

void print_area(struct circle circle)
{
    if ((circle.cords.rad < 0) || (!circle.name)) {
        return;
    }

    else {
        printf("Area: %.1f\n", Pi * circle.cords.rad * circle.cords.rad);
    }
}

void print_perimetre(struct circle circle)
{
    if ((circle.cords.rad < 0) || (!circle.name)) {
        return;
    }

    else {
        printf("Perimetre: %.1f\n", 2 * Pi * circle.cords.rad);
    }
}
