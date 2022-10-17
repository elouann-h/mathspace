#include "math.h"

#include <stdio.h>

int main(void) {
    struct Point2D p = Point2D.new(1, 2);
    printf("x=%f, y=%f", p.x, p.y);
}