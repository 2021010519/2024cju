#include <stdio.h>

int main()
{
	int c;
	
	printf("숫자를 입력해 주세요(정수) :"); 
	scanf_s("%d", &c); //값을 입력받음//

	switch (c%2) //짝수인 정수 값을 2로 나눈다면 2n 짝수는 나머지가 없음//
	{
	case(0):
		{
		printf("%d는 짝수입니다.", c);
				break;
		}
		case(1): //홀수인 정수 값을 2로 나눈값이 2n-1인 홀수는 나머지 1 나옴//
		{
			printf("%d는 홀수입니다.", c);
				break;
		}
	default:
	{
		printf("무엇을 입력하신 겁니까 ?");//숫자를 입력하지 않음//
		break;
	}
		
	}
	return 0;
}