//
// Created by pxndxdev on 2022/10/17.
//

#ifndef MATHSPACE_MATH_H
#define MATHSPACE_MATH_H

struct Point2D {
    double x;
    double y;
};
extern const struct Point2DClass {
    struct Point2D (*new)(double x, double y);
} Point2D;

#endif //MATHSPACE_MATH_H
