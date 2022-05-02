#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Pi 3.14

struct cords {
    double cord_x;
    double cord_y;
    double rad;
};

struct circle {
    char* name;
    struct cords cords;
};

char* name_figure(char* figure);