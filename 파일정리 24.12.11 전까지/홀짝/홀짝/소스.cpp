#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenRandSeed()
{
    srand(time(NULL)); //���� �õ� ����//
}

int GenRandNumber()  //���� �Լ� 100���� ����//
{
    return rand() % 100; 
}

void CalcSortArray(int* nRandNum, int size, int* nEvenNum, int* nOddNum) // �����Լ�, ¦�� Ȧ�� �׸��� �����Լ������� ���� ���� �����ͷ� �ҷ���//
{
    for (int i = 0; i < size; i++) 
    {
        if (nRandNum[i] % 2 == 0) 
        {
            nEvenNum[i] = nRandNum[i];  // ¦���� �� ����// 
            nOddNum[i] = 0; //¦���� Ȧ�� ���� 0 ����//
        }
        else 
        {
            nOddNum[i] = nRandNum[i]; // Ȧ���� �� ����//
            nEvenNum[i] = 0; //Ȧ���� ¦�� ���� 0 ����//
        }
    }
}

int main() 
{
    GenRandSeed();

    int nRandNum[10];   
    int nOddNum[10]; //Ȧ�� �׸�//
    int nEvenNum[10];  //¦�� �׸�//

    for (int i = 0; i < 10; i++) 
    {
        nRandNum[i] = GenRandNumber();
    }

    CalcSortArray(nRandNum, 10, nEvenNum, nOddNum); //�Լ� �ҷ�����//

    printf("Random numbers:\n"); //���� �Լ� ����Ʈ //
    for (int i = 0; i < 10; i++) 
    {
        printf("%3d", nRandNum[i]);
    }
    printf("\n");

    printf("¦��:\n"); //¦�� �Լ� ����Ʈ//
    for (int i = 0; i < 10; i++) 
    {
        printf("%3d", nEvenNum[i]);
    }

    printf("\n");

    printf("Ȧ��:\n"); // Ȧ�� �Լ� ����Ʈ//
    for (int i = 0; i < 10; ++i) 
    {
        printf("%3d", nOddNum[i]);
    }

    return 0;
}
