#include <stdio.h>

int trans(int x, char cf);

int main()
{
	int cu;
	char cf;
	int result;


	printf("in put(count, c or f?)"); // 숫자값과 섭씨인지 화씨인지 입력 받음//
	scanf_s("%d %c", &cu, &cf, sizeof(cf)); // 숫자와 c인지 f인지 입력받음//      

	result = trans(cu, cf); //trans 함수 불러옴//
	printf("result : %d", result);

	return 0;
}
int trans(int x, char cf) // //함수 설정 char에 y를 안쓴 이유는 실수로 cf로 이미 함수를 다 완성시키고 뒤늦게 cf로 만든것을 봤기 때문//
{
	int trn;

	if ('cf' == 'c') //만약 c즉 섭씨로 입력받았다면//
	{
		trn = (int)(x * 1.8 + 32);
	}
	else if ('cf' == 'f') //만약 f즉,화씨로 입력 받았다면//
	{
		trn = (int)((x - 32) / 1.8);
	}
	else
	{
		printf("no,no,no");
	}

	return trn; // 반환//

}