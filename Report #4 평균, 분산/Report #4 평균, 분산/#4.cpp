#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Max_Size 100
#define Choice_Size 10

int nNum[Max_Size];

// 총합 계산 함수 //
void nCalculate_Sum(int* nArr, int nSize, int* nResult)
{
    *nResult = 0;
    for (int i = 0; i < nSize; i++)
    {
        *nResult += nArr[i];
    }
}

// 평균 계산 함수 //
void dCalculate_Mean(int* nArr, int nSize, double* dResult)
{
    int nSum = 0;
    nCalculate_Sum(nArr, nSize, &nSum);
    *dResult = (double)nSum / nSize;
}

// 분산 계산 함수 //
void dCalculate_Variance(int* nArr, int nSize, double* dMean, double* dResult)
{
    *dResult = 0.0;
    for (int i = 0; i < nSize; i++)
    {
        *dResult += pow((nArr[i] - *dMean), 2);
    }
    *dResult /= nSize; // 분산 반환 //
}

// 표준편차 계산 함수 //
void Calculate_Stddev(double* dVariance, double* dResult)
{
    *dResult = sqrt(*dVariance);
}

int main()
{
    int nChoice[Choice_Size];
    int nLowerBound = 10, nUpperBound = 100;

    int nSum = 0;
    double dMean = 0.0;
    double dVariance = 0.0;
    double dStddev = 0.0;

    srand(time(NULL));

    // 무작위 정수 100개 생성 //
    printf("100 random numbers:\n");
    for (int i = 0; i < Max_Size; i++)
    {
        nNum[i] = (rand() % (nUpperBound - nLowerBound + 1)) + nLowerBound;
        printf("%d ", nNum[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }

    // 무작위로 10개의 정수 추출 //
    printf("\Randomly selected 10 numbers:\n");
    for (int i = 0; i < Choice_Size; i++)
    {
        nChoice[i] = nNum[rand() % Max_Size];
        printf("%d ", nChoice[i]);
    }
    printf("\n");

    // 평균 계산 //
    dCalculate_Mean(nChoice, Choice_Size, &dMean);

    // 분산 계산 //
    dCalculate_Variance(nChoice, Choice_Size, &dMean, &dVariance);

    // 표준편차 계산 //
    Calculate_Stddev(&dVariance, &dStddev);

    // 결과 출력 //
    printf("\Results:\n");
    printf("Sum: %d\n", nSum);
    printf("Variance: %.2f\n", dVariance);
    printf("Standard Deviation: %.2f\n", dStddev);

    return 0;
}
