#include <stdio.h>

int main()
{
	double dor;
	double hi;
	const double pie = 3.14;


	printf("������Ǵ� �簢���� �������� ���̴� ? :");
	scanf_s("%lf%lf", &dor, &hi);
	printf("�ﰢ��: %.1lf, �簢��: %.1lf", dor * dor / 2, dor * dor);

	return 0;
}


	