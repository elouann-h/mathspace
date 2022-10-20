//
// Created by pxndxdev on 2022/10/17.
//

#ifndef MATHSPACE_TWODIMS_H
#define MATHSPACE_TWODIMS_H

struct Point2D {
    double x;
    double y;
    double (*distancePoint2D)(struct Point2D *this, struct Point2D *other);
};
extern const struct Point2DClass {
    struct Point2D (*new)(double x, double y);
} Point2D;

struct Segment2D {
    struct Point2D firstExtremity, secondExtremity;
    double (*lengthSegment2D)(struct Segment2D *this);
};
extern const struct Segment2DClass {
    struct Segment2D (*new)(struct Point2D firstExtremity, struct Point2D secondExtremity);
} Segment2D;

struct SlopingLine2D {
    double leadingCoefficient, yIntercept;
    double (*xIntercept)(struct SlopingLine2D *this);
};
extern const struct SlopingLine2DClass {
    struct SlopingLine2D (*new)(double leadingCoefficient, double yIntercept);
} SlopingLine2D;

struct Square2D {
    struct Point2D topLeftVertex;
    double width;
    double (*areaSquare2D)(struct Square2D *this);
    double (*diagonalLengthSquare2D)(struct Square2D *this);
};
extern const struct Square2DClass {
    struct Square2D (*new)(struct Point2D topLeftVertex, double width);
} Square2D;

struct Triangle2D {
    struct Point2D firstVertex, secondVertex, thirdVertex;
    double (*areaTriangle2D)(struct Triangle2D *this);
    double (*perimeterTriangle2D)(struct Triangle2D *this);
};
extern const struct Triangle2DCLass {
    struct Triangle2D (*new)(struct Point2D firstVertex, struct Point2D secondVertex, struct Point2D thirdVertex);
} Triangle2D;

#endif //MATHSPACE_TWODIMS_H
