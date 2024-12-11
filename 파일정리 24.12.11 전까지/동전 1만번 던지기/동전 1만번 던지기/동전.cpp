#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define INITSTATUS 100
#define coin_Fwd_Bwd 3
#define coin_Fwd_Status 1
#define coin_Bwd_Status 2


#define END_COND 999
#define NUM_FLIP 10000



// generating the seed number using the time clock information
void GenRandSeed()
{
    // assigning seed

    // generating the random number using the time seed
    srand((unsigned int)(time(NULL)));
    return;
}

// generating the random number
unsigned int GenRandcoin(unsigned int nRange)
{
    unsigned int nRes = 0;
    while (1)
    {
        nRes = ((unsigned int)(rand()) % (nRange));
        if ((nRes == coin_Fwd_Status || nRes == coin_Bwd_Status))
            break;

    }

    return nRes;
}


// main function loop
int main(void)
{
    GenRandSeed();

    // initializing variables
    int nNumsumfwdflip = 0;
    int nNumsumBwdflip = 0;
    double FwddVar = 0.0;
    double BwddVar = 0.0;
    double dstdevFwddVar = 0.0;
    double dstdevBwddVar = 0.0;


    for (unsigned int i = 0; i < NUM_FLIP; i++)

    {
        // generating the random number, fwd: 0 Bwd:1
        unsigned int nStatusFlipcoin = GenRandcoin(coin_Fwd_Bwd);

        switch (nStatusFlipcoin)
        {

        case coin_Fwd_Status:
        {
            nNumsumfwdflip++;
            break;
        }
        case coin_Bwd_Status:
        {
            nNumsumBwdflip++;
            break;
        }
        default:
        {
            printf("error");
            break;
        }

        }


    }




    printf("Sum Result: (FAC, BAC): (%d, %d)\n", nNumsumfwdflip, nNumsumBwdflip);





    return 0;
}