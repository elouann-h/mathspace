//
// Created by pxndxdev on 2022/10/17.
//

#include "twodims.h"

#include <stdio.h>

int main(void) {
    // Create a triangle
    struct Triangle2D triangle = Triangle2D.new(
            Point2D.new(1, 2),
            Point2D.new(3, 4),
            Point2D.new(5, 6)
    );
    // Print the area of the triangle using Heron's formula
    double triangleArea = triangle.areaTriangle2D(&triangle);
    printf("The area of the triangle is: %f", triangleArea);

    return 0;
}