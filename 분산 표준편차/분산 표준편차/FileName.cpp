#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define nMaxCount 10 // ��� //

// �õ� ���� �Լ� //
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}

// ���� ���� ���� �Լ� ���Ǹ� ���� 100 ���� //
int GenRandNumber()
{
    return rand() % 100;
}

// ���� ��� �Լ� //
int CalculateSum(int sum, double mean, int count)
{
    mean = (double)(sum) / count;
    return mean;
}

// �л� ��� �Լ� //
double CalculateVariance(int sum, int sumOfSquares, int count)
{
    double mean = (double)sum / count;
    double meanOfSquares = (double)sumOfSquares / count;
    return meanOfSquares - (mean * mean);
}

// ���� �Լ�
int main(void)
{
    // �õ� �ʱ�ȭ
    GenRandSeed();

    int sum = 0; //���� //
    int sumOfSquares = 0; //������ ���� ������ ���� //
    int number; // ������ ���� //
    double nMean = 0; // ��� //
    double nVariance; // �л� //
    double nStddev; // ǥ������ //

    printf("10���� ������ ������ �����մϴ�:\n");

    // 10���� ���� ���� ���� �� ��, ������ ��� //
    for (int i = 0; i < nMaxCount; i++)
    {
        number = GenRandNumber();
        printf("%d ", number);

        sum += number; // ���� ���
        sumOfSquares += number * number; // ������ ��� //
    }
    printf("\n");

    // ���� ��� //
    CalculateSum(sum, nMean, nMaxCount);

    // �л� ��� //
    nVariance = CalculateVariance(sum, sumOfSquares, nMaxCount);

    // ǥ������ ���//
    nStddev = sqrt(nVariance); //�л�^2 = ǥ������// 


    printf("����: %d\n", sum);
    printf("�л�: %.2f\n", nVariance);
    printf("ǥ������: %.2f\n", nStddev);

    return 0;
}
