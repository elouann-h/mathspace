//
// Created by pxndxdev on 2022/10/17.
//

#include "twodims.h"

#include <stdio.h>
#include <math.h>

int main(void) {
    printf("Hello, World!\n");
    // Create a square at the origin
    struct Point2D a = Point2D.new(7., 7.);
    struct Square2D square = Square2D.new(a, 3);

    printf("Aire:%f\nDiagonale:%f", square.areaSquare2D(&square), square.diagonalLengthSquare2D(&square));

    return 0;
}