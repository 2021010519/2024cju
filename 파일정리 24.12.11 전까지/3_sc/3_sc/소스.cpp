#include <stdio.h>

int main()
{
	double dor;
	double hi;
	const double pie = 3.14;

	printf("ü���� ���� ������ ��������? :");
	scanf_s("%lf", &dor);
	printf("��:%.1lf ���� ǥ���� :%.1lf", dor * dor*pie/2, dor * dor*pie*4);

	return 0;

}

