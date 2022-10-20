//
// Created by pxndxdev on 2022/10/17.
//

#include "twodims.h"

#include <stdio.h>

int main(void) {
    struct SlopingLine2D line = SlopingLine2D.new(2, 3);
    printf("The x intercept of the line is %f", line.xIntercept(&line));
    return 0;
}