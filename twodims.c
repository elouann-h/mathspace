//
// Created by pxndxdev on 2022/10/17.
//

#include "twodims.h"

#include <math.h>
#include <stdio.h>

// STRUCTURE: Point2D
/**
 * Point in 2 Dimensional Space
 *
 * @param x The x coordinate of the point
 * @param y The y coordinate of the point
 */
static struct Point2D newPoint2D(double x, double y) {
    return (struct Point2D){.x=x, .y=y};
}
const struct Point2DClass Point2D={.new=&newPoint2D};


// STRUCTURE: Segment2D
/**
 * Return the length of a Segment2D instance
 *
 * @param this The Segment2D instance
 */
static double lengthSegment2D(struct Segment2D *this) {
    // Get the difference between the x and y coordinates of the two end points
    double firstTerm = pow(this->secondExtremity.x - this->firstExtremity.x, 2);
    double secondTerm = pow(this->secondExtremity.y - this->firstExtremity.y, 2);
    // Return the square root of the sum of the squares of the differences
    double length = sqrt(firstTerm + secondTerm);
    return length;
}
/**
 * Segment in 2 Dimensional Space
 * Use two structures of Point2D as the end points
 *
 * @param firstExtremity The first end point of the segment
 * @param secondExtremity The second end point of the segment
 */
static struct Segment2D newSegment2D(struct Point2D firstExtremity, struct Point2D secondExtremity) {
    return (struct Segment2D) {
        .firstExtremity=firstExtremity,
        .secondExtremity=secondExtremity,
        .lengthSegment2D=lengthSegment2D
    };
}
const struct Segment2DClass Segment2D={.new=&newSegment2D};


// STRUCTURE: SlopingLine2D
/**
 * Return the x intercept of a SlopingLine2D instance
 *
 * @param this The SlopingLine2D instance
 */
static double xIntercept(struct SlopingLine2D *this) {
    // Get the x intercept of the line
    double xIntercept = -this->yIntercept / this->leadingCoefficient;
    return xIntercept;
}
/**
 * Line which cannot be vertical in 2 Dimensional Space
 *
 * @param leadingCoefficient The leading coefficient of the line
 * @param yIntercept The y-intercept of the line
 */
static struct SlopingLine2D newSlopingLine2D(double leadingCoefficient, double yIntercept) {
    return (struct SlopingLine2D) {
        .leadingCoefficient=leadingCoefficient,
        .yIntercept=yIntercept,
        .xIntercept=xIntercept
    };
}
const struct SlopingLine2DClass SlopingLine2D={.new=&newSlopingLine2D};


// STRUCTURE: Square2D
/**
 * Return the area of a Square2D instance
 *
 * @param this The Square2D instance
 */
static double areaSquare2D(struct Square2D *this) {
    return pow(this->width, 2);
}
/**
 * Return the length of the diagonal of a Square2D instance
 *
 * @param this The Square2D instance
 */
static double diagonalLengthSquare2D(struct Square2D *this) {
    // Get the point placed at the opposite corners of the square (bottom right)
    double oppositeVertexX = this->topLeftVertex.x + this->width;
    double oppositeVertexY = this->topLeftVertex.x + this->width;
    // Create a segment with the two points
    struct Point2D oppositeVertex = Point2D.new(oppositeVertexX, oppositeVertexY);
    struct Segment2D diagonal = Segment2D.new(this->topLeftVertex,oppositeVertex);
    // Return the length of the segment
    return diagonal.lengthSegment2D(&diagonal);
}
/**
 * Square in a 2 Dimensional Space
 * Use four structures of Point2D as the corners
 *
 * @param topLeftVertex The top left vertex of the square
 */
static struct Square2D newSquare2D(struct Point2D topLeftVertex, double width) {
    return (struct Square2D) {
        .topLeftVertex=topLeftVertex,
        .width=width,
        .areaSquare2D=areaSquare2D,
        .diagonalLengthSquare2D=diagonalLengthSquare2D
    };
}
const struct Square2DClass Square2D={.new=&newSquare2D};


// STRUCTURE: Triangle2D
/**
 * Returns the perimeter of a Triangle2D instance
 *
 * @param this The Triangle2D instance
 */
static double perimeterTriangle2D(struct Triangle2D *this) {
    // Create three segments with the three points
    struct Segment2D firstSide = Segment2D.new(this->firstVertex, this->secondVertex);
    struct Segment2D secondSide = Segment2D.new(this->secondVertex, this->thirdVertex);
    struct Segment2D thirdSide = Segment2D.new(this->thirdVertex, this->firstVertex);
    // Return the sum of the lengths of the segments
    return firstSide.lengthSegment2D(&firstSide) + secondSide.lengthSegment2D(&secondSide) + thirdSide.lengthSegment2D(&thirdSide);
}
/**
 * Returns the area of a Triangle2D instance using Heron's formula
 *
 * @param this The Triangle2D instance
 */
static double areaTriangle2D(struct Triangle2D *this) {
    // Initialize the variables of the three sides for the Heron's formula
    struct Segment2D triangleBase, triangleSideA, triangleSideC;
    // Initialize and assign the variables of the three sides
    struct Segment2D firstSide = Segment2D.new(this->firstVertex, this->secondVertex);
    struct Segment2D secondSide = Segment2D.new(this->secondVertex, this->thirdVertex);
    struct Segment2D thirdSide = Segment2D.new(this->firstVertex, this->thirdVertex);
    // Get the perimeter of the triangle
    double demiPerimeter = this->perimeterTriangle2D(this) / 2;
    // Initialize the area variable
    double area;

    // Check which side is the base of the triangle
    double firstLength = firstSide.lengthSegment2D(&firstSide);
    double secondLength = secondSide.lengthSegment2D(&secondSide);
    double thirdLength = thirdSide.lengthSegment2D(&thirdSide);

    // Assign the variables of the three sides
    if (firstLength > secondLength) { // The first side is the longest
        if (secondLength > thirdLength || firstLength > thirdLength) {
            triangleBase = firstSide;
            triangleSideA = secondSide;
            triangleSideC = thirdSide;
        }
    }
    else if (secondLength > firstLength) { // The second side is the longest
        if (firstLength > thirdLength || secondLength > thirdLength) {
            triangleBase = secondSide;
            triangleSideA = firstSide;
            triangleSideC = thirdSide;
        }
    }
    else { // The third side is the longest
        triangleBase = thirdSide;
        triangleSideA = firstSide;
        triangleSideC = secondSide;
    }
    // Calculate the area of the triangle using Heron's formula
    area = sqrt(
            demiPerimeter
            * (demiPerimeter - triangleSideA.lengthSegment2D(&triangleSideA))
            * (demiPerimeter - triangleBase.lengthSegment2D(&triangleBase))
            * (demiPerimeter - triangleSideC.lengthSegment2D(&triangleSideC))
            );
    // Return the area of the triangle
    return area;
}
/**
 * Triangle in a 2 Dimensional Space
 * Use three structure of Point2D as the corners
 *
 * @param firstVertex The first vertex of the triangle
 * @param secondVertex The second vertex of the triangle
 * @param thirdVertex The third vertex of the triangle
 */
static struct Triangle2D newTriangle2D(struct Point2D firstVertex, struct Point2D secondVertex, struct Point2D thirdVertex) {
    return (struct Triangle2D) {
        .firstVertex=firstVertex,
        .secondVertex=secondVertex,
        .thirdVertex=thirdVertex,
        .perimeterTriangle2D=perimeterTriangle2D,
        .areaTriangle2D=areaTriangle2D
    };
}
const struct Triangle2DCLass Triangle2D={.new=&newTriangle2D};