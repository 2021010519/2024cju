#include <stdio.h>

int	main() 
{
	int A; //�ʱ� a�� ����//
	int B; //�ʱ� b�� ����//
	int a;
	int b;
	int c;//a%b���尪//

	printf("input a and b : ");
	scanf_s("%d %d", &a, &b);
	A = a;
	B = b;

		while (b != 0) //��Ŭ���� ȣ���� a%b==r�̶�� �Ѵٸ� a=b�� b=r�� ��ü �� b�� 0�� �ɶ����� �̰����� �ݺ��Ѵٸ� a���� �ּҰ������ �ȴ�.//
		{
			c = b;
			b = a%b;
			a = c;
		}

		printf("a�� b�� �ִ������� %d�Դϴ�.", a);
		printf("a�� b�� �ּҰ������ %d�Դϴ�.", A*B/a); // A*B=�ּҰ����*�ִ����� ��, A*B/�ִ�����= �ּҰ����

		
	return 0;

}