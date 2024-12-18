#include <stdio.h>
#include <math.h>

struct point // 3차원 점을 나타내는 구조체//

{
    int coords[3]; // 배열을 사용하여 x, y, z 좌표를 저장//
};
    

double EuclideanDistance(struct point* p1, struct point* p2) // 두 점 사이의 거리를 구하는 함수//
{
    double distance = 0.0; 
    for (int i = 0; i < 3; i++) 
    {
        distance += pow(p2->coords[i] - p1->coords[i], 2);
    }
    return sqrt(distance);
}

int main() 
{
    struct point p1, p2;

    
    printf("Input p1 (x, y, z): "); // 사용자로부터 p1 입력받기//
    for (int i = 0; i < 3; i++) 
    {
        scanf_s("%d", &p1.coords[i]); // 배열의 각 요소에 입력//
    }

    
    printf("Input p2 (x, y, z): "); // 사용자로부터 p2 입력받기//
    for (int i = 0; i < 3; i++) 
    {
        scanf_s("%d", &p2.coords[i]); // 배열의 각 요소에 입력//
    }

    
    double distance = EuclideanDistance(&p1, &p2); // 거리 계산 함수 

    // 결과 출력//
    printf("Point1: (%d, %d, %d)\n", p1.coords[0], p1.coords[1], p1.coords[2]);
    printf("Point2: (%d, %d, %d)\n", p2.coords[0], p2.coords[1], p2.coords[2]);
    printf("Distance between the points: %.2f\n", distance);

    return 0;
}

