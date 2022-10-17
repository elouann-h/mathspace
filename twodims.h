//
// Created by pxndxdev on 2022/10/17.
//

#ifndef MATHSPACE_TWODIMS_H
#define MATHSPACE_TWODIMS_H

/*
 * Point in 2 Dimensional Space
 */
struct Point2D {
    double x;
    double y;
};
extern const struct Point2DClass {
    struct Point2D (*new)(double x, double y);
} Point2D;

/*
 * Segment in 2 Dimensional Space
 * Use two structures of Point2D as the end points
 */
struct Segment2D {
    struct Point2D p1, p2;
    double (*lengthSegment2D)(struct Segment2D *this);
};
extern const struct Segment2DClass {
    struct Segment2D (*new)(struct Point2D p1, struct Point2D p2);
} Segment2D;

#endif //MATHSPACE_TWODIMS_H
