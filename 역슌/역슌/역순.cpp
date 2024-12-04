#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dMax_Num 100.0
#define dMin_Num -100.0


void GenRandSeed()
{
    srand((unsigned int)time(NULL)); // �ð� ���� ������� �õ� ����
}

// �־��� ���� ������ ���� ���� �Լ�
double GenRandNum(double dRangeMin, double dRangeMax)
{
    double dRns = ((double)rand() / RAND_MAX) * (dRangeMax - dRangeMin) + dRangeMin;
    return dRns;
}



int main()
{
    GenRandSeed();

    double dRandNum[10]; //���� �߻����� �迭ũ�� [9] ���� [10]���� �ø�//


    for (int i = 0; i < 10; i++)
    {
        dRandNum[i] = GenRandNum(dMin_Num, dMax_Num);
    }


    printf("Random numbers:\n"); //�� ���
    for (int i = 0; i < 10; i++)
    {
        printf("%.1f\n", dRandNum[i]);
    }

    for (int i = 0; i < 5; i++)  
    {
        double temp = *(dRandNum + i);  // 1,10 2,9 �̷������� 5�� ��ȯ�� ���� ��ġ �ٲ�//
        *(dRandNum + i) = *(dRandNum + 9 - i);  
        *(dRandNum + 9 - i) = temp;  
    }


    printf("Random numbers:\n"); //���� ���//
    for (int i = 0; i < 10; i++)
    {
        printf("%.1f\n", dRandNum[i]);
    }

    return 0;
}
