#include <stdio.h>

struct Student {
    int id;          // �й�
    char name[20];   // �̸�
    float grade;     // ����
};

int main() {
    struct Student s1 = { 1, "Kim", 3.8 };

    printf("ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("Grade: %.2f\n", s1.grade);

    return 0;
}