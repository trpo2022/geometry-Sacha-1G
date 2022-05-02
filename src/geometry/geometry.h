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

struct cords cordinates(char* figure);

void print_circle(struct circle circle);

void print_area(struct circle circle);

void print_perimetre(struct circle circle);