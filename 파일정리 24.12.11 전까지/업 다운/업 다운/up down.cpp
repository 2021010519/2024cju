#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���
#define nMax_opport 10


// �õ� ���� �Լ�
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}


int GenRandNumber()
{
    return rand() % 100; //���� �Լ��� (- ��� x), �ʹ� �������� �ϴ� ���ڸ� ���߱� ���� ��ü������ 100���� ����//
}


// ���� �Լ� //
int main(void)
{
    // �õ� �ҷ����� //
    GenRandSeed();

    int nCom = GenRandNumber(); // ��ǻ�Ͱ� ������ ���� //
    int nPlayer;
    int attempts = 0;

    printf("���� ���߱� ������ �����մϴ�!\n");


    while (attempts < nMax_opport)
    {
        printf("���ڸ� �Է��ϼ��� (���� ��ȸ: %d): ", nMax_opport - attempts); // ��ȸ - �õ� Ƚ���� ���� ��� ��ȸ ���Ҵ��� ǥ��//
        scanf_s("%d", &nPlayer);

        // ����ڰ� �Է��� ���ڿ� ���� ��//
        if (nPlayer > nCom) {
            printf("Down!\n");
        }
        else if (nPlayer < nCom) {
            printf("Up!\n");
        }
        else {
            printf("�����Դϴ�! %d�� ���� ���߼̽��ϴ�.\n", attempts + 1);

        }

        attempts++; // �õ� Ƚ�� //
    }

    return 0;
    // ������ ��� //
    printf("��ȸ�� ��� ����߽��ϴ�. ������ %d�����ϴ�.\n", nCom);
}