#include <stdio.h>

int main()
{
	int c;
	int i;

	printf("in put(2~9):");
	scanf_s("%d", &c); //���� �Է¹���//

	for ( i = 0; i <= 9; i++) // 9�� �ݺ�//
	{
		printf("%dx%d = %d\n", c, i, c * i); //�Է¹��� �� c*0 ���� 10�� �ݺ�// 
	}
	return 0;
}