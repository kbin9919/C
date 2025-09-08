#include <stdio.h>

int main() {
    int age = 25;
    float height = 175.5;
    char grade = 'A';
    char name[] = "Lee";

    printf("이름: %s\n", name);       // 문자열 출력
    printf("나이: %d\n", age);        // 정수 출력
    printf("키: %.1fcm\n", height);   // 소수점 1자리 출력
    printf("성적: %c\n", grade);      // 문자 출력

    return 0;
}
