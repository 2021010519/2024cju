#include <stdio.h>

int main()
{
	int c;


	printf("input int :");
	scanf_s("%d", &c); //���� �Է¹���//

	if (c % 2 == 0) //2�� ������ �� ¦���� 2n���� �������� ������ ������ 2n-1�� Ȧ���� �������� ���´�//
	{
		printf("%d�� ¦�� �Դϴ�.", c);
	}
	else
	{
		printf("%d�� Ȧ�� �Դϴ�.", c);
	}
	return 0;
}