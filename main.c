//
// Created by pxndxdev on 2022/10/17.
//

#include "twodims.h"

#include <stdio.h>
#include <math.h>

int main(void) {
    printf("Hello, World!\n");
    // Create points and segments
    struct Point2D a = Point2D.new(4., 7.);
    struct Point2D b = Point2D.new(2., 3.);
    struct Segment2D s = Segment2D.new(a, b);

    // Get some variables properties of segment [AB]
    double segmentABLength = s.lengthSegment2D(&s);
    printf("Length of the segment: %f\n", segmentABLength);
    printf("Square root of 20:%f\n", sqrt(20));

    // Create a square which starts at (x,y) of A
    struct Square2D sq = Square2D.new(a, segmentABLength);
    printf("Area of the square \"sq\": %f\n", sq.areaSquare2D(&sq));

    return 0;
}