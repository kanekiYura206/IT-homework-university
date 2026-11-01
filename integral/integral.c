#include <math.h>
#include <stdio.h>

double Integral (double (*f)(double), double from, double to, double step) {
    long count_steps = (long)((to - from) / step) + 1;
    double sum = 0.0;

    for(long i = 0; i < count_steps; i++) {
        double a = from + i * step;
        double b = fmin(a + step, to);
        sum += (b - a) * (f(a) + f(b)) / 2.0;
    }

    return sum;
}


int main() {
    double res;

    res = Integral(sin, 0, 3.14159/4, 0.0001);

    printf("Result: %lf\n", res);
    return 0;
}
