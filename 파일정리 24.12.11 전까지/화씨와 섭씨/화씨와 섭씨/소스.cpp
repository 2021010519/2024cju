#include <stdio.h>

int trans(int x, char cf);

int main()
{
	int cu;
	char cf;
	int result;


	printf("in put(count, c or f?)"); // ���ڰ��� �������� ȭ������ �Է� ����//
	scanf_s("%d %c", &cu, &cf, sizeof(cf)); // ���ڿ� c���� f���� �Է¹���//      

	result = trans(cu, cf); //trans �Լ� �ҷ���//
	printf("result : %d", result);

	return 0;
}
int trans(int x, char cf) // //�Լ� ���� char�� y�� �Ⱦ� ������ �Ǽ��� cf�� �̹� �Լ��� �� �ϼ���Ű�� �ڴʰ� cf�� ������� �ñ� ����//
{
	int trn;

	if ('cf' == 'c') //���� c�� ������ �Է¹޾Ҵٸ�//
	{
		trn = (int)(x * 1.8 + 32);
	}
	else if ('cf' == 'f') //���� f��,ȭ���� �Է� �޾Ҵٸ�//
	{
		trn = (int)((x - 32) / 1.8);
	}
	else
	{
		printf("no,no,no");
	}

	return trn; // ��ȯ//

}