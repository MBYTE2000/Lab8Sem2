#include <iostream>
#include <cmath>

double func(double x) {
    return sin(x) * sin(x) - 3 * cos(x);
}

double integrateByMidpoint(double a, double b, int n) {
    double h = (b - a) / n;  // Шаг разбиения
    double integral = 0.0;

    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * h;  // Середина каждого интервала
        integral += func(x);
    }

    integral *= h;
    return integral;
}

double integrateByMidpointWithAccuracy(double a, double b, double epsilon) {
    int n = 1;  // Начальное количество разбиений
    double integral_prev = 0.0;
    double integral = integrateByMidpoint(a, b, n);

    while (std::abs(integral - integral_prev) >= epsilon) {
        n *= 2;  // Удваиваем количество разбиений
        integral_prev = integral;
        integral = integrateByMidpoint(a, b, n);
    }

    return integral;
}

int main() {
    setlocale(LC_ALL, "ru");
    double a = 1.0;  // Нижний предел интегрирования
    double b = 7.0;  // Верхний предел интегрирования
    int n = 100;     // Количество разбиений
    double epsilon = 0.0001;  // Точность

    double result1 = integrateByMidpoint(a, b, n);
    double result2 = integrateByMidpointWithAccuracy(a, b, epsilon);

    std::cout << "Результат с фиксированным количеством разбиений (n = " << n << "): " << result1 << std::endl;
    std::cout << "Результат с заданной точностью (epsilon = " << epsilon << "): " << result2 << std::endl;

    return 0;
}
