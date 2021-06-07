#ifndef KURSOVAYA_FUNCTION_H
#define KURSOVAYA_FUNCTION_H

#include <iostream>

using namespace std;
;
void UinCalc(double time[], double U_in[], int n, double t_start, double t_end, double t_1, double par_a, double par_b);
void UoutCalc(double time[], double U_in[], double U_out[], int n, double u1, double u2, double Uin1, double Uin2);
void Show (double  time[], double U_in[], double U_out[], int n);

#endif //KURSOVAYA_FUNCTION_H
