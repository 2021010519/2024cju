#include <stdio.h>

int main()
{
    double p;  

    printf("input float (0~100.0): ");
    scanf_s("%lf", &p);  // �Ǽ������� �Է¹���//

    if (p)
    {
        if (p < 30.0)  
        {
            printf("c �Դϴ�");
        }
        else if (p >= 30.0 && p < 45.0) // 30<=p<45�� �ν����� ���ϹǷ� �����ڸ� �����//
        {
            printf("c+ �Դϴ�");
        }
        else if (p >= 45.0 && p < 55.0)// ���� ����//
        {
            printf("b- �Դϴ�");
        }
        else if (p >= 55.0 && p < 70.0)
        {
            printf("b �Դϴ�");
        }
        else if (p >= 70.0 && p < 75.0)
        {
            printf("b+ �Դϴ�");
        }
        else if (p >= 75.0 && p < 80.0)
        {
            printf("a- �Դϴ�");
        }
        else if (p >= 80.0 && p < 90.0)
        {
            printf("a �Դϴ�");
        }
        else if (p >= 90.0)
        {
            printf("a+ �Դϴ�");
        }
    }
    return 0;
}
