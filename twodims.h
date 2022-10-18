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
 *
 * Contains a method for get the length of a segment
 */
struct Segment2D {
    struct Point2D firstExtremity, secondExtremity;
    double (*lengthSegment2D)(struct Segment2D *this);
};
extern const struct Segment2DClass {
    struct Segment2D (*new)(struct Point2D firstExtremity, struct Point2D secondExtremity);
} Segment2D;

/*
 * Square in a 2 Dimensional Space
 * Use four structures of Point2D as the corners
 */
struct Square2D {
    struct Point2D topLeftVertex;
    double width;
    double (*areaSquare2D)(struct Square2D *this);
};
extern const struct Square2DClass {
    struct Square2D (*new)(struct Point2D topLeftVertex, double width);
} Square2D;

#endif //MATHSPACE_TWODIMS_H
