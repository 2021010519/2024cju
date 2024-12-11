#include <stdio.h>

double trans_sin(double ag)
{
    double rad = ag * 3.141592 / 180.0; // 각도를 라디안으로 변환
    double sin_value = rad; // sin(x) 초기값 (첫 항)
    double term = rad; // 테일러 급수의 각 항 계산용
    int sign = -1;

    // 사인 값을 테일러 급수로 근사 계산 (5항 정도까지 사용)
    for (int i = 3; i <= 9; i += 2)
    {
        term *= rad * rad / (i * (i - 1)); // 테일러 급수 항 계산
        sin_value += sign * term;
        sign *= -1; // 항의 부호 변경
    }
    return sin_value;
}

double trans_cos(double ag)
{
    double rad = ag * 3.141592 / 180.0; // 각도를 라디안으로 변환
    double cos_value = 1;
    double term = 1;
    int sign = -1;

    // 코사인 값 계산을 위한 테일러 급수 근사
    for (int i = 2; i <= 10; i += 2)
    {
        term *= rad * rad / (i * (i - 1));
        cos_value += sign * term;
        sign *= -1;
    }
    return cos_value;
}

int main()
{
    double ag;
    double sin_result, cos_result;

    printf("Input angle (0~180): ");
    scanf_s("%lf", &ag);

    sin_result = trans_sin(ag);
    cos_result = trans_cos(ag);

    printf("sin: %lf\n", sin_result);
    printf("cos: %lf\n", cos_result);

    return 0;
}
