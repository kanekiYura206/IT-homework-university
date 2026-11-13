#include <stdio.h>

int main() {
    double h, w, d;
    double rho_dsp, rho_dvp, rho_wood;
    double mass;
    int n;

    printf("h, w, d (meters): ");
    scanf("%lf %lf %lf", &h, &w, &d);

    printf("denses (dsp, dvp, wood) (kg/m^3): ");
    scanf("%lf %lf %lf", &rho_dsp, &rho_dvp, &rho_wood);

    n = (int)(h / 0.4) - 1;

    double m_back = h * w * 0.005 * rho_dvp;

    double m_sides = 2 * h * d * 0.015 * rho_dsp;

    double m_covers = 2 * w * d * 0.015 * rho_dsp;

    double m_doors = h * w * 0.01 * rho_wood;

    double m_shelves = n * w * d * 0.015 * rho_dsp;

    mass = m_back + m_sides + m_covers
           + m_doors + m_shelves;

    printf("mass: %.2f kg\n", mass);

    return 0;
}
