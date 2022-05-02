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