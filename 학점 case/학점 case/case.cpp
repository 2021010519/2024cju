#include <stdio.h>

int main()
{
	double p;	//point//

	printf("input int (0~100.0) :");
	scanf_s("%lf", &p);

	p = (p < 30.0) ? 0 : (p >= 30.0 && p < 45.0) ? 1 : (p >= 45.0 && p < 55.0) ? 2 : (p >= 55.0 && p < 70.0) ? 3 : (p >= 70.0 && p < 75.0) ? 4 : (p >= 75.0 && p < 80.0) ? 5 : (p >= 80 && p < 90) ? 6 : 7; 
	//연산자를 사용하여 case 문에 적합하게 p의 범위를 간단한 정수화//

		switch (int(p)) // 실수형p는 switch문을 사용할 수 없어 int 즉, 정수형으로 p로 바꿔 입력//
		{
			{
		case(0): // 0<p<30범위 정수화를 통해 입력 아래도 같음//
			printf("f 입니다.");
					break;
			}
			{
		case(1):
			printf("c 입니다.");
			break;
			}
			{
		case(2):
			printf("c+ 입니다.");
			break;
			}
			{
		case(3):
			printf("b- 입니다.");
			break;
			}
			{
		case(4):
			printf("b 입니다.");
			break;
			}
			{
		case(5):
			printf("b+ 입니다.");
			break;
			}
			{
		case(6):
			printf("a- 입니다.");
			break;
			}
			{
		case(7):
			printf("a 입니다.");
			break;
			}
			{
		case(8):
			printf("a+ 입니다.");
			break;
			}

		default:
			printf("오류, 오류.");
			break;
		}


	return 0;
}
