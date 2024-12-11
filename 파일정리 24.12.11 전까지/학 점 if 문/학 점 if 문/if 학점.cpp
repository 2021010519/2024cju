#include <stdio.h>

int main()
{
    double p;  

    printf("input float (0~100.0): ");
    scanf_s("%lf", &p);  // 실수형으로 입력받음//

    if (p)
    {
        if (p < 30.0)  
        {
            printf("c 입니다");
        }
        else if (p >= 30.0 && p < 45.0) // 30<=p<45는 인식하지 못하므로 연산자를 사용함//
        {
            printf("c+ 입니다");
        }
        else if (p >= 45.0 && p < 55.0)// 위와 같음//
        {
            printf("b- 입니다");
        }
        else if (p >= 55.0 && p < 70.0)
        {
            printf("b 입니다");
        }
        else if (p >= 70.0 && p < 75.0)
        {
            printf("b+ 입니다");
        }
        else if (p >= 75.0 && p < 80.0)
        {
            printf("a- 입니다");
        }
        else if (p >= 80.0 && p < 90.0)
        {
            printf("a 입니다");
        }
        else if (p >= 90.0)
        {
            printf("a+ 입니다");
        }
    }
    return 0;
}
