#include <stdio.h>

int main(void)
{
	int Nm = 0;
	double tw = 0;

	printf("나이와 키를 입력해주세요 :");
	scanf_s("%d%lf", &Nm,&tw);
	printf("나이는%Nm살, 키는%1lfcm입니다./n", Nm, tw);

	return 0;


}

