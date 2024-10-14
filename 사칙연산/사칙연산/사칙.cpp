#include <stdio.h>

int main()
{
	int x;
	int y;
	char co; //count//
	int end = 0;


	printf("input value(int) : ");
	scanf_s("%d %c %d", &x, &co, sizeof(co), &y);
	if (co == '+')
	{
		end = x + y;
	}
	else if (co == '-')
	{
		end = x - y;
	}
	else if (co == '*')
	{
		end = x * y;
	}
	else if (co == '/')
	{
		end = x / y;

	}
		printf("%d", end);

		return 0;
	}