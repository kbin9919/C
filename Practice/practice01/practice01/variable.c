#include <stdio.h>

int add(int a, int b) {   // 외부에서 접근 가능
    return a + b;
}

static int sub(int a, int b) { // 이 파일 내부에서만 사용 가능
    return a - b;
}

int main() {
    int x = add(10, 20);  
    printf("결과: %d\n", x);

    int y = sub(10, 20);  
    printf("결과: %d\n", y);
    return 0;
}
