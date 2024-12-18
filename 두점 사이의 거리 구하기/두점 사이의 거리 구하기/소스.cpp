#include <stdio.h>
#include <math.h>

struct point // 3���� ���� ��Ÿ���� ����ü//

{
    int coords[3]; // �迭�� ����Ͽ� x, y, z ��ǥ�� ����//
};
    

double EuclideanDistance(struct point* p1, struct point* p2) // �� �� ������ �Ÿ��� ���ϴ� �Լ�//
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

    
    printf("Input p1 (x, y, z): "); // ����ڷκ��� p1 �Է¹ޱ�//
    for (int i = 0; i < 3; i++) 
    {
        scanf_s("%d", &p1.coords[i]); // �迭�� �� ��ҿ� �Է�//
    }

    
    printf("Input p2 (x, y, z): "); // ����ڷκ��� p2 �Է¹ޱ�//
    for (int i = 0; i < 3; i++) 
    {
        scanf_s("%d", &p2.coords[i]); // �迭�� �� ��ҿ� �Է�//
    }

    
    double distance = EuclideanDistance(&p1, &p2); // �Ÿ� ��� �Լ� 

    // ��� ���//
    printf("Point1: (%d, %d, %d)\n", p1.coords[0], p1.coords[1], p1.coords[2]);
    printf("Point2: (%d, %d, %d)\n", p2.coords[0], p2.coords[1], p2.coords[2]);
    printf("Distance between the points: %.2f\n", distance);

    return 0;
}

