//
// Created by pxndxdev on 2022/10/17.
//

#include "twodims.h"

#include <stdio.h>
#include <math.h>

int main(void) {
    // Create a triangle
    struct Point2D firstVertex = Point2D.new(0, 0);
    struct Point2D secondVertex = Point2D.new(0, 1);
    struct Point2D thirdVertex = Point2D.new(1, 0);
    struct Triangle2D triangle = Triangle2D.new(firstVertex, secondVertex, thirdVertex);
    // Print the area of the triangle using Heron's formula
    double triangleArea = triangle.areaTriangle2D(&triangle);
    printf("The area of the triangle is: %f", triangleArea);

    return 0;
}