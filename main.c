#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Pi 3.14

struct cir {
    double x;
    double y;
    double r;
};

int main()
{
    FILE* file = fopen("output.txt", "r");

    int i = 0, N = 100, number_of_figures;
    char *str = NULL, cir[] = {"circle"};
    char* num = NULL;
    num = malloc(100 * sizeof(char));
    char* figure = NULL;
    figure = malloc(100 * sizeof(char));

    printf("Enter the number figures : ");
    scanf("%d", &number_of_figures);
    printf("\n");
    for (int p = 0; p < number_of_figures; p++) {
        str = malloc(N * sizeof(char));
        fgets(str, 100, file);

        if (strstr(str, cir) != NULL) { // circle(0 0, 1.5)
            struct cir circle;
            char* cor1 = malloc(20 * sizeof(char));
            char* cor2 = malloc(20 * sizeof(char));
            char* rad = malloc(20 * sizeof(char));
            while (str[i] != '\0') {
                if ((str[i] >= 'A' && str[i] <= 'Z')
                    || (str[i] >= 'a' && str[i] <= 'z')) {
                    strncat(figure, &str[i], 1);
                }
                i++;
            }
            i = 0;
            while (str[i] != ')') {
                if (str[i] == '-')
                    strncat(num, &str[i], 1);
                if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
                    strncat(num, &str[i], 1);
                }
                i++;
                if (str[i] == ' ' && str[i - 1] != ',') {
                    strcpy(cor1, num);
                    strcpy(num, "");
                    circle.x = atof(cor1);
                }
                if (str[i] == ',') {
                    strcpy(cor2, num);
                    strcpy(num, "");
                    circle.y = atof(cor2);
                }
                if (str[i] == ')') {
                    strcpy(rad, num);
                    strcpy(num, "");
                    circle.r = atof(rad);
                }
            }
            printf("%s(%.1f %.1f, %.1f)\n",
                   figure,
                   circle.x,
                   circle.y,
                   circle.r);
            if (circle.r < 0) {
                printf("Error, radius < 0\n");
                return -1;
            }
        }
    }
    fclose(file);

    return 0;
}