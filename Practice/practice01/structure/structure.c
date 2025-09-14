#include <stdio.h>

struct Student {
    int id;          // 학번
    char name[20];   // 이름
    float grade;     // 학점
};

int main() {
    struct Student s1 = { 1, "Kim", 3.8 };

    printf("ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("Grade: %.2f\n", s1.grade);

    return 0;
}