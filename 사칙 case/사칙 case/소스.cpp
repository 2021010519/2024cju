#include <stdio.h>

int main()
{
	int x;
	int y;
	int end;
	char ro;

	printf("input (x¤±y :)");
	scanf_s("%d %c %d", &x, &ro, sizeof(ro), &y);
		switch (ro)
		{
			case '+':
			{
				end = x + y;
				break;
			}
			case '-':
			{
				end = x - y;
				break; 
			}
			case '*':
			{
				end = x * y;
				break;
			}
			case ' /':
			{
				end = x / y;
				break; 
			}
			default:
			{
				end = 0; }

	}

		printf("%d", end);

	return 0;
}