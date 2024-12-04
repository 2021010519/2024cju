#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dMax_Num 100.0
#define dMin_Num -100.0


void GenRandSeed()
{
    srand((unsigned int)time(NULL)); // 시간 값을 기반으로 시드 설정
}

// 주어진 범위 내에서 난수 생성 함수
double GenRandNum(double dRangeMin, double dRangeMax)
{
    double dRns = ((double)rand() / RAND_MAX) * (dRangeMax - dRangeMin) + dRangeMin;
    return dRns;
}



int main()
{
    GenRandSeed();

    double dRandNum[10]; //에러 발생으로 배열크기 [9] 에서 [10]으로 늘림//


    for (int i = 0; i < 10; i++)
    {
        dRandNum[i] = GenRandNum(dMin_Num, dMax_Num);
    }


    printf("Random numbers:\n"); //수 출력
    for (int i = 0; i < 10; i++)
    {
        printf("%.1f\n", dRandNum[i]);
    }

    for (int i = 0; i < 5; i++)  
    {
        double temp = *(dRandNum + i);  // 1,10 2,9 이런식으로 5번 교환시 서로 위치 바뀜//
        *(dRandNum + i) = *(dRandNum + 9 - i);  
        *(dRandNum + 9 - i) = temp;  
    }


    printf("Random numbers:\n"); //역순 출력//
    for (int i = 0; i < 10; i++)
    {
        printf("%.1f\n", dRandNum[i]);
    }

    return 0;
}
