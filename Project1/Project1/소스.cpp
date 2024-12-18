#include <stdio.h>

int main()
{
	FILE *fp;

	fopen_s(&fp, "C:\\Users\\User\\Documents\\Downloads\\asd.txt", "r");
	if (fp == NULL)
	{
		printf("1");
		return 1;
	}
	printf("2");
		fclose(fp);

	return 0;

}