#include <iostream>
#include "../Header/function.h"

using namespace std;
int N, choose;
double *t, *Uin, *Uout;

int main() {
    ReadIntro();
    while (choose != 4) {
            cout << "Выберите действие:" << endl;
            cout << "1. Расчет времени, входного и выходного напряжения" << endl;
            cout << "2. Расчет параметра" << endl;
            cout << "3. Запись в файл" << endl;
            cout << "4. Завершить работу" << endl;
            cin >> choose;

            switch (choose) {
                case 1: {
                    cout << "Введите кол-во точек: ";
                    cin >> N;
                    cin.ignore();
                    t = new double[N];
                    Uin = new double[N];
                    Uout = new double[N];
                    UinCalc(t, Uin, N);
                    UoutCalc(t, Uin, Uout, N);
                    Show(t, Uin, Uout, N);
                }
                    break;
                case 2: {
                    double err = 1, eps = 0.01, par = 1000000000, par1;
                    int N0 = N;
                    cout << "Нахождение момента времени, при котором Uin достигает максимума:" << endl;
                    while (err > eps) {
                        t = new double [N0];
                        Uin = new double[N0];
                        Uout = new double[N0];

                        UinCalc(t, Uin, N0);
                        UinCalc(t, Uin, N0);
                        UoutCalc(t, Uin, Uout, N0);
                        par1 = ParamCalc(t, Uin, N0);
                        err = abs((par-par1)/par1);
                        cout << "N = " << N0 << " момент времени = " << par1 << " погрешность = " << err << endl;
                        par = par1;
                        N0 *= 2;

                        delete [] t; delete[] Uin; delete [] Uout;
                        t = nullptr; Uin = nullptr; Uout = nullptr;
                    }
                    cout << endl;
                }
                    break;
                case 3: {
                    t = new double[N];
                    Uin = new double[N];
                    Uout = new double[N];
                    UinCalc(t, Uin, N);
                    UoutCalc(t, Uin, Uout, N);

                    SaveToFile(t, N, "time");
                    SaveToFile(Uin, N, "Uin");
                    SaveToFile(Uout, N, "Uout");
                    cout << "Запись в файл прошла успешно!" << endl;
                }
                    break;
                default: {

                }
            }
        }
    delete [] t; delete[] Uin; delete [] Uout;
    t = nullptr; Uin = nullptr; Uout = nullptr;

    return 0;
}


