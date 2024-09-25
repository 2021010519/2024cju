#include <stdio.h>

int main()
{
	double dor;
	double hi;
	const double pie = 3.14;


	printf("삼격형또는 사각형의 반지름과 높이는 ? :");
	scanf_s("%lf%lf", &dor, &hi);
	printf("삼각형: %.1lf, 사각형: %.1lf", dor * dor / 2, dor * dor);

	return 0;
}


	