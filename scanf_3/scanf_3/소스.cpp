#include <stdio.h>

int main()
{
	double dor;
	double hi;
	double r;
	const double pie = 3.14;


	printf("������Ǵ� �簢���� �������� ���̴� ���� ��������? :");
	scanf_s("%lf%lf", &dor, &hi);
	printf("�ﰢ��: %.1lf, �簢��: %.1lf,���� ����: %.1lf, ���� ǥ����: %.1lf", dor * dor / 2, dor * dor,r*r*pie/2, r * r * pie*4);

	return 0;
}


	