#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ���� ��� �Լ� //
void nCalculate_Sum(int* nArr, int nSize, int* nResult)
{
    *nResult = 0;
    for (int i = 0; i < nSize; i++)
    {
        *nResult += nArr[i];
    }
}

// ��� ��� �Լ� //
void dCalculate_Mean(int* nArr, int nSize, double* dResult)
{
    int nSum = 0;
    nCalculate_Sum(nArr, nSize, &nSum);
    *dResult = (double)nSum / nSize;
}

// �л� ��� �Լ� //
void dCalculate_Variance(int* nArr, int nSize, double* dMean, double* dResult)
{
    *dResult = 0.0;
    for (int i = 0; i < nSize; i++)
    {
        *dResult += pow((nArr[i] - *dMean), 2);
    }
    *dResult /= nSize; // �л� ��ȯ //
}

// ǥ������ ��� �Լ� //
void Calculate_Stddev(double* dVariance, double* dResult)
{
    *dResult = sqrt(*dVariance);
}

// ���ο� ��� �Լ� //
void calculateStatistics(int* nArr, int nSize, int* nSum, double* dMean, double* dVariance, double* dStddev)
{
    // ���� ��� //
    nCalculate_Sum(nArr, nSize, nSum);

    // ��� ��� //
    dCalculate_Mean(nArr, nSize, dMean);

    // �л� ��� //
    dCalculate_Variance(nArr, nSize, dMean, dVariance);

    // ǥ������ ��� //
    Calculate_Stddev(dVariance, dStddev);
}

int main()
{
    int nNum[20]; // �迭 ũ�⸦ �˳��� ����
    int size, size_p, size_plus;
    int nSum = 0;
    double dMean = 0.0, dVariance = 0.0, dStddev = 0.0;

    // �ʱ� �迭 �Է� //
    printf("�ʱ� �迭 ũ��: ");
    scanf_s("%d", &size);

    printf("�Էµ� ��: ");
    for (int i = 0; i < size; i++)
    {
        scanf_s("%d", &nNum[i]);
    }

    // �ʱ� ��� ��� //
    calculateStatistics(nNum, size, &nSum, &dMean, &dVariance, &dStddev);

    printf("�հ�: %d\n", nSum);
    printf("���: %.2f\n", dMean);
    printf("�л�: %.2f\n", dVariance);
    printf("ǥ������: %.2f\n", dStddev);

    // �߰� �迭 �Է� //
    printf("�߰� �迭 ũ��: ");
    scanf_s("%d", &size_p);

    printf("�߰� �Էµ� ��: ");
    for (int i = size; i < size + size_p; i++)
    {
        scanf_s("%d", &nNum[i]);
    }

    // ���ο� ��� ��� //
    size_plus = size + size_p;
    calculateStatistics(nNum, size_plus, &nSum, &dMean, &dVariance, &dStddev);

    printf("���ο� �հ�: %d\n", nSum);
    printf("���ο� ���: %.2f\n", dMean);
    printf("���ο� �л�: %.2f\n", dVariance);
    printf("���ο� ǥ�� ����: %.2f\n", dStddev);

    return 0;
}

