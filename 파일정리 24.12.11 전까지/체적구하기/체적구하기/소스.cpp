#include <stdio.h>

int main()
{
	double dor;
	double hi;
	double r;
	const double pie = 3.14;


	printf("값을 입력하시요(삼,사각형의 밑변과 높이, 원과 구의 반지름");
	scanf_s("%lf%lf%lf", &dor, &hi,&r);
	printf("삼각형: %.1lf, 사각형: %.1lf,원의 부피: %.1lf, 원의 표면적: %.1lf", dor * dor / 2, dor * dor, r * r * pie / 2, r * r * pie * 4);

	return 0;
}