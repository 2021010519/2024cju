#include <stdio.h>

double trans_sin(double ag)
{
    double rad = ag * 3.141592 / 180.0; // ������ �������� ��ȯ
    double sin_value = rad; // sin(x) �ʱⰪ (ù ��)
    double term = rad; // ���Ϸ� �޼��� �� �� ����
    int sign = -1;

    // ���� ���� ���Ϸ� �޼��� �ٻ� ��� (5�� �������� ���)
    for (int i = 3; i <= 9; i += 2)
    {
        term *= rad * rad / (i * (i - 1)); // ���Ϸ� �޼� �� ���
        sin_value += sign * term;
        sign *= -1; // ���� ��ȣ ����
    }
    return sin_value;
}

double trans_cos(double ag)
{
    double rad = ag * 3.141592 / 180.0; // ������ �������� ��ȯ
    double cos_value = 1;
    double term = 1;
    int sign = -1;

    // �ڻ��� �� ����� ���� ���Ϸ� �޼� �ٻ�
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
