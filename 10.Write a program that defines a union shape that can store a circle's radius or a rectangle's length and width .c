#include <stdio.h>

union shape {
  float radius;
  struct {
    float length;
    float width;
  } rectangle;
};

int main() {
  union shape s;
  char shape_type;

  printf("Enter the type of shape you want to calculate (c for circle, r for rectangle): ");
  scanf("%c", &shape_type);

  if (shape_type == 'c') {
    printf("Enter the radius of the circle: ");
    scanf("%f", &s.radius);
    printf("Area of the circle: %.2f\n", 3.14 * s.radius * s.radius);
  }
  else if (shape_type == 'r') {
    printf("Enter the length of the rectangle: ");
    scanf("%f", &s.rectangle.length);

    printf("Enter the width of the rectangle: ");
    scanf("%f", &s.rectangle.width);

    printf("Area of the rectangle: %.2f\n", s.rectangle.length * s.rectangle.width);
  }
  else {
    printf("Invalid shape type entered.\n");
  }

  return 0;
}
