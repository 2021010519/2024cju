#include <stdio.h>

int main()
{
	double dor;
	double hi;

	const double slug = 14.5939;
	const double ft = 0.3048;


	printf("si로 변환할 FPS값은 ?(ft,slug) :");
	scanf_s("%lf%lf", &dor, &hi);
	printf("m: %.1lf, kg: %.1lf", dor *ft , hi * slug);

	return 0;
}