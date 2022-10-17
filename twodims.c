//
// Created by pxndxdev on 2022/10/17.
//

#include "twodims.h"

#include <math.h>
#include <stdio.h>

/*
 * Point in 2 Dimensional Space
 */
static struct Point2D newPoint2D(double x, double y) {
    return (struct Point2D){.x=x, .y=y};
}
const struct Point2DClass Point2D={.new=&newPoint2D};

/*
 * Segment in 2 Dimensional Space
 * Use two structures of Point2D as the end points
 */
static double lengthSegment2D(struct Segment2D *this) {
    printf("lengthSegment2D called");
    double firstTerm = pow(this->p2.x - this->p1.x, 2);
    double secondTerm = pow(this->p2.y - this->p1.y, 2);
    double length = sqrt(firstTerm + secondTerm);
    return length;
}
static struct Segment2D newSegment2D(struct Point2D p1, struct Point2D p2) {
    return (struct Segment2D) {.p1=p1, .p2=p2};
}
const struct Segment2DClass Segment2D={.new=&newSegment2D};