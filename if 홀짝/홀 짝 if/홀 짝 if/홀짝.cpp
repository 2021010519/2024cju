#include <stdio.h>

int main()
{
	int c;


	printf("input int :");
	scanf_s("%d", &c); //값을 입력받음//

	if (c % 2 == 0) //2로 나눳을 때 짝수인 2n값은 나머지가 나오지 않으며 2n-1인 홀수는 나머지가 나온다//
	{
		printf("%d는 짝수 입니다.", c);
	}
	else
	{
		printf("%d는 홀수 입니다.", c);
	}
	return 0;
}