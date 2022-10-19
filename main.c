//
// Created by pxndxdev on 2022/10/17.
//

#include "twodims.h"

#include <stdio.h>

int main(void) {
    // You will need three points (instances of Point2D)
    struct Point2D firstVertex = Point2D.new(1, 1);
    struct Point2D secondVertex = Point2D.new(2, 4);
    struct Point2D thirdVertex = Point2D.new(1, 6);
    // Create a triangle
    struct Triangle2D triangle = Triangle2D.new(firstVertex, secondVertex, thirdVertex);
    // Attributes
    double triangleArea = triangle.areaTriangle2D(&triangle);
    printf("The area of the triangle is: %f", triangleArea);

    return 0;
}