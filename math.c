//
// Created by pxndxdev on 2022/10/17.
//

#include "math.h"

static struct Point2D new(double x, double y) {
    return (struct Point2D){.x=x, .y=y};
}
const struct Point2DClass Point2D={.new=&new};