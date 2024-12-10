#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Max_Size 100
#define Choice_Size 10

int nNum[Max_Size];

// ���� ��� �Լ� //
void nCalculate_Sum(int* nArr, int nSize, int* nResult)
{
    *nResult = 0;
    for (int i = 0; i < nSize; i++)
    {
        *nResult += nArr[i];
    }
}

// �л� ��� �Լ�//
double dCalculate_Variance(int* nArr, int nSize, double dMean)
{
    double dResult = 0.0;
    for (int i = 0; i < nSize; i++) {
        dResult += pow((nArr[i] - dMean), 2);
    }
    dResult /= nSize;
    return dResult;  // �л� ��ȯ//
}

// ǥ������ ��� �Լ� //
void Calculate_Stddev(double dVariance, double* dResult)
{
    *dResult = sqrt(dVariance);
}

int main()
{
    int nChoice[Choice_Size];
    int nLowerBound = 10, nUpperBound = 100;

    int nSum = 0;
    double dMean = 0.0;
    double dVariance = 0.0;
    double dStddev = 0.0;

    dMean = (double)nSum / Choice_Size; //���//


    srand(time(NULL));

    // ������ ���� 100�� ����//
    printf("Generated 100 random numbers:\n");
    for (int i = 0; i < Max_Size; i++)
    {
        nNum[i] = (rand() % (nUpperBound - nLowerBound + 1)) + nLowerBound;
        printf("%d ", nNum[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }

    // �������� 10���� ���� ����//
    printf("\Randomly selected 10 numbers:\n");
    for (int i = 0; i < Choice_Size; i++)
    {
        nChoice[i] = nNum[rand() % Max_Size];
        printf("%d ", nChoice[i]);
    }
    printf("\n");

    // ���� ��� �Լ� �ҷ�����//
    nCalculate_Sum(nChoice, Choice_Size, &nSum);

    // �л� ��� �Լ� �ҷ����� //
    dVariance = dCalculate_Variance(nChoice, Choice_Size, dMean);

    // ǥ������ ��� �Լ� �ҷ�����//
    Calculate_Stddev(dVariance, &dStddev);

    // ��� ���//
    printf("\Results:\n");
    printf("Sum: %d\n", nSum);
    printf("Variance: %.2f\n", dVariance);
    printf("Standard Deviation: %.2f\n", dStddev);

    return 0;
}