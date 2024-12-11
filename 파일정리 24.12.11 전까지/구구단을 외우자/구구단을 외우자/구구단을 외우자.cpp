#include <stdio.h>

int main()
{
	int c;
	int i;

	printf("in put(2~9):");
	scanf_s("%d", &c); //값을 입력받음//

	for ( i = 0; i <= 9; i++) // 9번 반복//
	{
		printf("%dx%d = %d\n", c, i, c * i); //입력받은 값 c*0 부터 10번 반복// 
	}
	return 0;
}