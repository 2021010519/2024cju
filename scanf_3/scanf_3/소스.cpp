#include <stdio.h>

int main()
{
	double dor;
	double hi;
	double r;
	const double pie = 3.14;


	printf("삼격형또는 사각형의 반지름과 높이는 원의 반지름은? :");
	scanf_s("%lf%lf", &dor, &hi);
	printf("삼각형: %.1lf, 사각형: %.1lf,원의 부피: %.1lf, 원의 표면적: %.1lf", dor * dor / 2, dor * dor,r*r*pie/2, r * r * pie*4);

	return 0;
}


	