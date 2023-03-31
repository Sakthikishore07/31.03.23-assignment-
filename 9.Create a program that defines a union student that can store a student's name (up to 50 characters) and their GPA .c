#include <stdio.h>

union student {
  char name[50];
  float gpa;
};

int main() {
  union student s;

  printf("Enter the student's name: ");
  scanf("%s", s.name);

  printf("Enter the student's GPA: ");
  scanf("%f", &s.gpa);

  printf("Student Name: %s\n", s.name);
  printf("Student GPA: %.2f\n", s.gpa);

  return 0;
}
