#include <stdio.h>

int add(int a, int b) {   // �ܺο��� ���� ����
    return a + b;
}

static int sub(int a, int b) { // �� ���� ���ο����� ��� ����
    return a - b;
}

int main() {
    int x = add(10, 20);  
    printf("���: %d\n", x);

    int y = sub(10, 20);  
    printf("���: %d\n", y);
    return 0;
}
