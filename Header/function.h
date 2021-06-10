#ifndef KURSOVAYA_FUNCTION_H
#define KURSOVAYA_FUNCTION_H

#include <iostream>
#include <fstream>

using namespace std;
;
void UinCalc(double time[], double U_in[], int n);
void UoutCalc(double time[], double U_in[], double U_out[], int n);
void Show (double  time[], double U_in[], double U_out[], int n);
double ParamCalc(double  time[], double U_in[], int n);
void SaveToFile(double  array[], int n, string fileName);
void ReadIntro();

#endif //KURSOVAYA_FUNCTION_H
