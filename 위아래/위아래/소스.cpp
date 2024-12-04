#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dMax_Num 100.0
#define dMin_Num -100.0


void GenRandSeed()
{
    srand((unsigned int)time(NULL)); // 시간 값을 기반으로 시드 설정
}


double GenRandNum(double dRangeMin, double dRangeMax)
{
    double dRns = ((double)rand() / RAND_MAX) * (dRangeMax - dRangeMin) + dRangeMin;
    return dRns;
}

void CalcSortArray(double* dRandNum, int size) // 오름차순 함수//
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - 1 - i; j++) // i를 모든 함수와 비교해 위치 선정//
        {
            if (*(dRandNum + j) < *(dRandNum + j + 1)) 
            {
                double temp = *(dRandNum + j);
                *(dRandNum + j) = *(dRandNum + j + 1);
                *(dRandNum + j + 1) = temp;
            }
        }
    }
}


void UnCalcSortArray(double* dRandNum, int size) // 내림차순 정렬 함수
{
    for (int i = 0; i < size - 1; i++) // i를 모든 함수와 비교해 위치 선정//
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (*(dRandNum + j + 1) < *(dRandNum + j))
            {
                double temp = *(dRandNum + j + 1);
                *(dRandNum + j + 1) = *(dRandNum + j);
                *(dRandNum + j) = temp;
            }
        }
    }
}


int main()
{
    GenRandSeed(); 

    double dRandNum[10]; //에러 발생으로 배열크기 [9] 에서 [10]으로 늘림//
    char ud;
  
    for (int i = 0; i < 10; i++) 
    {
        dRandNum[i] = GenRandNum(dMin_Num, dMax_Num);
    }
    printf("up or down? (u or d?): ");
    scanf_s(" %c", &ud, (unsigned int)sizeof(ud));

    if (ud == 'u')
    {
        CalcSortArray(dRandNum, 10);
    }
    else
    {
        UnCalcSortArray(dRandNum, 10);
    }
    

    
    printf("Random numbers:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.1f\n", dRandNum[i]);
    }

    return 0;
}
