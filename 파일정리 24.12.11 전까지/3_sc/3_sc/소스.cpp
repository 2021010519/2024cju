#include <stdio.h>

int main()
{
	double dor;
	double hi;
	const double pie = 3.14;

	printf("체적을 구할 도형의 반지름은? :");
	scanf_s("%lf", &dor);
	printf("원:%.1lf 원의 표면적 :%.1lf", dor * dor*pie/2, dor * dor*pie*4);

	return 0;

}

