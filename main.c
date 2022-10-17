//
// Created by pxndxdev on 2022/10/17.
//

#include "twodims.h"

#include <stdio.h>

int main(void) {
    printf("Hello, World!");
    // Create a point
    struct Point2D a = Point2D.new(4., 7.);
    printf("Point a: (%f, %f), ", a.x, a.y);
    // Create a second point
    struct Point2D b = Point2D.new(2., 3.);
    printf("Point b: (%f, %f), ", b.x, b.y);
    // Create a segment
    struct Segment2D s = Segment2D.new(a, b);
    printf("%f", s.lengthSegment2D(&s));
}