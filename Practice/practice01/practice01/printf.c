#include <stdio.h>

int main() {
    int age = 25;
    float height = 175.5;
    char grade = 'A';
    char name[] = "Lee";

    printf("�̸�: %s\n", name);       // ���ڿ� ���
    printf("����: %d\n", age);        // ���� ���
    printf("Ű: %.1fcm\n", height);   // �Ҽ��� 1�ڸ� ���
    printf("����: %c\n", grade);      // ���� ���

    return 0;
}
