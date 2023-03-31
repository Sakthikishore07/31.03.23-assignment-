#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct student {
    char name[50];
    int roll_number;
    struct tm birthday;
    struct tm admission_date;
};

int calculate_age(struct tm birthday, struct tm admission_date);

int main() {
    struct student s;
    
    printf("Enter student name: ");
    fgets(s.name, 50, stdin);
    
    printf("Enter student roll number: ");
    scanf("%d", &s.roll_number);
    
    printf("Enter student birthday (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &s.birthday.tm_year, &s.birthday.tm_mon, &s.birthday.tm_mday);
    s.birthday.tm_year -= 1900;
    s.birthday.tm_mon -= 1;
    
    printf("Enter student admission date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &s.admission_date.tm_year, &s.admission_date.tm_mon, &s.admission_date.tm_mday);
    s.admission_date.tm_year -= 1900;
    s.admission_date.tm_mon -= 1;
    
    int age = calculate_age(s.birthday, s.admission_date);
    
    printf("\nStudent Information\n");
    printf("Name: %s", s.name);
    printf("Roll Number: %d\n", s.roll_number);
    printf("Birthday: %d-%d-%d\n", s.birthday.tm_year+1900, s.birthday.tm_mon+1, s.birthday.tm_mday);
    printf("Admission Date: %d-%d-%d\n", s.admission_date.tm_year+1900, s.admission_date.tm_mon+1, s.admission_date.tm_mday);
    printf("Age at the time of admission: %d years\n", age);
    
    return 0;
}

int calculate_age(struct tm birthday, struct tm admission_date) {
    time_t t1, t2;
    double seconds;
    int years;
    
    t1 = mktime(&birthday);
    t2 = mktime(&admission_date);
    
    seconds = difftime(t2, t1);
    years = (int) (seconds / (60 * 60 * 24 * 365));
    
    return years;
}

