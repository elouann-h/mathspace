# Mathspace library

There is the first library I made for my own. This library contains structs which are geometric objects.

## Content

Currently, the library contains the following structs:
- Two dimensional geometrical objects: Point, Segment, Square, Triangle

---

# Usages

## 2D geometrical objects

Per default, to use the 2D geometrical objects, you have to import the `two_dimensional` module.

```c
#include "twodims.h"
```

### → Point

---

```c
// Create a point
struct Point2D point = Point2D.new(1, 2);
// Attributes
point.x; // 1, the x coordinate
point.y; // 2, the y coordinate
```

### → Segment

```c
// You will need two points (instances of Point2D)
struct Point2D firstExtremity = Point2D.new(1, 2);
struct Point2D secondExtremity = Point2D.new(3, 4);
// Create a segment
struct Segment2D segment = Segment2D.new(firstExtremity, secondExtremity);
// Attributes
segment.firstExtremity; // Point2D.new(1, 2), the first extremity of the segment
segment.secondExtremity; // Point2D.new(3, 4), the second extremity of the segment
// Methods
segment.lengthSegment2D(&segment); // 2.8284271247461903, the length of the segment
```

### → Square

```c
// You will need one point (instance of Point2D) and one length. The point is the top left corner of the square.
struct Point2D topLeftVertex = Point2D.new(1, 2);
// Create a square
struct Square2D square = Square2D.new(topLeftVertex, 3);
// Attributes
square.topLeftVertex; // Point2D.new(1, 2), the top left corner of the square
square.width; // 3, the length of the square
// Methods
square.areaSquare2D(&square); // 9, the area of the square
square.diagonalLengthSquare2D(&square); // 4.242640687119285, the length of the diagonal of the square
```

### → Triangle

```c
// You will need three points (instances of Point2D)
struct Point2D firstVertex = Point2D.new(1, 1);
struct Point2D secondVertex = Point2D.new(2, 4);
struct Point2D thirdVertex = Point2D.new(1, 6);
// Create a triangle
struct Triangle2D triangle = Triangle2D.new(firstVertex, secondVertex, thirdVertex);
// Attributes
triangle.firstVertex; // Point2D.new(1, 2), the first vertex of the triangle
triangle.secondVertex; // Point2D.new(3, 4), the second vertex of the triangle
triangle.thirdVertex; // Point2D.new(5, 6), the third vertex of the triangle
// Methods
triangle.areaTriangle2D(&triangle); // , the area of the triangle
triangle.perimeterTriangle2D(&triangle); // 6.82842712474619, the perimeter of the triangle
```
