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
    double firstTerm = pow(this->secondExtremity.x - this->firstExtremity.x, 2);
    double secondTerm = pow(this->secondExtremity.y - this->firstExtremity.y, 2);
    double length = sqrt(firstTerm + secondTerm);
    return length;
}
static struct Segment2D newSegment2D(struct Point2D firstExtremity, struct Point2D secondExtremity) {
    return (struct Segment2D) {.firstExtremity=firstExtremity, .secondExtremity=secondExtremity, .lengthSegment2D=lengthSegment2D};
}
const struct Segment2DClass Segment2D={.new=&newSegment2D};

/*
 * Square in a 2 Dimensional Space
 * Use four structures of Point2D as the corners
 */
static double areaSquare2D(struct Square2D *this) {
    return pow(this->width, 2);
}
static struct Square2D newSquare2D(struct Point2D topLeftVertex, double width) {
    return (struct Square2D) {.topLeftVertex=topLeftVertex,.width=width,.areaSquare2D=areaSquare2D};
}
const struct Square2DClass Square2D={.new=&newSquare2D};