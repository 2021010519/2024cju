#include <stdio.h>

int main()
{
	double p;	//point//

	printf("input int (0~100.0) :");
	scanf_s("%lf", &p);

	p = (p < 30.0) ? 0 : (p >= 30.0 && p < 45.0) ? 1 : (p >= 45.0 && p < 55.0) ? 2 : (p >= 45.0 && p < 55.0) ? 3 : (p >= 55.0 && p < 70.0) ? 4 : (p >= 70.0 && p < 75.0) ? 5 : (p >= 75.0 && p < 80.0) ? 6 : (p >= 80 && p < 90) ? 7 : 8; 
	//�����ڸ� ����Ͽ� case ���� �����ϰ� p�� ������ ������ ����ȭ//

		switch (int(p)) // �Ǽ���p�� switch���� ����� �� ���� int ��, ���������� p�� �ٲ� �Է�//
		{
			{
		case(0): // 0<p<30���� ����ȭ�� ���� �Է� �Ʒ��� ����//
			printf("f �Դϴ�.");
					break;
			}
			{
		case(1):
			printf("c �Դϴ�.");
			break;
			}
			{
		case(2):
			printf("c+ �Դϴ�.");
			break;
			}
			{
		case(3):
			printf("b- �Դϴ�.");
			break;
			}
			{
		case(4):
			printf("b �Դϴ�.");
			break;
			}
			{
		case(5):
			printf("b+ �Դϴ�.");
			break;
			}
			{
		case(6):
			printf("a- �Դϴ�.");
			break;
			}
			{
		case(7):
			printf("a �Դϴ�.");
			break;
			}
			{
		case(8):
			printf("a+ �Դϴ�.");
			break;
			}

		default:
			printf("����, ����.");
			break;
		}


	return 0;
}
