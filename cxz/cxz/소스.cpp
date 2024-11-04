#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RPS 3
#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define INITSTATUS 100
#define END_COND 20

// generating the seed number using the time clock information
void GenRandSeed()
{
    // generating the random number using the time seed
    srand((unsigned int)(time(NULL)));
    return;
}

// generating the random number
unsigned int GenRandNum(unsigned int nRange)
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}

int main(void)
{
    // assigning seed
    GenRandSeed();

    // initializing variables
    unsigned int nComrps = INITSTATUS;
    unsigned int nPlayerrps = INITSTATUS;
    //플레이어가 낸 값을 먼저 내고 컴퓨터는 랜덤값

    while (1)
    {
        printf("Input ROCK:0 PAPER:1 SCISSORS: 2:\n");
        printf("if you want to end the loop, please input 20\n");
        scanf_s("%d", &nPlayerrps);

        if (nPlayerrps == END_COND)
        {
            printf("if you want to end the loop, please input 20\n");
            break;
        }
        else if (nPlayerrps < 0 || nPlayerrps >= RPS)
        {
            // generating the random number
            printf("no, error");
            continue;

        }
        else
        {
            // generating the random number
            unsigned int nComrps = GenRandNum(RPS);
            // for debugging
            printf("Player, computer (%d,%d)\n\n", nPlayerrps, nComrps);

            switch (nPlayerrps)
            {
            case ROCK:
                if (nComrps == ROCK)
                    printf("sam sam\n");
                else if (nComrps == PAPER)
                    printf("you lose..\n");
                else
                    printf("you win!\n");
                break;
            case PAPER:
                if (nComrps == ROCK)
                    printf("you win!\n");
                else if (nComrps == PAPER)
                    printf("sam sam\n");
                else
                    printf("you lose..\n");
                break;
            case SCISSORS:
                if (nComrps == ROCK)
                    printf("you lose..\n");
                else if (nComrps == PAPER)
                    printf("you win!\n");
                else
                    printf("sam sam\n");
                break;
            default:
                printf("wow; error\n");
                break;
            }
        }
    }
    
    system("pause");
    return 0;
}

