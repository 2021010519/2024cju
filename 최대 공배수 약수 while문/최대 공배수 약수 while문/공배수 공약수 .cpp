#include <stdio.h>

int	main() 
{
	int A; //초기 a값 저장//
	int B; //초기 b값 저장//
	int a;
	int b;
	int c;//a%b저장값//

	printf("input a and b : ");
	scanf_s("%d %d", &a, &b);
	A = a;
	B = b;

		while (b != 0) //유클리드 호제법 a%b==r이라고 한다면 a=b로 b=r로 대체 후 b가 0이 될때까지 이과정을 반복한다면 a값은 최소공약수가 된다.//
		{
			c = b;
			b = a%b;
			a = c;
		}

		printf("a와 b의 최대공약수는 %d입니다.", a);
		printf("a와 b의 최소공배수는 %d입니다.", A*B/a); // A*B=최소공배수*최대공약수 즉, A*B/최대공약수= 최소공배수

		
	return 0;

}