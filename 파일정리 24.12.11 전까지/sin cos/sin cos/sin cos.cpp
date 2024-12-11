#include <stdio.h>

double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

double sine(double x) {
    double sin_x = 0.0;
    for (int n = 0; n < 10; n++) { // 10�ױ����� ���
        int sign = (n % 2 == 0) ? 1 : -1; // ��ȣ �����
        sin_x += sign * power(x, 2 * n + 1) / factorial(2 * n + 1);
    }
    return sin_x;
}

double cosine(double x) {
    double cos_x = 0.0;
    for (int n = 0; n < 10; n++) { // 10�ױ����� ���
        int sign = (n % 2 == 0) ? 1 : -1; // ��ȣ �����
        cos_x += sign * power(x, 2 * n) / factorial(2 * n);
    }
    return cos_x;
}

int main() {
    double ag;
    const double PI = 3.141592;

    printf("Input angle (0~180): ");
    scanf("%lf", &ag);

    // ������ �������� ��ȯ
    double rad = ag * (PI / 180.0);

    // �ڻ��ΰ� ���� ���
    double result_cos = cosine(rad);
    double result_sin = sine(rad);

    printf("cos: %lf sin: %lf\n", result_cos, result_sin);
    return 0;
}






