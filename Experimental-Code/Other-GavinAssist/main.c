#include <stdio.h>
#include "utils.h"


int main() {
    line_t array[10];
    int size = 10;
    int value = read_lines("lines.txt", array, size);
    for (int i = 0; i < value; i++) {
        printf("%lf %lf %lf %lf\n", array[i].p0.x, array[i].p0.y, array[i].p1.x, array[i].p1.y);
    }
}
