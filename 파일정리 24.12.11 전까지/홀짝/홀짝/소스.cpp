#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenRandSeed()
{
    srand(time(NULL)); //랜덤 시드 생성//
}

int GenRandNumber()  //랜덤 함수 100까지 제한//
{
    return rand() % 100; 
}

void CalcSortArray(int* nRandNum, int size, int* nEvenNum, int* nOddNum) // 랜덤함수, 짝수 홀수 그릇을 메인함수에서도 쓰기 위해 포인터로 불러옴//
{
    for (int i = 0; i < size; i++) 
    {
        if (nRandNum[i] % 2 == 0) 
        {
            nEvenNum[i] = nRandNum[i];  // 짝수면 값 저장// 
            nOddNum[i] = 0; //짝수면 홀수 값에 0 저장//
        }
        else 
        {
            nOddNum[i] = nRandNum[i]; // 홀수면 값 저장//
            nEvenNum[i] = 0; //홀수면 짝수 값에 0 저장//
        }
    }
}

int main() 
{
    GenRandSeed();

    int nRandNum[10];   
    int nOddNum[10]; //홀수 그릇//
    int nEvenNum[10];  //짝수 그릇//

    for (int i = 0; i < 10; i++) 
    {
        nRandNum[i] = GenRandNumber();
    }

    CalcSortArray(nRandNum, 10, nEvenNum, nOddNum); //함수 불러오기//

    printf("Random numbers:\n"); //랜덤 함수 프린트 //
    for (int i = 0; i < 10; i++) 
    {
        printf("%3d", nRandNum[i]);
    }
    printf("\n");

    printf("짝수:\n"); //짝수 함수 프린트//
    for (int i = 0; i < 10; i++) 
    {
        printf("%3d", nEvenNum[i]);
    }

    printf("\n");

    printf("홀수:\n"); // 홀수 함수 프린트//
    for (int i = 0; i < 10; ++i) 
    {
        printf("%3d", nOddNum[i]);
    }

    return 0;
}
