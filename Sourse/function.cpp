#include "../Header/function.h"

void UinCalc(double time[], double U_in[], int n, double t_start, double t_end, double t_1, double par_a, double par_b) {
    double dt;
    dt = (t_end - t_start)/(n-1);
    time[0] = t_start;

    for (int i = 1; i < n; i++) {
        time[i] = time[i - 1] + dt;
    }
    double j = t_start;

    for (int i = 0; i < n; i++) {
        if (j <= t_1) {
            U_in[i] = par_a * (j - t_start);
        } else {
            U_in[i] = par_a * (t_1 - t_start) - par_b * (j - t_1);
        }
        j += dt;
    }
}

void UoutCalc(double time[], double U_in[], double U_out[], int n, double u1, double u2, double Uin1, double Uin2) {
    for (int i = 0; i < n; i++) {
        if (U_in[i] <= Uin1) {
            U_out[i] = u1;
        } else if (U_in[i] < Uin2) {
            U_out[i] = (U_in[i]-Uin1) * (u1-u2) / (Uin2-Uin1) + u1;
        } else {
            U_out[i] = u2;
        }
    }
}

void Show (double  time[], double U_in[], double U_out[], int n) {
    cout << "|t| \t\t\t\t\t|Uin|\t\t\t\t\t|Uout|\n" << endl;

    for (int i = 0; i < n; i++) {
        printf ("%-8.4g\t\t\t\t%-8.4g\t\t\t\t%-8.4g\n", time[i], U_in[i], U_out[i]);
    }
    cout << endl;
}