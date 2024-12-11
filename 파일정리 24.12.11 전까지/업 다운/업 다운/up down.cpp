#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 상수
#define nMax_opport 10


// 시드 생성 함수
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}


int GenRandNumber()
{
    return rand() % 100; //랜덤 함수는 (- 출력 x), 너무 무작위로 하니 숫자를 맞추기 힘들어서 자체적으로 100까지 제한//
}


// 메인 함수 //
int main(void)
{
    // 시드 불러오기 //
    GenRandSeed();

    int nCom = GenRandNumber(); // 컴퓨터가 생성한 정답 //
    int nPlayer;
    int attempts = 0;

    printf("숫자 맞추기 게임을 시작합니다!\n");


    while (attempts < nMax_opport)
    {
        printf("숫자를 입력하세요 (남은 기회: %d): ", nMax_opport - attempts); // 기회 - 시도 횟수를 통해 몇번 기회 남았는지 표시//
        scanf_s("%d", &nPlayer);

        // 사용자가 입력한 숫자와 정답 비교//
        if (nPlayer > nCom) {
            printf("Down!\n");
        }
        else if (nPlayer < nCom) {
            printf("Up!\n");
        }
        else {
            printf("정답입니다! %d번 만에 맞추셨습니다.\n", attempts + 1);

        }

        attempts++; // 시도 횟수 //
    }

    return 0;
    // 실패한 경우 //
    printf("기회를 모두 사용했습니다. 정답은 %d였습니다.\n", nCom);
}