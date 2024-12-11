#include <stdio.h>

// ���� ��� �Լ�//
int dot_product(int* A, int* B)  // �迭�� ����� A,B ������ �ּҸ� �����ͷ� ������//
{
    int result = 0;
    for (int i = 0; i < 3; i++)
    {
        result += A[i] * B[i];
    }
    return result; // ��� ���� ���� ��Ŵ//
}

// ���� ��� �Լ�//
void cross_product(int* A, int* B, int* C)  // �迭�� ����� A,B ������ �ּҸ� �����ͷ� ������//
{
    *(C + 0) = *(A + 1) * *(B + 2) - *(A + 2) * *(B + 1);
    *(C + 1) = *(A + 2) * *(B + 0) - *(A + 0) * *(B + 2);
    *(C + 2) = *(A + 0) * *(B + 1) - *(A + 1) * *(B + 0);
} // �迭 C �ּҸ� �����͸� ���� ���� ����Ǿ����Ƿ� ������ �ʿ� ����//

int main() //���� �Լ�//
{
    int A[3]; //3���� ���͸� ǥ���ϱ� ���� x, y, z�� �̷���� 3���� ���� ������ �� �ִ� �迭 ����
    int B[3];
    int C[3];


    printf("Input A (x, y, z): "); // A�� �Է� ����//
    scanf_s("%d %d %d", &A[0], &A[1], &A[2]);

    printf("Input B (x, y, z): "); // B�� �Է� ����//
    scanf_s("%d %d %d", &B[0], &B[1], &B[2]);


    int nDot = dot_product(A, B); // ���� �Լ� �ҷ����� //
    printf("Dot Product: %d\n", nDot);


    cross_product(A, B, C); // ���� ���//
    printf("Cross Product: (%d, %d, %d)\n", C[0], C[1], C[2]);

    return 0;
}