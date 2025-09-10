#include <stdio.h>

int PrintPointerTest() {
	int x = 10;

	int* p1 = &x; // x의 주소를 p1에 저장	
	*(p1) = 50; // p1이 가리키는 주소의 값 변경 (x의 값 변경)

	printf("&x : %lld\n", (long long)&x); // 변수 x의 주소 출력
	printf("p1 : %lld\n", (long long)p1); // 포인터 p1이 가리키는 주소 출력

	printf("x : %d\n", x);   // 변수 x의 값 출력 (변경되지 않음)
}

int main() {
	PrintPointerTest();
	return 0;
}