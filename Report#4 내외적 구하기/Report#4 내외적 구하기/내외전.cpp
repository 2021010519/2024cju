#include <stdio.h>

// 내적 계산 함수//
int dot_product(int* A, int* B)  // 배열로 선언된 A,B 데이터 주소를 포인터로 가져옴//
{
    int result = 0;
    for (int i = 0; i < 3; i++)
    {
        result += A[i] * B[i];
    }
    return result; // 결과 값을 리턴 시킴//
}

// 외적 계산 함수//
void cross_product(int* A, int* B, int* C)  // 배열로 선언된 A,B 데이터 주소를 포인터로 가져옴//
{
    *(C + 0) = *(A + 1) * *(B + 2) - *(A + 2) * *(B + 1);
    *(C + 1) = *(A + 2) * *(B + 0) - *(A + 0) * *(B + 2);
    *(C + 2) = *(A + 0) * *(B + 1) - *(A + 1) * *(B + 0);
} // 배열 C 주소를 포인터를 통해 값이 저장되었으므로 리턴이 필요 없음//

int main() //메인 함수//
{
    int A[3]; //3차원 백터를 표현하기 위해 x, y, z로 이루어진 3개의 값을 저장할 수 있는 배열 선언
    int B[3];
    int C[3];


    printf("Input A (x, y, z): "); // A값 입력 받음//
    scanf_s("%d %d %d", &A[0], &A[1], &A[2]);

    printf("Input B (x, y, z): "); // B값 입력 받음//
    scanf_s("%d %d %d", &B[0], &B[1], &B[2]);


    int nDot = dot_product(A, B); // 내전 함수 불러오기 //
    printf("Dot Product: %d\n", nDot);


    cross_product(A, B, C); // 외적 계산//
    printf("Cross Product: (%d, %d, %d)\n", C[0], C[1], C[2]);

    return 0;
}