//
// Created by pxndxdev on 2022/10/17.
//

#include "twodims.h"

#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    // Create a point
    struct Point2D a = Point2D.new(4., 7.);
    printf("Point a: (%f, %f)\n", a.x, a.y);
    // Create a second point
    struct Point2D b = Point2D.new(2., 3.);
    printf("Point b: (%f, %f)\n", b.x, b.y);
    // Create a segment
    struct Segment2D s = Segment2D.new(a, b);
    printf("Test");
    printf("%f\n", s.lengthSegment2D(&s));
    printf("Test");
}