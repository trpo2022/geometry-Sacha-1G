#include <geometry/geometry.h>

int main()
{
    FILE* file = fopen("input.txt", "r");
    int number_of_figures;
    struct circle circle;

    printf("Enter the number figures : ");
    scanf("%d", &number_of_figures);
    printf("\n");
    for (int p = 0; p < number_of_figures; p++) {
        char* figure = malloc(sizeof(char) * 100);
        fgets(figure, 100, file);
        circle.name = name_figure(figure);
        circle.cords = cordinates(figure);
        print_circle(circle);
        print_area(circle);
        print_perimetre(circle);
    }
    fclose(file);

    return 0;
}