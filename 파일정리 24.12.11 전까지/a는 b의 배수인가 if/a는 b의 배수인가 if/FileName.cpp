#include <stdio.h>

int main()
{
	int c1;
	int c2; 


	printf("input (c1,c2) :");
	scanf_s("%d %d", &c1, &c2); //값을 입력받음//
	if (c1 % c2 == 0 || c2 % c1 == 0)  //c1 과 c2의 배수 관계를 확인 서로 나눳을 때 나머지가 없다면 배수 관계 단, c1과 c2을 서로 나눠주면서 오류를 방지함 나누기 1 or 나누기2중 하나라도 나머지가 없으면 배수 관계 //
	{
		printf("%d와 %d는 배수관계 입니다.", c1, c2);
	}
	else if (c1 == 0 || c2 == 0)// 둘 중 하나라도 0이라면 값이 나올 수 없음 //
	{
		printf("0으로 나눌수 없습니다");
	}
	else
	{
		printf("%d와 %d는 배수관계가 아닙니다.", c1, c2);
	}
	return 0;
}