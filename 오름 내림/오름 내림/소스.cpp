#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dMax_Num 100.0
#define dMin_Num -100.0


void GenRandSeed()
{
    srand((unsigned int)time(NULL)); // �ð� ���� ������� �õ� ����
}


double GenRandNum(double dRangeMin, double dRangeMax)
{
    double dRns = 0;
    double dNum = rand();
    double dRange = rand();

    double dRns = ((double)rand() / RAND_MAX) * (dRangeMax - dRangeMin) + dRangeMin;

        return dRns;
}


int main()
{
    GenRandSeed();

    double dRandNum[9]; // ũ�Ⱑ 9�� �迭 ����


    for (int i = 0; i < 10; i++)
    {
        dRandNum[i] = GenRandNum(dMin_Num, dMax_Num);
    }


    printf("random numbers:\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%.1f\n", dRandNum[i]);
    }

    return 0;
}
