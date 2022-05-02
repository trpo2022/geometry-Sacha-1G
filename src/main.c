#include <geometry/geometry.h>

int main()
{
    FILE* file = fopen("input.txt", "r");
    int number_of_figures;

    printf("Enter the number figures : ");
    scanf("%d", &number_of_figures);
    printf("\n");
    for (int p = 0; p < number_of_figures; p++) {
        char* figure = malloc(sizeof(char) * 100);
        fgets(figure, 100, file);
        printf("%s\n", figure);
    }
    fclose(file);

    return 0;
}