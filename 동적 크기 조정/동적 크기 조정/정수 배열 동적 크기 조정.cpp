#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

// 새로운 계산 함수 //
void calculateStatistics(int* nArr, int nSize, int* nSum, double* dMean, double* dVariance, double* dStddev)
{
    // 총합 계산 //
    nCalculate_Sum(nArr, nSize, nSum);

    // 평균 계산 //
    dCalculate_Mean(nArr, nSize, dMean);

    // 분산 계산 //
    dCalculate_Variance(nArr, nSize, dMean, dVariance);

    // 표준편차 계산 //
    Calculate_Stddev(dVariance, dStddev);
}

int main()
{
    int nNum[20]; // 배열 크기를 넉넉히 설정
    int size, size_p, size_plus;
    int nSum = 0;
    double dMean = 0.0, dVariance = 0.0, dStddev = 0.0;

    // 초기 배열 입력 //
    printf("초기 배열 크기: ");
    scanf_s("%d", &size);

    printf("입력된 값: ");
    for (int i = 0; i < size; i++)
    {
        scanf_s("%d", &nNum[i]);
    }

    // 초기 통계 계산 //
    calculateStatistics(nNum, size, &nSum, &dMean, &dVariance, &dStddev);

    printf("합계: %d\n", nSum);
    printf("평균: %.2f\n", dMean);
    printf("분산: %.2f\n", dVariance);
    printf("표준편차: %.2f\n", dStddev);

    // 추가 배열 입력 //
    printf("추가 배열 크기: ");
    scanf_s("%d", &size_p);

    printf("추가 입력된 값: ");
    for (int i = size; i < size + size_p; i++)
    {
        scanf_s("%d", &nNum[i]);
    }

    // 새로운 통계 계산 //
    size_plus = size + size_p;
    calculateStatistics(nNum, size_plus, &nSum, &dMean, &dVariance, &dStddev);

    printf("새로운 합계: %d\n", nSum);
    printf("새로운 평균: %.2f\n", dMean);
    printf("새로운 분산: %.2f\n", dVariance);
    printf("새로운 표준 편차: %.2f\n", dStddev);

    return 0;
}

