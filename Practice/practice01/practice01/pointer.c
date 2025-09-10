#include <stdio.h>

int PrintPointerTest() {
	int x = 10;

	int* p1 = &x; // x�� �ּҸ� p1�� ����	
	*(p1) = 50; // p1�� ����Ű�� �ּ��� �� ���� (x�� �� ����)

	printf("&x : %lld\n", (long long)&x); // ���� x�� �ּ� ���
	printf("p1 : %lld\n", (long long)p1); // ������ p1�� ����Ű�� �ּ� ���

	printf("x : %d\n", x);   // ���� x�� �� ��� (������� ����)
}

int main() {
	PrintPointerTest();
	return 0;
}