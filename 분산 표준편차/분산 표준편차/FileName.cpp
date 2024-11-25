#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define nMaxCount 10 // 상수 //

// 시드 생성 함수 //
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}

// 랜덤 숫자 생성 함수 편의를 위해 100 제한 //
int GenRandNumber()
{
    return rand() % 100;
}

// 총합 계산 함수 //
int CalculateSum(int sum, double mean, int count)
{
    mean = (double)(sum) / count;
    return mean;
}

// 분산 계산 함수 //
double CalculateVariance(int sum, int sumOfSquares, int count)
{
    double mean = (double)sum / count;
    double meanOfSquares = (double)sumOfSquares / count;
    return meanOfSquares - (mean * mean);
}

// 메인 함수
int main(void)
{
    // 시드 초기화
    GenRandSeed();

    int sum = 0; //총합 //
    int sumOfSquares = 0; //편차를 위한 총합의 제곱 //
    int number; // 생성된 숫자 //
    double nMean = 0; // 평균 //
    double nVariance; // 분산 //
    double nStddev; // 표준편차 //

    printf("10개의 무작위 정수를 생성합니다:\n");

    // 10개의 랜덤 숫자 생성 및 합, 제곱합 계산 //
    for (int i = 0; i < nMaxCount; i++)
    {
        number = GenRandNumber();
        printf("%d ", number);

        sum += number; // 총합 계산
        sumOfSquares += number * number; // 제곱합 계산 //
    }
    printf("\n");

    // 총합 계산 //
    CalculateSum(sum, nMean, nMaxCount);

    // 분산 계산 //
    nVariance = CalculateVariance(sum, sumOfSquares, nMaxCount);

    // 표준편차 계산//
    nStddev = sqrt(nVariance); //분산^2 = 표준편차// 


    printf("총합: %d\n", sum);
    printf("분산: %.2f\n", nVariance);
    printf("표준편차: %.2f\n", nStddev);

    return 0;
}
